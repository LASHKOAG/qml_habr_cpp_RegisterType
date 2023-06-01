#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <testclass.h>
#include <myclass.h>
#include <QQmlContext>
#include "secondclass.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<TestClass>("ModuleName", 1, 0, "TypeName");
    qmlRegisterType<SecondClass>("ModuleNameSecond", 1, 0, "SecondClass");

    MyClass myClass;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("_myClass", &myClass);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);




    return app.exec();
}
