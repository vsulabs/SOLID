#include "settingsgood.h"

SettingsGood::SettingsGood()
{
}

IUISettings::Theme SettingsGood::getTheme() const
{
    return theme;
}

void SettingsGood::setTheme(const Theme& value)
{
    theme = value;
}

bool SettingsGood::getFullScreen() const
{
    return fullScreen;
}

void SettingsGood::setFullScreen(bool value)
{
    fullScreen = value;
}

int SettingsGood::getConnectionTimeout() const
{
    return connectionTimeout;
}

void SettingsGood::setConnectionTimeout(int value)
{
    connectionTimeout = value;
}

QString SettingsGood::getProxy() const
{
    return proxy;
}

void SettingsGood::setProxy(const QString& value)
{
    proxy = value;
}
