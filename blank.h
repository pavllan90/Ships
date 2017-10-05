#ifndef BLANK_H
#define BLANK_H

#include <QString>
#include <QRegExp>
#include <stdio.h>

struct FI
{
    QString name, surname;
};

class Blank
{
public:
    Blank();
    Blank (QString _oname, QString _osurname, QString _name, QString _tonnage, QString _home);
    Blank(const Blank &a);
    ~Blank();
    void setOwner(FI _owner);
    FI getOwner();
    void setName(QString _name);
    QString getName();
    void setTonnage(QString _tonnage);
    float getTonnage();
    void setHome(QString _home);
    QString getHome();
    void show();
private:
    FI owner;
    QString name;
    float tonnage;
    QString home;
};

#endif // BLANK_H
