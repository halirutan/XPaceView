#include "logfile.h"

#include <QFile>
#include <QDebug>
#include <QString>
#include <cstdio>

#include "vectormath.h"

LogFile::LogFile(QUrl file): mFile(file)
{

}

/**
 * @brief LogFile::parse Parses a xpace_XXX.log file and extracts motion values
 * @return true if parsing was successful
 *
 * This is dead-simple because there are usually about 50k lines in the logfiles
 * and thorough parsing and checking each line would take too long. Think
 * of 1ms per line and you're already up to a minute just reading the values.
 */
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
                int numItems;
                switch (buffer[0]) {
                // Initial Pose starts with a @ in the logfile
                case '@':
                    numItems = sscanf(buffer, "@%f %f %f ( %f %f %f ) %f",
                        &(p.x), &(p.y), &(p.z), &(p.qi), &(p.qj), &(p.qk), &(p.qr));
                    // Check if we got the right number of values
                    if(numItems != 7) {
                        return false;
                    }
                    p.time = 0;
                    p.frame = 0;
                    mInitialPose = p;
                    break;
                // Comment
                case '#':
                    break;
                // Some error thingie we're going to ignore
                case '[':
                    break;
                // All other lines in the logfile should be motion measures
                // They start with a number, but we don't check for that.
                // We ruthlessly try to match the values.
                default:
                    numItems = sscanf(buffer, "%d %d %f %f %f ( %f %f %f ) %f",
                        &(p.frame), &(p.time), &(p.x), &(p.y), &(p.z), &(p.qi),
                        &(p.qj), &(p.qk), &(p.qr));
                    // Check if we got the right number of values
                    if(numItems != 9) {
                        return false;
                    }
                    mData.push_back(p);
                    break;
                }

            }
        }
        return true;
    }
    return false;
}

/**
 * @brief LogFile::calculateAbsolutePositions Calculate absolute positions from
 * the relative motion tracking transformations.
 *
 * Note: The transformation is done in-place and it changes mData. Don't apply it
 * more than once.
 */
void LogFile::calculateAbsolutePositions()
{
    Quat q0{mInitialPose.qr, mInitialPose.qi, mInitialPose.qj, mInitialPose.qk};
    Vec3d t0{mInitialPose.x, mInitialPose.y, mInitialPose.z};
    for(auto e: mData) {
        Quat qi{e.qr, e.qi, e.qj, e.qr};
        Vec3d ti{e.x, e.y, e.z};
        Quat q = q0.mult(qi);
        Vec3d t = qi.rotate(t0).add(ti);
        e.x = t.x;
        e.y = t.y;
        e.z = t.z;
        e.qr = q.qr;
        e.qi = q.qi;
        e.qj = q.qj;
        e.qk = q.qk;
    }
    qDebug() << "Finished transforming";
}
