#ifndef CARNUMAP_TB_H
#define CARNUMAP_TB_H
#include<QString>
class CarNuMap_tb
{

public:
    QString carName;
    int car_nu_l;
    int car_nu_g;
    bool isValid;
    CarNuMap_tb();
    void print();
};

#endif // CARNUMAP_TB_H
