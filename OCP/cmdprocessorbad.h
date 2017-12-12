#ifndef CMD_PROCESSOR_H
#define CMD_PROCESSOR_H

#include <QStringList>

class CmdProcessorBad
{
public:
    CmdProcessorBad();
    QStringList process(const QString& cmd);
};

#endif // CMD_PROCESSOR_H
