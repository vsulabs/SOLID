#include "cmdprocessorgood.h"
#include "cmdprocessortemplate.h"
#include <QtTest/QtTest>

class TestCmdProcessor : public QObject
{
    Q_OBJECT
public:
    TestCmdProcessor(ICmdProcessor* cp);

private slots:
    void testPrint();
    void testSum();
    void twoTake();
    void twoSum();
    void takeAndSum();

private:
    ICmdProcessor* cp;
};

TestCmdProcessor::TestCmdProcessor(ICmdProcessor *cp)
    : cp{cp}
{

}

void TestCmdProcessor::testPrint()
{
    QStringList res = cp->process("take 5");
    QCOMPARE(res.size(), 1);
    QVERIFY(res[0] == "5");
}

void TestCmdProcessor::testSum()
{
    QStringList res = cp->process("sum 7 8");
    QCOMPARE(res.size(), 1);
    QVERIFY(res[0] == "15");
}

void TestCmdProcessor::twoTake()
{
    QStringList res = cp->process("take 1\n"
                                  "take 2");
    QCOMPARE(res.size(), 2);
    QVERIFY(res[0] == "1");
    QVERIFY(res[1] == "2");
}

void TestCmdProcessor::twoSum()
{
    QStringList res = cp->process("sum 1 2\n"
                                  "sum 3 4");
    QCOMPARE(res.size(), 2);
    QVERIFY(res[0] == "3");
    QVERIFY(res[1] == "7");
}

void TestCmdProcessor::takeAndSum()
{
    QStringList res = cp->process("take 0\n"
                                  "sum 2 2");
    QCOMPARE(res.size(), 2);
    QVERIFY(res[0] == "0");
    QVERIFY(res[1] == "4");
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    app.setAttribute(Qt::AA_Use96Dpi, true);

    CmdProcessorGood* cp = new CmdProcessorGood();
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

    CmdProcessorSimple* cps = new CmdProcessorSimple();

    TestCmdProcessor testGood(cp);
    TestCmdProcessor testTemplate(cps);

    QTEST_SET_MAIN_SOURCE_PATH

    int res = QTest::qExec(&testGood, argc, argv);
    res += QTest::qExec(&testTemplate, argc, argv);
    delete cp;
    delete cps;
    return res;
}
#include "testcmdprocessor.moc"
