#include "cmdprocessortemplate.h"

#include <QStringList>
#include <sstream>

QStringList CmdProcessorTemplate::process(const QString &text)
{
    QStringList result;
    for (const QString& line : text.split('\n')) {
        const QString cmd = line.split(' ').at(0);
        if (avaliableCommands().contains(cmd)) {
            QString res = processCmd(cmd, line);
            result.append(res);
        }
    }

    return result;
}

QString CmdProcessorSimple::processCmd(const QString &cmd, const QString &input)
{
    std::string s = input.toStdString();
    if (cmd == "sum") {
        int a, b;
        sscanf(s.c_str(), "%*s %d %d", &a, &b);
        return QString::number(a + b);
    } else if (cmd == "take") {
        int a;
        sscanf(s.c_str(), "%*s %d", &a);
        return QString::number(a);
    }

    return QString{};
}

QStringList CmdProcessorSimple::avaliableCommands() const
{
    return { "sum", "take" };
}
