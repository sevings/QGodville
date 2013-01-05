#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QtGui>

class SettingsDialog: public QDialog
{
    Q_OBJECT

public:
    SettingsDialog(QWidget *parent=0);

public slots:
    void save();

private:
    QLineEdit *nameLine;
    QComboBox *serverBox;
    QComboBox *fontSizeBox;
    QFontComboBox *fontBox;
    QSettings settings;
    QPushButton *ok;
    QPushButton *cancel;
};
#endif
