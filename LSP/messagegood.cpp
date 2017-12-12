#include "messagegood.h"

MessageGood::MessageGood()
{
}

MessageGood::MessageGood(MessageGood::Type type, const QString& author, const QString& text)
    : type{type}
    , author{author}
    , text{text}
{
}

MessageGood::Type MessageGood::getType() const
{
    return type;
}

void MessageGood::setType(const Type& value)
{
    type = value;
}

QString MessageGood::getAuthor() const
{
    if (type == Type::System) {
        return "System";
    }
    return author;
}

void MessageGood::setAuthor(const QString& value)
{
    if (type == Type::System) {
        throw std::logic_error("System Message author can't be changed");
    }

    author = value;
}

QString MessageGood::getText() const
{
    return text;
}

void MessageGood::setText(const QString& value)
{
    text = value;
}
