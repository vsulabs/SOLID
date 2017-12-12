#include "settingsgood.h"
#include <QtTest/QtTest>
#include <exception>

class TestSettings : public QObject
{
    Q_OBJECT
private slots:
    void changeTheme();
    void changeFullscreen();
    void changeProxy();
    void changeTimeout();

private:
    SettingsGood s;
};

void TestSettings::changeTheme()
{
    IUISettings* uis = &s;
    uis->setTheme(SettingsGood::Theme::Dark);
    QCOMPARE(uis->getTheme(), SettingsGood::Theme::Dark);
    uis->setTheme(SettingsGood::Theme::Yellow);
    QCOMPARE(uis->getTheme(), SettingsGood::Theme::Yellow);
    uis->setTheme(SettingsGood::Theme::White);
    QCOMPARE(uis->getTheme(), SettingsGood::Theme::White);
}

void TestSettings::changeFullscreen()
{
    IUISettings* uis = &s;
    uis->setFullScreen(true);
    QCOMPARE(uis->getFullScreen(), true);
    uis->setFullScreen(false);
    QCOMPARE(uis->getFullScreen(), false);
}

void TestSettings::changeProxy()
{
    INetworkSettings* ns = &s;
    ns->setProxy(QString{});
    QVERIFY(ns->getProxy().isEmpty());
    ns->setProxy("sock5://127.0.0.1:9876");
    QVERIFY(ns->getProxy() == "sock5://127.0.0.1:9876");
}

void TestSettings::changeTimeout()
{
    INetworkSettings* ns = &s;
    ns->setConnectionTimeout(10);
    QCOMPARE(ns->getConnectionTimeout(), 10);
    ns->setConnectionTimeout(0);
    QCOMPARE(ns->getConnectionTimeout(), 0);
}

QTEST_MAIN(TestSettings)
#include "testsettings.moc"
