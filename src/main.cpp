#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QFontDatabase>
#include <QDebug>
#include <QQmlContext>
#include <QFile>

#include "xpacelogview.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    qmlRegisterType<XPaceView>();

    QGuiApplication app(argc, argv);
    app.setOrganizationName("Neurophysics");
    app.setOrganizationDomain("cbs.mpg.de");
    QQmlApplicationEngine engine;

    QStringList fonts = QStringList{} << ":/fonts/MaterialIcons.ttf";

    for (const auto& font : fonts) {
      if (QFontDatabase::addApplicationFont(font) == -1) {
          qWarning() << "Failed to load font: " << font;
      }
    }

    const QUrl url(QStringLiteral("qrc:/views/mainView.qml"));
    QQmlComponent compontent(&engine, url);

    for(QQmlError err: compontent.errors()) {
        qDebug() << err;
    }
    compontent.create();
    return QGuiApplication::exec();
}
