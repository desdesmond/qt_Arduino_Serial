#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "serialcom.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    serialCom sC;
    QQmlContext *context = new QQmlContext(engine.rootContext());
    context -> setContextProperty("serialCom", &sC);

    serialCom(); //start serial connection

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
