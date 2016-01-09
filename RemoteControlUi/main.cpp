#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <sumui.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    SumUi sumUi;
    engine.rootContext()->setContextProperty("sum", &sumUi);

    //std::cout << "Hi" << Sum::sum(1, 2) << std::endl;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
