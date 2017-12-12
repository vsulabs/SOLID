#ifndef CMDPROCESSORGOOD_H
#define CMDPROCESSORGOOD_H

#include <QString>
#include <QStringList>
#include <QMap>
#include <functional>

typedef std::function<QString (const QString& cmd)> CmdHandler;

class CmdProcessorGood
{
public:
    CmdProcessorGood();
    void addCommand(const QString& cmd, const CmdHandler& handler);
    QStringList process(const QString& text);

private:
    QMap<QString, CmdHandler> handlers;
};

#endif // CMDPROCESSORGOOD_H
