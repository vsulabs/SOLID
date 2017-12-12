#ifndef MESSAGE_GOOD_H
#define MESSAGE_GOOD_H

#include <QString>

class MessageGood
{
public:
    enum class Type {
        Normal, System
    };

    MessageGood();
    MessageGood(Type type, const QString& author, const QString& text);

    Type getType() const;
    void setType(const Type& value);

    QString getAuthor() const;
    void setAuthor(const QString& value);

    QString getText() const;
    void setText(const QString& value);

private:
    Type type;
    QString author;
    QString text;
};

#endif // MESSAGE_GOOD_H
