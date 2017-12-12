#ifndef SETTINGS_GOOD_H
#define SETTINGS_GOOD_H

#include <QString>

class IUISettings {
public:
    enum class Theme {
        Dark, Yellow, White
    };

    virtual Theme getTheme() const = 0;
    virtual void setTheme(const Theme& value) = 0;

    virtual bool getFullScreen() const = 0;
    virtual void setFullScreen(bool value) = 0;
};

class INetworkSettings {
public:
    virtual int getConnectionTimeout() const = 0;
    virtual void setConnectionTimeout(int value) = 0;

    virtual QString getProxy() const = 0;
    virtual void setProxy(const QString& value) = 0;
};

class SettingsGood : public IUISettings, public INetworkSettings
{
public:
    SettingsGood();

    IUISettings::Theme getTheme() const override;
    void setTheme(const Theme& value) override;

    bool getFullScreen() const override;
    void setFullScreen(bool value) override;

    int getConnectionTimeout() const override;
    void setConnectionTimeout(int value) override;

    QString getProxy() const override;
    void setProxy(const QString& value) override;

private:
    Theme theme;
    bool fullScreen;

    int connectionTimeout;
    QString proxy;
};

#endif // SETTINGS_GOOD_H
