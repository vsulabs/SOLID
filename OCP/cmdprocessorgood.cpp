#include "cmdprocessorgood.h"

void CmdProcessorGood::addCommand(const QString& cmd, const CmdHandler& handler)
{
    handlers[cmd] = handler;
}

QStringList CmdProcessorGood::process(const QString& text)
{
    QStringList result;
    for (const QString& line : text.split('\n')) {
        for (auto it = handlers.cbegin(); it != handlers.cend(); ++it) {
            const QString& cmd = it.key();
            if (line.startsWith(cmd)) {
                QString res = handlers[cmd](line);
                result.append(res);
            }
        }
    }

    return result;
}
