#ifndef GODVILLE_H
#define GODVILLE_H

#include <QtGui>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#ifdef Q_WS_MAEMO_5
#include <QtMaemo5/QMaemo5InformationBox>
#endif
#include "settingsdialog.h"
#include "parser.h"

class QLabel;

class Godville: public QMainWindow
{
    Q_OBJECT
public:
    Godville(QMainWindow *parent=0);
    ~Godville();

public slots:
    void updateData();
    void reloadJson();
    void readJson(QNetworkReply* list);
    void forcedUpdate();
    void options();
    void about();
    void changeFont();
    void canceled();

private:
    QLabel *nameLabel;     //hero
    QLabel *genderLabel;
    QLabel *mottoLabel;
    QLabel *alignmentLabel;
    QLabel *clanLabel;
    QLabel *levelLabel;       //data
    QLabel *inventoryLabel;
    QLabel *healthLabel;
    QLabel *questLabel;
    QLabel *goldLabel;
    QLabel *bcLabel;
    QLabel *bricksLabel;
    QLabel *diLabel;
    QLabel *distanceLabel;
    QLabel *petNameLabel;  //pet
    QLabel *petClassLabel;
    QLabel *petLevelLabel;
    QLabel *diaryLabel;       //diary
    QLabel *energyLabel;   //prana
    QProgressBar *experienceBar;
    QProgressBar *inventoryBar;
    QProgressBar *healthBar;
    QProgressBar *questBar;
    QProgressBar *energyBar;
    QGroupBox *energyBox;
    QGroupBox *petBox;
    QGroupBox *diaryBox;
    QGroupBox *inventoryBox;
    QVBoxLayout *inventoryVLayout;
    QList<QLabel*> inventoryList;
    QNetworkAccessManager *manager;
    QSettings settings;
    QTimer *timer;
    QMenu *menu;
    QAction *optionsAction;
    QAction *updateAction;
    QAction *aboutAction;
    QAction *quitAction;
    bool expired;
    bool fight;
    QByteArray json;
    bool ok;
    inline void setBarStyle (QProgressBar *bar, QString color);
};
#endif
