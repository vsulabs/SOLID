#ifndef SETTINGS_BAD_H
#define SETTINGS_BAD_H

#include <QString>

class SettingsBad
{
public:
    enum class Theme {
        Dark, Yellow, White
    };
    SettingsBad();

    Theme getTheme() const;
    void setTheme(const Theme& value);

    bool getFullScreen() const;
    void setFullScreen(bool value);

    int getConnectionTimeout() const;
    void setConnectionTimeout(int value);

    QString getProxy() const;
    void setProxy(const QString& value);

private:
    Theme theme;
    bool fullScreen;

    int connectionTimeout;
    QString proxy;
};

#endif // SETTINGS_BAD_H
