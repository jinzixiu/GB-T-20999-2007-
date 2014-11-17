#ifndef CPUBSUB_H
#define CPUBSUB_H
#include "serialport.h"
QT_BEGIN_NAMESPACE_SERIALPORT
class SerialPort;
QT_END_NAMESPACE_SERIALPORT

QT_USE_NAMESPACE_SERIALPORT
class CPubSub
{
public:
    CPubSub();
    virtual ~CPubSub();

    bool OpenCom(const QString name,int index);
    int GetDataLen();
    unsigned int ReadCom(char *pBuff,int nCount);
    bool WriteCom(char *pBuff, int nCount);
    bool CloseCom();
    bool isopen();
private:
    SerialPort *com;
};

#endif // CPUBSUB_H
