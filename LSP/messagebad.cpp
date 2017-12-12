#include "messagebad.h"

#include <exception>

MessageBad::MessageBad()
{
}

MessageBad::MessageBad(const QString& author, const QString& text)
    : author{author}
    , text{text}
{

}

QString MessageBad::getAuthor() const
{
    return author;
}

void MessageBad::setAuthor(const QString& value)
{
    author = value;
}

QString MessageBad::getText() const
{
    return text;
}

void MessageBad::setText(const QString& value)
{
    text = value;
}

QString SystemMessage::getAuthor() const
{
    return "System";
}

void SystemMessage::setAuthor(const QString& value)
{
    Q_UNUSED(value);
    throw std::logic_error("System Message author can't be changed");
}
