#ifndef BLANK_H
#define BLANK_H

#include <QString>

struct FI
{
    QString name, surname;
};

class Blank
{
public:
    Blank();
    Blank (FI o, QString n, float t, QString h);
    Blank(const Blank &a);
    ~Blank();
private:
    FI owner;
    QString name;
    float tonnage;
    QString home;


};

#endif // BLANK_H
