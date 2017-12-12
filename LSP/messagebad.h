#ifndef MESSAGE_BAD_H
#define MESSAGE_BAD_H

#include <QString>

class MessageBad
{
public:
    MessageBad();
    MessageBad(const QString& author, const QString& text);

    virtual QString getAuthor() const;
    virtual void setAuthor(const QString& value);

    virtual QString getText() const;
    virtual void setText(const QString& value);

private:
    QString author;
    QString text;
};

class SystemMessage : public MessageBad
{
public:
    SystemMessage(const QString& text);
    QString getAuthor() const override;
    void setAuthor(const QString& value) override;
};

#endif // MESSAGE_BAD_H
