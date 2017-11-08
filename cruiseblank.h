#ifndef CRUISEBLANK_H
#define CRUISEBLANK_H
#include "blank.h"

class CruiseBlank : public Blank
{
public:
    CruiseBlank();
    CruiseBlank(const CruiseBlank &a);
    CruiseBlank(QString _oname,
                QString _osurname,
                QString _name, float _tonnage,
                QString _home, float _lineage,
                int _passengersAmount,
                QString _finalDestination);
    ~CruiseBlank();
    void setPassengersAmount(int _passengersAmount);
    int getPassengersAmount();
    void setFinalDestination(QString _finalDestination);
    QString getFinalDestination();
    virtual void show();
    virtual int getType();
private:
    int passengersAmount;
    QString finalDestination;
};

#endif // CRUISEBLANK_H
