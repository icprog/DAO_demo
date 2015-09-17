#include "carnumap_tb.h"
#include <QDebug>
CarNuMap_tb::CarNuMap_tb()
{
    isValid = true;
}
void CarNuMap_tb::print()
{
    qDebug()<<"carName  : "<<carName;
    qDebug()<<"car_nu_l     : "<<car_nu_l;
    qDebug()<<"car_nu_g     : "<<car_nu_g;
    qDebug()<<"isValid  : "<<isValid;
}
