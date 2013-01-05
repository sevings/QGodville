#include "settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent):
    QDialog(parent)
{
    QLabel *nameLabel = new QLabel(tr("Имя бога"));
    nameLine = new QLineEdit;
    if (settings.contains("godname"))
        nameLine->setText(settings.value("godname").toString());
    QLabel *serverLabel = new QLabel(tr("Сервер"));
    serverBox = new QComboBox;
    serverBox->setEditable(false);
    serverBox->addItem("godville.net");
    serverBox->addItem("godvillegame.com");
    if (settings.value("server").toString()=="godvillegame.com")
        serverBox->setCurrentIndex(1);
    QLabel *fontLabel = new QLabel(tr("Шрифт"));
    fontBox = new QFontComboBox;
    QFont currentFont(settings.value("fontFamily").toString());
    fontBox->setCurrentFont(currentFont);
    fontSizeBox = new QComboBox;
    fontSizeBox->setEditable(false);
    for (int i=8; i<30; i+=2)
        fontSizeBox->addItem(QString::number(i));
    fontSizeBox->setCurrentIndex((settings.value("fontSize").toInt()-8)/2);
    ok = new QPushButton(tr("Применить"));
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(nameLine, 0, 1, 1, 2);
    layout->addWidget(serverLabel, 1, 0);
    layout->addWidget(serverBox, 1, 1, 1, 2);
    layout->addWidget(fontLabel, 2, 0);
    layout->addWidget(fontBox, 2, 1);
    layout->addWidget(fontSizeBox, 2, 2);
    QVBoxLayout *formLayout = new QVBoxLayout;
    formLayout->addLayout(layout);
#ifdef Q_WS_MAEMO_5
    formLayout->addWidget(ok);
#else
    cancel = new QPushButton(tr("Отмена"));
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(ok);
    buttonLayout->addWidget(cancel);
    formLayout->addLayout(buttonLayout);
    connect(cancel, SIGNAL(clicked()), this, SLOT(close()));
#endif
    setLayout(formLayout);

    connect(ok, SIGNAL(clicked()), this, SLOT(save()));
}

void SettingsDialog::save()
{
    settings.setValue("godname", nameLine->text());
    settings.setValue("fontFamily", fontBox->currentFont().family());
    settings.setValue("fontSize", fontSizeBox->currentText());
    if ((settings.contains("server") and settings.value("server").toString()!=serverBox->currentText())
            or (!settings.contains("server") and ((serverBox->currentText()=="godvillegame.com" and QLocale::system().name()=="ru_RU")
                                                  or (serverBox->currentText()=="godville.net" and QLocale::system().name()!="ru_RU"))))
    {
        settings.setValue("server", serverBox->currentText());
        settings.sync();
        QMessageBox::information(this, "The language changed.",
          "Please restart the program.");
        QApplication::quit();
    }
    else
        settings.setValue("server", serverBox->currentText());
    settings.sync();
    accept();
}
