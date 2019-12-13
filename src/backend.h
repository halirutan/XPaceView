#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QList>
#include <QUrl>

class Backend : public QObject
{
    Q_OBJECT

public:
    explicit Backend(QObject *parent = nullptr);
    Q_INVOKABLE void addFiles(QList<QUrl>);
    Q_INVOKABLE void closeFiles();

signals:

public slots:


};

#endif // BACKEND_H
