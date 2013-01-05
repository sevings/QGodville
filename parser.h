#ifndef Parser_H
#define Parser_H

#include <QVariantMap>

class Parser: public QObject
{
    Q_OBJECT
public:
    Parser(QByteArray ba, QObject* parent = 0);
    ~Parser();
    bool parse();
    QVariantMap* toMap();

private:
    bool FSM();
    void parsing(QVariantMap* map, int &i);
    void convert(QString* string);
    QByteArray json;
    QVariantMap* parsed;
};

#endif // Parser_H
