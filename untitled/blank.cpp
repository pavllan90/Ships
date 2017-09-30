#include "blank.h"

Blank::Blank()
{
    owner.name = "Ekaterina";
    owner.surname = "Volkova";
    name = "Avrora";
    tonnage = 10.6;
    home = "Sankt-Petersburg";
}

Blank::Blank(FI o, QString n, float t, QString h)
{
    owner.name = o.name;
    owner.surname=o.surname;
    name = n;
    tonnage = t;
    home = h;
}

Blank::Blank(const Blank &a)
{
    owner = a.owner;
    name = a.name;
    tonnage = a.tonnage;
    home = a.home;
}

Blank::~Blank()
{

}
