#include "messagebad.h"
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
};

void TestMessage::construct()
{
    MessageBad msg1("author", "text");
    QVERIFY(msg1.getAuthor() == "author");
    QVERIFY(msg1.getText() == "text");

    SystemMessage msg2("alert");
    QVERIFY(msg2.getAuthor() == "System");
    QVERIFY(msg2.getText() == "alert");
}

void TestMessage::changeAuthorOfNormalMessage()
{
    MessageBad msg("author", "text");
    msg.setAuthor("new author");
    QVERIFY(msg.getAuthor() == "new author");
}

void TestMessage::changeAuthorOfSystemMessage()
{
    MessageBad msg(QString{}, "text");
    QVERIFY_EXCEPTION_THROWN(msg.setAuthor("test"), std::logic_error);
}

void TestMessage::changeText()
{
    MessageBad msg1("author", "text");
    msg1.setText("new text");
    QVERIFY(msg1.getText() == "new text");

    SystemMessage msg2("text");
    msg2.setText("new text");
    QVERIFY(msg2.getText() == "new text");
}

QTEST_MAIN(TestMessage)
#include "testmessage.moc"
