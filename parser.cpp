#include "parser.h"

Parser::Parser(QByteArray ba, QObject * parent) :
    QObject(parent), json(ba)
{
    parsed = new QVariantMap();
}

bool Parser::FSM()
{
    enum States { start=0, ob=1, name=2, eofName=3, colon=4, strVal=5, eofVal=6, numVal=7, comma=8, cb=9,
                  t=10, r=11, u=12, f=13, a=14, l=15, s=16, n=17, ull=18, ll=19, err=101, OK=102};
    States ST[20][17] =
    {
//       {       "       :       ,       0..9    rest    }       \0     t       r       u       e       f       a       l       s       n
    {   ob,      err,    err,    err,    err,    err,    err,    err,   err,    err,    err,    err,    err,    err,    err,    err,    err}, //start
    {   err,     name,   err,    err,    err,    err,    cb,     err,   err,    err,    err,    err,    err,    err,    err,    err,    err}, //ob
    {   name,    eofName,name,   name,   name,   name,   name,   err,   name,   name,   name,   name,   name,   name,   name,   name,   name}, //name
    {   err,     err,    colon,  err,    err,    err,    err,    err,   err,    err,    err,    err,    err,    err,    err,    err,    err}, //eofName
    {   ob,      strVal, err,    err,    numVal, err,    err,    err,   t,      err,    err,    err,    f,      err,    err,    err,    n}, //colon
    {   strVal,  eofVal, strVal, strVal, strVal, strVal, strVal, err,   strVal, strVal, strVal, strVal, strVal, strVal, strVal, strVal, strVal}, //strVal
    {   err,     err,    err,    comma,  err,    err,    cb,     err,   err,    err,    err,    err,    err,    err,    err,    err,    err}, //eofVal
    {   err,     err,    err,    comma,  numVal, err,    cb,     err,   err,    err,    err,    err,    err,    err,    err,    err,    err}, //numVal
    {   err,     name,   err,    err,    err,    err,    err,    err,   err,    err,    err,    err,    err,    err,    err,    err,    err}, //comma
    {   err,     err,    err,    comma,  err,    err,     cb,     OK,   err,    err,    err,    err,    err,    err,    err,    err,    err},  //cb
    {   err,     err,    err,    err,    err,    err,    err,    err,   err,    r,      err,    err,    err,    err,    err,    err,    err}, //t
    {   err,     err,    err,    err,    err,    err,    err,    err,   err,    err,    u,      err,    err,    err,    err,    err,    err}, //r
    {   err,     err,    err,    err,    err,    err,    err,    err,   err,    err,    err,    eofVal, err,    err,    err,    err,    err}, //u
    {   err,     err,    err,    err,    err,    err,    err,    err,   err,    err,    err,    err,    err,    a,      err,    err,    err}, //f
    {   err,     err,    err,    err,    err,    err,    err,    err,   err,    err,    err,    err,    err,    err,    l,      err,    err}, //a
    {   err,     err,    err,    err,    err,    err,    err,    err,   err,    err,    err,    err,    err,    err,    err,    s,      err}, //l
    {   err,     err,    err,    err,    err,    err,    err,    err,   err,    err,    err,    eofVal, err,    err,    err,    err,    err}, //s
    {   err,     err,    err,    err,    err,    err,    err,    err,   err,    err,    ull,    err,    err,    err,    err,    err,    err}, //n
    {   err,     err,    err,    err,    err,    err,    err,    err,   err,    err,    err,    err,    err,    err,    ll,     err,    err}, //u
    {   err,     err,    err,    err,    err,    err,    err,    err,   err,    err,    err,    err,    err,    err,    eofVal, err,    err}  //l
    };
    States state = start;
    int brace = 0;
    int i;
    for (i = 0; i<json.size(); i++)
    {
        switch (json.at(i))
        {
        case '{':
            state = ST[state][0];
            brace++;
            break;
        case '"':
            state = ST[state][1];
            break;
        case ':':
            state = ST[state][2];
            break;
        case ',':
            state = ST[state][3];
            break;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            state = ST[state][4];
            break;
        case '}':
            state = ST[state][6];
            brace--;
            break;
        case 't':
            state = ST[state][8];
            break;
        case 'r':
            state = ST[state][9];
            break;
        case 'u':
            state = ST[state][10];
            break;
        case 'e':
            state = ST[state][11];
            break;
        case 'f':
            state = ST[state][12];
            break;
        case 'a':
            state = ST[state][13];
            break;
        case 'l':
            state = ST[state][14];
            break;
        case 's':
            state = ST[state][15];
            break;
        case 'n':
            state = ST[state][16];
            break;
        default:
            state = ST[state][5];
            break;
        }
        if (state==err or state==OK)
            break;
    }
    if (state == err or brace)
    {
//        qDebug("Number of braces is %d", brace);
//        qDebug("State is %d", state);
//        qDebug("Last symbols are %c, %c, %c", json.at(i-2), json.at(i-1), json.at(i));
//        qDebug("i=%d", i);
        return false;
    }
    state = ST[state][7];
    return (state==OK);
}

bool Parser::parse()
{
    if (!FSM())
    {
        qDebug("fsm returns false");
        return false;
    }
    int i = 1;
    parsing(parsed, i);
    return true;
}

void Parser::parsing(QVariantMap *map, int &i)
{
    QString name;
    int intValue = 0;
    QString strValue;
    QVariantMap* mapValue;
    while (i<json.size())           // "
    {
        i++;                        // name
        while (json.at(i)!='"')
        {
            name += json.at(i);
            i++;
        }                           // "
        convert(&name);
        i++;                        // :
        i++;                        // " or bool or number or { or null
        switch (json.at(i))
        {
        case '"':
            i++;                    // value or "
            while (json.at(i)!='"')
            {
                strValue += json.at(i);
                i++;
            }                       // "
            i++;                    // , or }
            convert(&strValue);
            map->insert(name, QVariant(strValue));
            strValue.clear();
            name.clear();
            break;
        case 'f':
            i += 5;                 // , or }
            map->insert(name, QVariant(false));
            name.clear();
            break;
        case 't':
            i += 4;                 // , or }
            map->insert(name, QVariant(true));
            name.clear();
            break;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            while (json.at(i)>='0' and json.at(i)<='9')
            {
                intValue *= 10;
                intValue += (int)(json.at(i)-'0');
                i++;
            }                       // , or }
            map->insert(name, QVariant(intValue));
            intValue = 0;
            name.clear();
            break;
        case 'n':
            i += 4;                 // , or }
            name.clear();
            break;
        case '{':
            i++;                    // " or }
            mapValue = new QVariantMap;
            if (json.at(i)!='}')
                parsing(mapValue, i);// , or }
            else
                i++;                // , or }
            map->insert(name, QVariant(*mapValue));
            name.clear();
            break;
        }
        switch (json.at(i))
        {
        case ',':
            i++;                    // "
            break;
        case '}':
            i++;                    // , or }
            return;
            break;
        }
    }
}

void Parser::convert(QString *string)
{
    int i = -1;
    while ((i = string->indexOf("\\u")) != -1)
    {
        int nHex = string->mid(i + 2, 4).toInt(0, 16);
        string->replace(i, 6, QChar(nHex));
    }
}

QVariantMap *Parser::toMap()
{
    return parsed;
}

Parser::~Parser()
{
    delete parsed;
}
