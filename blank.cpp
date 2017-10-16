#include "blank.h"

Blank::Blank()
{
    owner.name = "Ekaterina";
    owner.surname = "Volkova";
    name = "Avrora";
    tonnage = 10.6;
    home = "Sankt-Petersburg";
    lineage = 1000;
}

Blank::Blank(QString _oname, QString _osurname, QString _name, float _tonnage, QString _home, float _lineage)
{
    tonnage = _tonnage>0 ? _tonnage : Blank().tonnage;
    owner.name = _oname!="" ? _oname : Blank().owner.name;
    owner.surname = _osurname!="" ? _osurname : Blank().owner.surname;
    name = _name!="" ? _name : Blank().name;
    home = _home!="" ? _home : Blank().home;
    lineage = _lineage > 0 ? _lineage : Blank().lineage;

}

Blank::Blank(const Blank &a)
{
    owner.name = a.owner.name;
    owner.surname = a.owner.surname;
    name = a.name;
    tonnage = a.tonnage;
    home = a.home;
    lineage = a.lineage;
}

void Blank::show()
{
    printf("Owners name: %s\nOwners surname: %s\nShips name: %s\nTonnage: %f\nHome port: %s\n", owner.name.toLatin1().data(), owner.surname.toLatin1().data(), name.toLatin1().data(), tonnage, home.toLatin1().data());
}

Blank::~Blank()
{

}

void Blank::setLineage(float _lineage)
{
    lineage = _lineage > 0 ? _lineage : lineage;
}

float Blank::getLineage()
{
    return lineage;
}

FI Blank::getOwner()
{
    return owner;
}

QString Blank::getName()
{
    return name;
}

float Blank::getTonnage()
{
    return tonnage;
}

QString Blank::getHome()
{
    return home;
}

void Blank::setOwner(FI _owner)
{
    owner.name = (_owner.name!="") ? _owner.name : owner.name;
    owner.surname = (_owner.surname!="") ? _owner.surname : owner.surname;
}

void Blank::setName(QString _name)
{
    name = _name!="" ? _name : name;
}

void Blank::setTonnage(float _tonnage)
{
    tonnage = _tonnage>0 ? _tonnage : tonnage;
}

void Blank::setHome(QString _home)
{
    home = _home!="" ? _home : home;
}
