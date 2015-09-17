#include "carinfo_tb.h"
#include<QDebug>
CarInfo_tb::CarInfo_tb()
{
    isValid = true;
}

void CarInfo_tb::print()
{
    qDebug()<<"carName  : "<<carName;
    qDebug()<<"slm1     : "<<slm1;
    qDebug()<<"slm2     : "<<slm2;
    qDebug()<<"isValid  : "<<isValid;
}
