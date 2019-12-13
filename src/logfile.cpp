#include "logfile.h"

#include <QFile>
#include <QString>
#include <cstdio>

LogFile::LogFile(QUrl file): mFile(file)
{

}

bool LogFile::parse()
{
    if(!mFile.isLocalFile()) {
        return false;
    }
    QString fileName = mFile.toLocalFile();
    QFile file(fileName);
    if (!file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    char buffer[2048];
    QString magic("# libXPACE log file");
    qint64 length = file.readLine(buffer, sizeof(buffer));
    if(length > 0 || magic.compare(QString(buffer), Qt::CaseSensitive) == 0) {
        mData.clear();
        while (!file.atEnd()) {
            qint64 length = file.readLine(buffer, sizeof(buffer));
            if(length > 0) {
                struct trans_t p;
                switch (buffer[0]) {
                case '@':
                    sscanf(buffer, "@%f %f %f ( %f %f %f ) %f", &(p.x), &(p.y), &(p.z), &(p.qi), &(p.qj), &(p.qk), &(p.qr));
                    p.time = -1;
                    p.frame = -1;
                    mInitialPose = p;
                    break;
                case '#':
                    break;
                case '[':
                    break;
                default:
                    sscanf(buffer, "%d %d %f %f %f ( %f %f %f ) %f", &(p.frame), &(p.time), &(p.x), &(p.y), &(p.z), &(p.qi), &(p.qj), &(p.qk), &(p.qr));
                    mData.push_back(p);
                    break;
                }

            }
        }
        return true;
    }
    return false;
}

void LogFile::calculateAbsolutePositions()
{

}
