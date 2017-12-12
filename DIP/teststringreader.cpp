#include "servicegood.h"

#include <QtTest/QtTest>
#include <iostream>

#include "Zone.h"
#include "GlobalZoneType.h"
#include "ConcreteZoneType.h"
#include "supply.h"

using namespace CppInject;
extern Zone globalZone;
Zone globalZone {&GlobalZoneType::instance};

class TestStringReader : public QObject
{
    Q_OBJECT
private slots:
    void sumOneTwo();
    void sumTenFive();

private:
    ServiceGood sg;
};

void TestStringReader::sumOneTwo()
{
    supply<IDataReader>::release(&globalZone);
    supply<IDataReader>::configure([](Zone& z) {
        return new StringReader("sum 1 2");
    });
    QVERIFY(sg.process() == "3");
}

void TestStringReader::sumTenFive()
{
    supply<IDataReader>::release(&globalZone);
    supply<IDataReader>::configure([](Zone& z) {
        return new StringReader("sum 10 5");
    });
    QVERIFY(sg.process() == "15");
}

QTEST_MAIN(TestStringReader)
#include "teststringreader.moc"
