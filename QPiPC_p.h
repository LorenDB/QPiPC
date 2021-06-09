#ifndef QPIPC_P_H
#define QPIPC_P_H

#include "QPiPC_global.h"

#include <QObject>
#include <QQuickView>
#include <QAbstractListModel>

class GpioPins : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles
    {
        Pin,
        Value,
    };

    Q_INVOKABLE void setPin(int pin, int value);

    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const { return m_pinValues.count(); }

signals:
    void changed();

private:
    QMap<int, int> m_pinValues;
};

class QPiPC : public QObject
{
    Q_OBJECT

    Q_PROPERTY(GpioPins * gpio READ gpio NOTIFY gpioChanged)

public:
    QPiPC(QObject *parent = nullptr);

    GpioPins *gpio() { return &m_gpio; }

signals:
    void pinValuesChanged();
    void gpioChanged();

private:
    QQuickView m_view;
    GpioPins m_gpio;
};

#endif // QPIPC_P_H
