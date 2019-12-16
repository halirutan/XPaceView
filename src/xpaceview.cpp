#include <QDebug>
#include <QList>
#include <QUrl>
#include <iostream>

#include "xpaceview.h"
#include "logfile.h"


XPaceView::XPaceView(QObject *parent) : QObject(parent)
{

}

void XPaceView::addFiles(QList<QUrl> files)
{
    qDebug() << "Files Added";
    Q_FOREACH(QUrl url, files) {
        LogFile l(url);
        bool result = l.parse();
        qDebug() << "Parsing done: " << result << endl;
        l.calculateAbsolutePositions();
    }
    emit logLoaded();

}


void XPaceView::closeFiles()
{
    qDebug() << "Files Closed";
}
