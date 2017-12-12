#include "testcorrectorgood.h"
#include <QtTest/QtTest>

class TestTextCorrector : public QObject
{
    Q_OBJECT
public:
    TestTextCorrector();
    ~TestTextCorrector();
private slots:
    void trim();
    void firstIsUpper();
    void lastIsDot();
    void removeSpacesBetweenSentences();
    void makeUpperLaterAfterDot();

private:
    TextCorrectorGood* tc;
};

TestTextCorrector::TestTextCorrector()
{
    tc = new TextCorrectorGood();
}

TestTextCorrector::~TestTextCorrector()
{
    delete tc;
}

void TestTextCorrector::trim()
{
    tc->setText("   ASD.    ");
    QVERIFY(tc->getCorrected() == "ASD.");
}

void TestTextCorrector::firstIsUpper()
{
    tc->setText("asd.");
    QVERIFY(tc->getCorrected() == "Asd.");
}

void TestTextCorrector::lastIsDot()
{
    tc->setText("Asd");
    QVERIFY(tc->getCorrected() == "Asd.");
}

void TestTextCorrector::removeSpacesBetweenSentences()
{
    tc->setText("First part.        Second Part.       Thrid part.");
    QVERIFY(tc->getCorrected() == "First part. Second Part. Thrid part.");
}

void TestTextCorrector::makeUpperLaterAfterDot()
{
    tc->setText("qwe rty. asd fgh. zxc vbn.");
    QVERIFY(tc->getCorrected() == "Qwe rty. Asd fgh. Zxc vbn.");
}

QTEST_MAIN(TestTextCorrector)
#include "testtextcorrector.moc"
