#include <QDebug>
#include <QList>
#include <QUrl>
#include <iostream>

#include "backend.h"
#include "logfile.h"


Backend::Backend(QObject *parent) : QObject(parent)
{

}

void Backend::addFiles(QList<QUrl> files)
{
    qDebug() << "Files Added";
    Q_FOREACH(QUrl url, files) {
        LogFile l(url);
        bool result = l.parse();
        std::cout << "Parsing result: " << result << std::endl;
    }

}


void Backend::closeFiles()
{
    qDebug() << "Files Closed";
}
