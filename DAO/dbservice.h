#ifndef DBSERVICE_H
#define DBSERVICE_H
#include<QSqlDatabase>
class CarInfo_tb;
class CarNuMap_tb;
class DBService
{
    QSqlDatabase database;
public:
    DBService(const QString& dbName);
    CarInfo_tb  getCarInfo_tb(const QString& carName);
    QVector<CarInfo_tb>  getAllCarInfo_tb();
    ///return  : success or failed
    bool  updateCarInfo_tb(const CarInfo_tb& carInfo);
    bool  insertCarInfo_tb(const CarInfo_tb& carInfo);

    CarNuMap_tb  getCarNuMap_tb(const QString& carName);
    QVector<CarNuMap_tb>  getAllCarNuMap_tb();
    bool  updateCarNuMap_tb(const CarNuMap_tb& carNuMap);
    bool  insertCarNuMap_tb(const CarNuMap_tb& carNuMap);
};

#endif // DBSERVICE_H
