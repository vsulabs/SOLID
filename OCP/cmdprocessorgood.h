#ifndef CMDPROCESSORGOOD_H
#define CMDPROCESSORGOOD_H

#include "icmdprocessor.h"

#include <QString>
#include <QStringList>
#include <QMap>
#include <functional>

typedef std::function<QString (const QString& cmd)> CmdHandler;

class CmdProcessorGood : public ICmdProcessor
{
public:
    ~CmdProcessorGood() override {}
    void addCommand(const QString& cmd, const CmdHandler& handler);
    QStringList process(const QString& text) override;

private:
    QMap<QString, CmdHandler> handlers;
};

#endif // CMDPROCESSORGOOD_H
