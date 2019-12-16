#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QList>
#include <QUrl>

class XPaceView : public QObject
{
    Q_OBJECT

public:
    explicit XPaceView(QObject *parent = nullptr);
    Q_INVOKABLE void addFiles(QList<QUrl>);
    Q_INVOKABLE void closeFiles();

signals:
    void logLoaded();
    void logClosed();
};

#endif // BACKEND_H
