#include "textcorrectorgood.h"

TextCorrectorGood::TextCorrectorGood()
{

}

void TextCorrectorGood::setText(const QString& text)
{
    result.clear();
    this->text = text;
}

QString TextCorrectorGood::getCorrected()
{
    if (result.isEmpty())
        correct();

    return result;
}

void TextCorrectorGood::correct() const
{
    if (!result.isEmpty())
        return;

    QString text = this->text.trimmed();
    for (int i = 0; i < text.length(); i++) {
        while (i < text.length() && text[i] == ' ' && text[i + 1] == ' ') {
            i++;
        }

        result.append(text[i]);
    }

    if (result[result.length() - 1] != '.') {
        result.append('.');
    }

    result[0] = result[0].toUpper();

    int dotPos = result.indexOf('.');
    while (dotPos != -1) {
        int pos = dotPos + 2;
        if (pos >= result.length())
            break;

        result[pos] = result[pos].toUpper();
        dotPos = result.indexOf('.', dotPos + 1);
    }
}
