#include <QDebug>
#include <QList>
#include <QUrl>
#include <iostream>

#include "backend.h"



Backend::Backend(QObject *parent) : QObject(parent)
{

}

void Backend::addFiles(QList<QUrl> files)
{
    qDebug() << "Files Added";
    Q_FOREACH(QUrl item, files) {
        std::cout << "item" << std::endl;
    }

}


void Backend::closeFiles()
{
    qDebug() << "Files Closed";
}
