#ifndef _TEXT_CORRECTOR_H_
#define _TEXT_CORRECTOR_H_

#include <QString>

class TextCorrectorBad
{
public:
    TextCorrectorBad();
    TextCorrectorBad(const QString& text);

    const QString& getCorrected();
    void setText(const QString& text);

    int wordCount() const;

    void saveToFile(const QString& path);
    void loadFromFile(const QString& path);

private:
    void correct() const;

    QString text;
    mutable QString result;
};

#endif // _TEXT_CORRECTOR_H_
