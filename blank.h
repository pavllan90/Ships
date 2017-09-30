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
    Blank (QString on, QString os, QString n, QString t, QString h);
    Blank(const Blank &a);
    ~Blank();
    FI owner;
    QString name;
    float tonnage;
    QString home;
    void show();


};

#endif // BLANK_H
