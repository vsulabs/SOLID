#include "cmdprocessorbad.h"

#include <cstdio>

CmdProcessorBad::CmdProcessorBad()
{

}

QStringList CmdProcessorBad::process(const QString& text)
{
    QStringList result;
    for (const QString& line : text.split('\n')) {
        const std::string sline = line.toStdString();
        if (line.startsWith("sum")) {
            int a, b;
            sscanf(sline.c_str(), "%*s %d %d", &a, &b);
            result.append(QString::number(a + b));
        } else if (line.startsWith("take")) {
            int a;
            sscanf(sline.c_str(), "%*s %d", &a);
            result.append(QString::number(a));
        }
    }

    return result;
}
