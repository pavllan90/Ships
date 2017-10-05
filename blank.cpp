#include "blank.h"

Blank::Blank()
{
    owner.name = "Ekaterina";
    owner.surname = "Volkova";
    name = "Avrora";
    tonnage = 10.6;
    home = "Sankt-Petersburg";
}

Blank::Blank(QString _oname, QString _osurname, QString _name, QString _tonnage, QString _home)
{
    bool *f  =new bool;
    *f = true;
    _tonnage.toFloat(f);
    if(f&&_tonnage.toFloat()<=0) *f = false;
    if(*f)
    {
        tonnage = _tonnage.toFloat();
    }
    else
    {
        tonnage = Blank().tonnage;
    }
    owner.name = _oname!="" ? _oname : Blank().owner.name;
    owner.surname = _osurname!="" ? _osurname : Blank().owner.surname;
    name = _name!="" ? _name : Blank().name;
    home = _home!="" ? _home : Blank().home;

}

Blank::Blank(const Blank &a)
{
    owner = a.owner;
    name = a.name;
    tonnage = a.tonnage;
    home = a.home;
}

void Blank::show()
{
    printf("Owners name: %s\nOwners surname: %s\nShips name: %s\nTonnage: %f\nHome port: %s\n", owner.name.toLatin1().data(), owner.surname.toLatin1().data(), name.toLatin1().data(), tonnage, home.toLatin1().data());
}

Blank::~Blank()
{

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
    name = (_name!="") ? _name : name;
}

void Blank::setTonnage(QString _tonnage)
{
    bool f = true;
    _tonnage.toFloat(&f);
    f = f&(_tonnage.toFloat()>0) ? true :false;
    tonnage = f ? _tonnage.toFloat() : tonnage;
}

void Blank::setHome(QString _home)
{
    home = _home!="" ? _home : home;
}
