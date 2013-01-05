#include <QtGui>
//#include <QDebug>
#include "Godville.h"

int main (int argc, char *argv[]) 
{ 
    QApplication app(argc, argv); 
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    QCoreApplication::setOrganizationName("binque");
    QCoreApplication::setApplicationName("QGodville");

    QSettings settings;
    QTranslator translator;
    if (settings.value("server").toString()=="godvillegame.com" or (!settings.contains("server") and QLocale::system().name()!="ru_RU"))
    {
        translator.load("qgodville_en", "/usr/bin/qgodville/");
        app.installTranslator(&translator);
    }

    Godville gv;
    gv.show();
    return app.exec(); 
}
