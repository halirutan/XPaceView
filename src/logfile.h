#ifndef LOGFILE_H
#define LOGFILE_H

#include <QUrl>

// Used for the data in one line of a logfile
struct trans_t {
    unsigned int frame;
    unsigned int time;
    float x;
    float y;
    float z;
    float qr;
    float qi;
    float qj;
    float qk;
};

class LogFile
{
public:
    LogFile(QUrl file);

    /**
     * @brief parse Attempts to parse the numeric values in the logfile
     * @return true if successful
     */
    bool parse();

    /**
     * @brief calculateAbsolutePositions transforms the relative logfile
     * transformations into absolute positions and rotations.
     */
    void calculateAbsolutePositions();

private:
    QUrl mFile;
    struct trans_t mInitialPose;
    std::list<struct trans_t> mData;
};

#endif // LOGFILE_H
