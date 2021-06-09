#include "QPiPC"
#include "QPiPC_p.h"

#include <QSharedPointer>

QSharedPointer<QPiPC> pi;

QPiPC::QPiPC(QObject *parent)
    : QObject{parent}
{
    connect(&m_gpio, &GpioPins::changed, this, &QPiPC::gpioChanged);

    static auto self = this;
    qmlRegisterSingletonType<QPiPC>("QPiPC", 1, 0, "QPiPC", [](QQmlEngine *, QJSEngine *) -> QObject * {
        return self;
    });

    m_view.setSource(QUrl{"qrc:/PiPCControlPage.qml"});
    m_view.show();
}

void GpioPins::setPin(int pin, int value)
{
    m_pinValues[pin] = value;
    emit changed();
}

QHash<int, QByteArray> GpioPins::roleNames() const
{
        return {{Pin, "pin"}, {Value, "value"}};
}

QVariant GpioPins::data(const QModelIndex &index, int role) const
{
        if (!index.isValid() || index.row() >= (int)m_pinValues.size() || index.row() < 0)
                return {};

        switch (role) {
        case Pin:
                return m_pinValues.keys()[index.row()];
        case Value:
                return m_pinValues[m_pinValues.keys()[index.row()]];
        default:
                return {};
        }
}


int wiringPiSetup()
{
    auto pc = new QPiPC;
    pi.reset(pc);

    return 0;
}
