#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <QtCore/qstring>
#include <QtCore/qdir>
#include <QtGui/qcolor>
#include <QtCore/qsettings>
#include <QtGui/qfont>

class ConfigKeys
{
public:
    static const QString FontKey;
    enum Colors
    {
        DiffWindow_addedTextForeground = 0,
        DiffWindow_addedTextBackGround,
        DiffWindow_unchangedTextForeground,
        DiffWindow_unchangedTextBackGround,
        DiffWindow_changedTextForeground,
        DiffWindow_changedTextBackGround,
        DiffWindow_removedTextForeground,
        DiffWindow_removedTextBackGround,
        DiffWindow_lineNumberOddForeground,
        DiffWindow_lineNumberOddBackground,
        DiffWindow_lineNumberEvenForeground,
        DiffWindow_lineNumberEvenBackground,
        DiffWindow_mouseHover,
        COUNT
    };

private:
    static std::map<Colors, QString> colorsKeys;
    static std::map<Colors, QColor> colorsDefaults;
public:

    static Colors keyToColorEnum(QString key)
    {
        for (std::map<Colors, QString>::iterator it = colorsKeys.begin(); it != colorsKeys.end(); ++it)
            if (it->second == key)
                return it->first;
        return COUNT;
    }

    static QString getColorKey(Colors color)
    {
        return colorsKeys[color];
    }
    static QColor getColorDefault(Colors color)
    {
        return colorsDefaults[color];
    }
};



class ConfigManager
{
    
private:
    ConfigManager();
    ~ConfigManager();

    void generate();

    QString configDirectory;
    QSettings* settings;
    
public:
    ConfigManager(ConfigManager const&) = delete;
    void operator=(ConfigManager const&) = delete;
    static ConfigManager& getInstance();
    void initialize(QString directory);

    QColor getQColor(const QString key);
    QColor getQColor(const ConfigKeys::Colors key);
    void setQColor(const QString key, const QColor color);
    void setQColor(const ConfigKeys::Colors key, const QColor color);

    QFont getQFont(const QString key);
    void setQFont(const QString key, const QFont font);
;};

#endif // CONFIG_MANAGER_H