#include "cruiseblank.h"

CruiseBlank::CruiseBlank() : Blank(), finalDestination("Boston"), passengersAmount(3500) { }

CruiseBlank::CruiseBlank(QString _oname,
                         QString _osurname,
                         QString _name,
                         float _tonnage,
                         QString _home,
                         float _lineage,
                         int _passengersAmount,
                         QString _finalDestination) : Blank(_oname, _osurname, _name, _tonnage, _home, _lineage)
{
    passengersAmount = _passengersAmount>=0 ? _passengersAmount : CruiseBlank().passengersAmount;
    finalDestination = _finalDestination!="" ? _finalDestination : CruiseBlank().finalDestination;
}

CruiseBlank::CruiseBlank(const CruiseBlank &a) : Blank(a), finalDestination(a.finalDestination), passengersAmount(a.passengersAmount) { }

CruiseBlank::~CruiseBlank() { }

void CruiseBlank::setFinalDestination(QString _finalDestination)
{
    finalDestination = _finalDestination != "" ? _finalDestination : finalDestination;
}

QString CruiseBlank::getFinalDestination()
{
    return finalDestination;
}

int CruiseBlank::getType()
{
    return 1;
}

void CruiseBlank::setPassengersAmount(int _passengersAmount)
{
    passengersAmount = _passengersAmount>0 ? _passengersAmount : passengersAmount;
}

int CruiseBlank::getPassengersAmount()
{
    return passengersAmount;
}

void CruiseBlank::show()
{
    printf("Owners name: %s\nOwners surname: %s\nShips name: %s\nTonnage: %f\nHome port: %s\nLineage: %f\nPassengers amount: %d\nFinal destination: %s\n", owner.name.toLatin1().data(), owner.surname.toLatin1().data(), name.toLatin1().data(), tonnage, home.toLatin1().data(), lineage, passengersAmount, finalDestination.toLatin1().data());
}
