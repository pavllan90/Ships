#include "blank.h"

Blank::Blank()
{
    printf("\nBasic constructor\n");
    owner.name = "Ekaterina";
    owner.surname = "Volkova";
    name = "Avrora";
    tonnage = 10.6;
    home = "Sankt-Petersburg";
}

Blank::Blank(QString on, QString os, QString n, QString t, QString h)
{
    printf("\nInit constructor\n");
    bool *f  =new bool;
    *f = true;
    t.toFloat(f);
    if(on==""||os==""||n==""||t==""||h=="") *f = false;
    else if(t.toFloat()<=0) *f = false;
    if(*f)
    {
        owner.name = on;
        owner.surname=os;
        name = n;
        tonnage = t.toFloat();
        home = h;
    }
    else
    {
        Blank a;
        owner = a.owner;
        name = a.name;
        tonnage = a.tonnage;
        home = a.home;
    }
}

Blank::Blank(const Blank &a)
{
    printf("\nCopy constructor\n");
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
