#include "cmdprocessorgood.h"
#include <QtTest/QtTest>

class TestMessage : public QObject
{
    Q_OBJECT
public:
    TestMessage();
    ~TestMessage();

private slots:
    void testPrint();
    void testSum();
    void twoTake();
    void twoSum();
    void takeAndSum();

private:
    CmdProcessorGood* cp;
};

TestMessage::TestMessage()
{
    cp = new CmdProcessorGood();
    cp->addCommand("take", [](const QString& cmd) {
        int a;
        sscanf(cmd.toStdString().c_str(), "%*s %d", &a);
        return QString::number(a);
    });
    cp->addCommand("sum", [](const QString& cmd) {
        int a, b;
        sscanf(cmd.toStdString().c_str(), "%*s %d %d", &a, &b);
        return QString::number(a + b);
    });
}

TestMessage::~TestMessage()
{
    delete cp;
}

void TestMessage::testPrint()
{
    QStringList res = cp->process("take 5");
    QCOMPARE(res.size(), 1);
    QVERIFY(res[0] == "5");
}

void TestMessage::testSum()
{
    QStringList res = cp->process("sum 7 8");
    QCOMPARE(res.size(), 1);
    QVERIFY(res[0] == "15");
}

void TestMessage::twoTake()
{
    QStringList res = cp->process("take 1\n"
                                  "take 2");
    QCOMPARE(res.size(), 2);
    QVERIFY(res[0] == "1");
    QVERIFY(res[1] == "2");
}

void TestMessage::twoSum()
{
    QStringList res = cp->process("sum 1 2\n"
                                  "sum 3 4");
    QCOMPARE(res.size(), 2);
    QVERIFY(res[0] == "3");
    QVERIFY(res[1] == "7");
}

void TestMessage::takeAndSum()
{
    QStringList res = cp->process("take 0\n"
                                  "sum 2 2");
    QCOMPARE(res.size(), 2);
    QVERIFY(res[0] == "0");
    QVERIFY(res[1] == "4");
}

QTEST_MAIN(TestCmdProcessor)
#include "testcmdprocessor.moc"
