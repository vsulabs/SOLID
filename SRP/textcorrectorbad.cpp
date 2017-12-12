#include "textcorrectorbad.h"
#include <fstream>

#include <QDebug>

TextCorrectorBad::TextCorrectorBad()
    : text{}
    , result{}
{
}

TextCorrectorBad::TextCorrectorBad(const QString& text)
    : text{text}
    , result{}
{
}

void TextCorrectorBad::correct() const
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

const QString& TextCorrectorBad::getCorrected()
{
    if (result.isEmpty())
        correct();

    return result;
}

void TextCorrectorBad::setText(const QString& text)
{
    result.clear();
    this->text = text;
}

int TextCorrectorBad::wordCount() const
{
    if (result.isEmpty())
        correct();

    return result.count(' ') + 1;
}

void TextCorrectorBad::saveToFile(const QString& path)
{
    std::string p = path.toStdString();
    std::ofstream f(p);
    f << text.toStdString();
    f.close();
}

void TextCorrectorBad::loadFromFile(const QString& path)
{
    std::string p = path.toStdString();
    std::string in;
    std::ifstream f(p);
    f >> in;
    text = QString::fromUtf8(in.c_str());
}
