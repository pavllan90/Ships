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
    Blank (QString _oname, QString _osurname, QString _name, float _tonnage, QString _home, float _lineage);
    Blank(const Blank &a);
    ~Blank();
    void setOwner(FI _owner);
    FI getOwner();
    void setName(QString _name);
    QString getName();
    void setTonnage(float _tonnage);
    float getTonnage();
    void setHome(QString _home);
    QString getHome();
    void setLineage(float _lineage);
    float getLineage();
    virtual void show();
//    virtual void setFinalDestination(QString _finalDestination);
//    virtual QString getFinalDestination();
//    virtual void setPassengersAmount(int _passengersAmount);
//    virtual int getPassengersAmount();
    virtual int getType();
protected:
    FI owner;
    QString name;
    float tonnage;
    QString home;
    float lineage;
};

#endif // BLANK_H
