#include <QPiPC>
#include <QCoreApplication>

int main(int argc, char **argv)
{
    QCoreApplication app{argc, argv};

    qDebug("a");
    wiringPiSetup();
    qDebug("b");

    return app.exec();
}
