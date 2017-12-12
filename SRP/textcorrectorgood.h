#ifndef TESTCORRECTOR2_H
#define TESTCORRECTOR2_H

#include <QString>

class TextCorrectorGood
{
public:
    TextCorrectorGood();
    void setText(const QString& text);
    QString getCorrected();

private:
    void correct() const;

    QString text;
    mutable QString result;
};

#endif // TESTCORRECTOR2_H
