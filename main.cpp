//#include <QtCore/QCoreApplication>
#include "db_dao.h"
#include<QDebug>
#include<QApplication>
#include<QtCore>
#include<QtGui>
int main(int argc, char *argv[])
{
    qDebug()<<"11111111111111111111111 ";
    printf("aaaaaaaaaaaaaaaaaaa ");
    QCoreApplication a(argc, argv);

    qDebug()<<"222222222222222222222 ";
    DBService db("db_system_controller.db");
    CarInfo_tb carInfo;
    carInfo.carName = "APN2";

    carInfo.slm1 = "off";
    carInfo.slm2 = "off";
    qDebug()<<"333333333333333333333333 ";
    qDebug()<<"insert res = "<<db.insertCarInfo_tb(carInfo);

    CarNuMap_tb carNuMap;
    carNuMap.carName = "PNP2";

    carNuMap.car_nu_l = 500;
    carNuMap.car_nu_g = 500;
    qDebug()<<"444444444444444444444 ";
    qDebug()<<"insert res = "<<db.insertCarNuMap_tb(carNuMap);
    CarInfo_tb info = db.getCarInfo_tb("APN");
    info.print();
    CarNuMap_tb numap = db.getCarNuMap_tb("PNP");
    numap.print();
    qDebug()<<"5555555555555555555555555555 ";
    QVector<CarInfo_tb> carInfos = db.getAllCarInfo_tb();
    for(int i = 0;i < carInfos.count();i++)
        carInfos[i].print();
    QVector<CarNuMap_tb> carNus = db.getAllCarNuMap_tb();
    for(int i = 0;i < carNus.count();i++)
        carNus[i].print();
    return a.exec();
}
