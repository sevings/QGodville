#include "Godville.h"

Godville::Godville(QMainWindow *parent):
    QMainWindow(parent), expired(true), fight(true), ok(false)
{
    QLabel *nLabel = new QLabel(tr("Имя"));        //hero
    QLabel *gLabel = new QLabel(tr("Пол"));
    QLabel *mLabel = new QLabel(tr("Девиз"));
    QLabel *aLabel = new QLabel(tr("Характер"));
    QLabel *cLabel = new QLabel(tr("Гильдия"));
    QLabel *leLabel = new QLabel(tr("Уровень"));       //data
    QLabel *inLabel = new QLabel(tr("Инвентарь"));
    QLabel *heLabel = new QLabel(tr("Здоровье"));
    QLabel *quLabel = new QLabel(tr("Задание"));
    QLabel *gaLabel = new QLabel(tr("Золота"));
    bcLabel = new QLabel(tr("Кирпичей для храма"));
    diLabel = new QLabel(tr("Столбов от столицы"));
    QLabel *pcLabel = new QLabel(tr("Вид"));
    QLabel *plLabel = new QLabel(tr("Уровень"));
    QLabel *pnLabel = new QLabel(tr("Имя"));
    QLabel *geLabel = new QLabel(tr("Прана"));

    nameLabel = new QLabel;
    nameLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    genderLabel = new QLabel;
    genderLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    mottoLabel = new QLabel;
    mottoLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    mottoLabel->setWordWrap(true);
    alignmentLabel = new QLabel;
    alignmentLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    clanLabel = new QLabel;
    clanLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    clanLabel->setWordWrap(true);
    levelLabel = new QLabel;
    levelLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    inventoryLabel = new QLabel;
    inventoryLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    healthLabel = new QLabel;
    healthLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    questLabel = new QLabel;
    questLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    questLabel->setWordWrap(true);
    goldLabel = new QLabel;
    goldLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    goldLabel->setWordWrap(true);
    bricksLabel = new QLabel;
    bricksLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    distanceLabel = new QLabel;
    distanceLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    petNameLabel = new QLabel;
    petNameLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    petClassLabel = new QLabel;
    petClassLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    petLevelLabel = new QLabel;
    petLevelLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    diaryLabel = new QLabel;
    diaryLabel->setWordWrap(true);
    energyLabel = new QLabel;
    energyLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);

    experienceBar = new QProgressBar;
    experienceBar->setTextVisible(false);
    setBarStyle(experienceBar, "f9b436");
    inventoryBar = new QProgressBar;
    inventoryBar->setTextVisible(false);
    setBarStyle(inventoryBar, "882d17");
    healthBar = new QProgressBar;
    healthBar->setTextVisible(false);
    questBar = new QProgressBar;
    questBar->setTextVisible(false);
    setBarStyle(questBar, "ffc0cb");
    energyBar = new QProgressBar;
    energyBar->setTextVisible(false);
    setBarStyle(energyBar, "199bdc");

    QHBoxLayout *nameLayout = new QHBoxLayout;
    nameLayout->addWidget(nLabel);
    nameLayout->addWidget(nameLabel);
    QHBoxLayout *genderLayout = new QHBoxLayout;
    genderLayout->addWidget(gLabel);
    genderLayout->addWidget(genderLabel);
    QHBoxLayout *mottoLayout = new QHBoxLayout;
    mottoLayout->addWidget(mLabel);
    mottoLayout->addWidget(mottoLabel);
    QHBoxLayout *alignLayout = new QHBoxLayout;
    alignLayout->addWidget(aLabel);
    alignLayout->addWidget(alignmentLabel);
    QHBoxLayout *clanLayout = new QHBoxLayout;
    clanLayout->addWidget(cLabel);
    clanLayout->addWidget(clanLabel);
    QHBoxLayout *levelLayout = new QHBoxLayout;
    levelLayout->addWidget(leLabel);
    levelLayout->addWidget(levelLabel);
    QHBoxLayout *inventoryLayout = new QHBoxLayout;
    inventoryLayout->addWidget(inLabel);
    inventoryLayout->addWidget(inventoryLabel);
    QHBoxLayout *healthLayout = new QHBoxLayout;
    healthLayout->addWidget(heLabel);
    healthLayout->addWidget(healthLabel);
    QHBoxLayout *questLayout = new QHBoxLayout;
    questLayout->addWidget(quLabel);
    questLayout->addWidget(questLabel);
    QHBoxLayout *goldLayout = new QHBoxLayout;
    goldLayout->addWidget(gaLabel);
    goldLayout->addWidget(goldLabel);
    QHBoxLayout *bricksLayout = new QHBoxLayout;
    bricksLayout->addWidget(bcLabel);
    bricksLayout->addWidget(bricksLabel);
    QHBoxLayout *distanceLayout = new QHBoxLayout;
    distanceLayout->addWidget(diLabel);
    distanceLayout->addWidget(distanceLabel);
    QHBoxLayout *petNameLayout = new QHBoxLayout;
    petNameLayout->addWidget(pnLabel);
    petNameLayout->addWidget(petNameLabel);
    QHBoxLayout *petClassLayout = new QHBoxLayout;
    petClassLayout->addWidget(pcLabel);
    petClassLayout->addWidget(petClassLabel);
    QHBoxLayout *petLevelLayout = new QHBoxLayout;
    petLevelLayout->addWidget(plLabel);
    petLevelLayout->addWidget(petLevelLabel);
    QHBoxLayout *energyLayout = new QHBoxLayout;
    energyLayout->addWidget(geLabel);
    energyLayout->addWidget(energyLabel);

    QVBoxLayout *heroLayout = new QVBoxLayout;
    heroLayout->addLayout(nameLayout);
    heroLayout->addLayout(genderLayout);
    heroLayout->addLayout(mottoLayout);
    heroLayout->addLayout(alignLayout);
    heroLayout->addLayout(clanLayout);
    QVBoxLayout *dataLayout = new QVBoxLayout;
    dataLayout->addLayout(levelLayout);
    dataLayout->addWidget(experienceBar);
    dataLayout->addLayout(inventoryLayout);
    dataLayout->addWidget(inventoryBar);
    dataLayout->addLayout(healthLayout);
    dataLayout->addWidget(healthBar);
    dataLayout->addLayout(questLayout);
    dataLayout->addWidget(questBar);
    dataLayout->addLayout(goldLayout);
    dataLayout->addLayout(bricksLayout);
    dataLayout->addLayout(distanceLayout);
    QVBoxLayout *petLayout = new QVBoxLayout;
    petLayout->addLayout(petNameLayout);
    petLayout->addLayout(petClassLayout);
    petLayout->addLayout(petLevelLayout);
    QVBoxLayout *diaryLayout = new QVBoxLayout;
    diaryLayout->addWidget(diaryLabel);
    QVBoxLayout *pranaLayout = new QVBoxLayout;
    pranaLayout->addLayout(energyLayout);
    pranaLayout->addWidget(energyBar);
    inventoryVLayout = new QVBoxLayout;

    QGroupBox *heroBox = new QGroupBox(tr("Герой"));
    heroBox->setLayout(heroLayout);
    QGroupBox *dataBox = new QGroupBox(tr("Данные героя"));
    dataBox->setLayout(dataLayout);
    petBox = new QGroupBox(tr("Питомец"));
    petBox->setLayout(petLayout);
    diaryBox = new QGroupBox(tr("Дневник героя"));
    diaryBox->setLayout(diaryLayout);
    energyBox = new QGroupBox(tr("Вмешательство"));
    energyBox->setLayout(pranaLayout);
    inventoryBox = new QGroupBox(tr("В карманах можно найти:"));
    inventoryBox->setLayout(inventoryVLayout);

    QVBoxLayout *boxLayout = new QVBoxLayout;
    boxLayout->addWidget(heroBox);
    boxLayout->addWidget(dataBox);
    boxLayout->addWidget(petBox);
    boxLayout->addWidget(diaryBox);
    boxLayout->addWidget(inventoryBox);
    boxLayout->addWidget(energyBox);

    QWidget *page = new QWidget(this);
    page->setLayout(boxLayout);

    QScrollArea *scroll = new QScrollArea(this);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setWidget(page);
    scroll->setWidgetResizable(true);


#ifdef Q_WS_MAEMO_5
    setAttribute(Qt::WA_Maemo5AutoOrientation, true);
#endif
    setCentralWidget(scroll);
    setWindowTitle("QGodville");
    changeFont();

    updateAction = new QAction(tr("Обновить"), this);
    optionsAction = new QAction(tr("Настройки"), this);
    aboutAction = new QAction(tr("О программе"), this);
    quitAction = new QAction(tr("Выход"), this);
    menuBar()->addAction(updateAction);
    menuBar()->addAction(optionsAction);
    menuBar()->addAction(aboutAction);
    menuBar()->addAction(quitAction);

    manager = new QNetworkAccessManager(this);
    timer = new QTimer(this);

    if (settings.contains("data"))
      {
      json = settings.value("data").toByteArray();
      updateData();
      }
    if (settings.contains("godname") and 
      settings.contains("server") and
      settings.contains("fontFamily") and
      settings.contains("fontSize"))
        forcedUpdate();
    else
        options();

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readJson(QNetworkReply*)));
    connect(timer, SIGNAL(timeout()), this, SLOT(reloadJson()));
    connect(optionsAction, SIGNAL(triggered()), this, SLOT(options()));
    connect(updateAction, SIGNAL(triggered()), this, SLOT(forcedUpdate()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void Godville::reloadJson()
{
    QUrl request(QString("http://%1/gods/api/%2.json").arg(settings.value("server").toString())
                             .arg(settings.value("godname").toString()));
    manager->get(QNetworkRequest(request));
}

void Godville::readJson(QNetworkReply* list)
{
    if (!list->error())
    {
        json = list->readAll();
        updateData();
    }
    else
    {
        QMessageBox::critical(this, tr("Ошибка загрузки данных"),
          tr("Проверьте соединение с интернетом (код ошибки %1)")
          .arg(list->error()));
        ok = false;
        if (!settings.contains("data"))
            options();
    }
    list->deleteLater();
    list = NULL;
}

void Godville::updateData()
{
    Parser parser(json);
    ok = parser.parse();
    QVariantMap* data = parser.toMap();
    if (!ok)
    {
        QMessageBox::critical(this, tr("Ошибка распаковки данных"), 
          tr("Проверьте имя бога и сервер"));
        return;
    }

    nameLabel->setText(data->value("name").toString());
    if (data->value("gender").toString()=="male")
        genderLabel->setText(tr("мужской"));
    if (data->value("gender").toString()=="female")
        genderLabel->setText(tr("женский"));
    mottoLabel->setText(data->value("motto").toString());
    alignmentLabel->setText(data->value("alignment").toString());
    if (!data->value("clan").toString().isEmpty())
        clanLabel->setText(tr("%1 (%2)").arg(data->value("clan").toString())
          .arg(data->value("clan_position").toString()));
    else
        clanLabel->setText(tr("(не состоит)"));
    levelLabel->setText(data->value("level").toString());
    if (data->contains("diary_last"))
    {
        inventoryLabel->setText(tr("%1/%2")
          .arg(data->value("inventory_num").toString())
          .arg(data->value("inventory_max_num").toString()));
        healthLabel->setText(tr("%1/%2")
          .arg(data->value("health").toString())
          .arg(data->value("max_health").toString()));
        experienceBar->setValue(data->value("exp_progress").toInt());
        inventoryBar->setMaximum(data->value("inventory_max_num").toInt());
        inventoryBar->setValue(data->value("inventory_num").toInt());
        healthBar->setMaximum(data->value("max_health").toInt());
        healthBar->setValue(data->value("health").toInt());
        if (healthBar->value()<healthBar->maximum()*0.3)
            setBarStyle(healthBar, "eb0000");
        else if (healthBar->value()>healthBar->maximum()*0.7)
            setBarStyle(healthBar, "008000");
        else
            setBarStyle(healthBar, "f6f600");
        questBar->setValue(data->value("quest_progress").toInt());
        diaryLabel->setText(data->value("diary_last").toString());
        energyLabel->setText(data->value("godpower").toString() + "%");
        energyBar->setValue(data->value("godpower").toInt());
        if (data->value("town_name").toString()=="")
        {
            diLabel->setText(tr("Столбов от столицы"));
            distanceLabel->setText(tr("%1 шт.")
              .arg(data->value("distance").toString()));
        }
        else
        {
            diLabel->setText(tr("Город"));
            distanceLabel->setText(data->value("town_name").toString());
        }

        QMap<QString, QVariant> inventory = data->value("inventory").toMap();
        int n = data->value("inventory_num").toInt();
        while (inventoryList.size()<n)
        {
            QLabel* lbl = new QLabel;
            inventoryList.append(lbl);
            inventoryVLayout->addWidget(lbl);
            lbl->setWordWrap(true);
        }
        QMapIterator<QString, QVariant> i(inventory);
        while (i.hasNext())
        {
            i.next();
            QVariantMap item = i.value().toMap();
            int j = item.value("pos").toInt();
            QString text = i.key();
            if (item.value("cnt").toInt()>1)
            {
                text = tr("%1 (%2 шт)").arg(text)
                  .arg(item.value("cnt").toInt());
                n -= item.value("cnt").toInt()-1;
            }
            if (item.value("activate_by_user").toBool())
                text = tr("%1 (@)").arg(text);
            if (item.value("price").toInt())
                text = "<b>" + text + "</b>";
            if (item.value("type").toString()=="heal_potion")
                text = "<i>" + text + "</i>";
            text = "- " + text;
            inventoryList[j]->setText(text);
        }
        while (inventoryList.size()>n)
            delete inventoryList.takeLast();
        if (n==0)
            inventoryBox->setTitle(tr("В карманах пусто."));
        else
            inventoryBox->setTitle(tr("В карманах можно найти:"));

        experienceBar->show();
        inventoryBar->show();
        healthBar->show();
        questBar->show();
        energyBox->show();
        inventoryBox->show();
        diaryBox->show();
        diLabel->show();
        distanceLabel->show();
    }
    else
    {
        inventoryLabel->setText(data->value("inventory_max_num").toString());
        healthLabel->setText(data->value("max_health").toString());
        experienceBar->hide();
        inventoryBar->hide();
        healthBar->hide();
        questBar->hide();
        energyBox->hide();
        inventoryBox->hide();
        diaryBox->hide();
        diLabel->hide();
        distanceLabel->hide();
    }

    questLabel->setText(data->value("quest").toString());
    goldLabel->setText(data->value("gold_approx").toString());
    if (data->value("bricks_cnt").toInt()<1000)
    {
        bcLabel->show();
        bricksLabel->show();
        bcLabel->setText(tr("Кирпичей для храма"));
        double bricks = data->value("bricks_cnt").toDouble();
        bricks/=10;
        bricksLabel->setText(QString::number(bricks) + "%");
    }
    else
    {
        bcLabel->hide();
        bricksLabel->hide();
    }
    if (data->contains("pet"))
    {
        petBox->show();
        QVariantMap pet = data->value("pet").toMap();
        petNameLabel->setText(pet.value("pet_name").toString());
        petClassLabel->setText(pet.value("pet_class").toString());
        petLevelLabel->setText(pet.value("pet_level").toString());
    }
    else
        petBox->hide();

    setWindowTitle(data->value("godname").toString());

#ifdef Q_WS_MAEMO_5
    if (!expired and data->value("expired").toBool())
    {
        expired = data->value("expired").toBool();
        QMaemo5InformationBox::information(this, tr("Данные устарели!\nОткройте страницу героя через браузер или полноценный клиент."),
          QMaemo5InformationBox::NoTimeout);
    }
    else
        expired = data->value("expired").toBool();
    if (!fight and data->value("arena_fight").toBool())
    {
        fight = data->value("arena_fight").toBool();
        QMaemo5InformationBox::information(this, tr("Битва началась!"),
          QMaemo5InformationBox::NoTimeout);
    }
    else
        fight = data->value("arena_fight").toBool();
#else
    if (!expired and data->value("expired").toBool())
    {
        expired = data->value("expired").toBool();
        QMessageBox::warning(this, tr("Данные устарели!"),
          tr("Откройте страницу героя через браузер или полноценный клиент."));
    }
    else
        expired = data->value("expired").toBool();
    if (!fight and data->value("arena_fight").toBool())
    {
        fight = data->value("arena_fight").toBool();
        QMessageBox::warning(this, tr("Внимание!"), tr("Битва началась!"));
    }
    else
        fight = data->value("arena_fight").toBool();
#endif
}

void Godville::forcedUpdate()
{
    timer->stop();
    reloadJson();
    timer->start(60000);
}

void Godville::about()
{
    QMessageBox::about(this, tr("О программе"),
      tr("QGodville 1.0 \nbinque (Семикрылый), 2012"));
}

void Godville::options()
{
    SettingsDialog dialog(this);
    connect(&dialog, SIGNAL(accepted()), this, SLOT(forcedUpdate()));
    connect(&dialog, SIGNAL(accepted()), this, SLOT(changeFont()));
    connect(&dialog, SIGNAL(rejected()), this, SLOT(canceled()));
    dialog.exec();
}

void Godville::changeFont()
{
    setStyleSheet(QString("QGroupBox, QLabel { font-family: ""%1""; font-size: %2px; }").arg( settings.value("fontFamily").toString())
                  .arg(settings.value("fontSize").toString()));
}

void Godville::setBarStyle(QProgressBar *bar, QString color)
{
bar->setStyleSheet(QString("QProgressBar::chunk {background-color: #%1; width: 20px;} QProgressBar {border: 2px solid #999999; max-height: 20px}")
  .arg(color));
}
void Godville::canceled()
{
    if (!settings.contains("godname"))
        QApplication::quit();
}

Godville::~Godville()
{
    if (ok)
        settings.setValue("data", json);
}
