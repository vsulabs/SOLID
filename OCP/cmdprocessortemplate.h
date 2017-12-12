#ifndef CMDPROCESSORTEMPLATE_H
#define CMDPROCESSORTEMPLATE_H

#include "icmdprocessor.h"
#include <functional>
#include <QString>

typedef std::function<QString (const QString& cmd)> CmdHandler;

class CmdProcessorTemplate : public ICmdProcessor
{
public:
    QStringList process(const QString& text) override;

protected:
    virtual QString processCmd(const QString& cmd, const QString& input) = 0;
    virtual QStringList avaliableCommands() const = 0;
};

class CmdProcessorSimple : public CmdProcessorTemplate
{
public:
    ~CmdProcessorSimple() override {}

protected:
    QString processCmd(const QString& cmd, const QString& input) override;
    QStringList avaliableCommands() const override;
};

#endif // CMDPROCESSORTEMPLATE_H
