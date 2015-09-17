#ifndef CARINFO_TB_H
#define CARINFO_TB_H
#include<QString>
class CarInfo_tb
{

public:
    QString carName;
    QString slm1;
    QString slm2;
    bool isValid;
    CarInfo_tb();
    void print();
};

#endif // CARINFO_TB_H
