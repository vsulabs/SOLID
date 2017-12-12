#include "settingsbad.h"

#include <exception>

SettingsBad::SettingsBad()
{
}

SettingsBad::Theme SettingsBad::getTheme() const
{
    return theme;
}

void SettingsBad::setTheme(const Theme& value)
{
    theme = value;
}

bool SettingsBad::getFullScreen() const
{
    return fullScreen;
}

void SettingsBad::setFullScreen(bool value)
{
    fullScreen = value;
}

int SettingsBad::getConnectionTimeout() const
{
    return connectionTimeout;
}

void SettingsBad::setConnectionTimeout(int value)
{
    connectionTimeout = value;
}

QString SettingsBad::getProxy() const
{
    return proxy;
}

void SettingsBad::setProxy(const QString& value)
{
    proxy = value;
}
