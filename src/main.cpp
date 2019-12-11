#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QStringList fonts = QStringList{} << ":/fonts/MaterialIcons.ttf";


    for (const auto& font : fonts) {
      if (QFontDatabase::addApplicationFont(font) == -1) {
          qWarning() << "Failed to load font: " << font;
      }
    }

    const QUrl url(QStringLiteral("qrc:/views/MainView.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return QGuiApplication::exec();
}
