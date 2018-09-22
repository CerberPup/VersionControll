#ifndef DIALOG_SETTINGS_H
#define DIALOG_SETTINGS_H

#include "GeneratedFiles/ui_dialog_settings.h"
#include "GeneratedFiles/ui_dialog_settings_color.h" 
#include "headerfiles/settings_model.h"

#include <QDialog>

class FontPickingWidget :public QWidget
{
    Q_OBJECT

public:
    FontPickingWidget(QString label, QString key, QWidget* parrent);

private:
    QString m_key;
    QLabel* m_fontLabel;

private slots:
    void onFontChoose();
};

class ColorPickingWidget :public QWidget
{
    Q_OBJECT

public:
    ColorPickingWidget(QString label, QString key, QWidget* parrent);

private:
    QString m_key;
    QLabel* m_colorLabel;

private slots:
    void onColorChoose();
};

class DialogSettings : public QDialog, public Ui::DialogSettings
{
    Q_OBJECT

private:
    SettingsModel m_model;
    Ui::DialogSettingsColor* wdg;
    QList<QHBoxLayout*> m_rows;

    void createColorRow(QString label, QString key);
    void createFontRow(QString label, QString key);

private slots:
    void onSelectedItem(const QModelIndex &index);
public:
    DialogSettings(QWidget *parent);
    ~DialogSettings();

};

#endif // !DIALOG_SETTINGS_H