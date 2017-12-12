#ifndef ICMDPROCESSOR_H
#define ICMDPROCESSOR_H

#include <QString>

class ICmdProcessor
{
public:
    virtual ~ICmdProcessor() {};
    virtual QStringList process(const QString& text) = 0;
};

#endif // ICMDPROCESSOR_H
