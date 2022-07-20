#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qtwebengineglobal.h>
int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("QtExamples");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
    qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "--ignore-gpu-blacklist");
    qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "–enable-gpu-rasterization");
    qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "–enable-native-gpu-memory-buffers");
    qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "–num-raster-threads=4");
    QtWebEngine::initialize();

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
