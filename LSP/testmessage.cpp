#include "messagegood.h"
#include <QtTest/QtTest>
#include <exception>

class TestMessage : public QObject
{
    Q_OBJECT
private slots:
    void construct();
    void changeAuthorOfNormalMessage();
    void changeAuthorOfSystemMessage();
    void changeText();
    void changeType();
};

void TestMessage::construct()
{
    MessageGood msg1(MessageGood::Type::Normal, "author", "text");
    QVERIFY(msg1.getType() == MessageGood::Type::Normal);
    QVERIFY(msg1.getAuthor() == "author");
    QVERIFY(msg1.getText() == "text");

    MessageGood msg2(MessageGood::Type::System, QString{}, "alert");
    QVERIFY(msg2.getType() == MessageGood::Type::System);
    QVERIFY(msg2.getAuthor() == "System");
    QVERIFY(msg2.getText() == "alert");
}

void TestMessage::changeAuthorOfNormalMessage()
{
    MessageGood msg(MessageGood::Type::Normal, "author", "text");
    msg.setAuthor("new author");
    QVERIFY(msg.getAuthor() == "new author");
}

void TestMessage::changeAuthorOfSystemMessage()
{
    MessageGood msg(MessageGood::Type::System, QString{}, "text");
    QVERIFY_EXCEPTION_THROWN(msg.setAuthor("test"), std::logic_error);
}

void TestMessage::changeText()
{
    MessageGood msg1(MessageGood::Type::Normal, "author", "text");
    msg1.setText("new text");
    QVERIFY(msg1.getText() == "new text");

    MessageGood msg2(MessageGood::Type::System, "author", "text");
    msg2.setText("new text");
    QVERIFY(msg2.getText() == "new text");
}

void TestMessage::changeType()
{
    MessageGood msg1(MessageGood::Type::Normal, "author", "text");
    msg1.setType(MessageGood::Type::System);
    QVERIFY(msg1.getType() == MessageGood::Type::System);
    msg1.setType(MessageGood::Type::Normal);
    QVERIFY(msg1.getType() == MessageGood::Type::Normal);
}

QTEST_MAIN(TestMessage)
#include "testmessage.moc"
