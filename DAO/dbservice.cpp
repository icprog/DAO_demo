#include "dbservice.h"
#include<QtCore>
#include<QSqlQuery>
#include"carinfo_tb.h"
#include"carnumap_tb.h"
#include <QSqlError>
DBService::DBService(const QString& dbName )
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    if(!QFile::exists(dbName))
    {
        qDebug()<<"db "<<dbName<<" is not exists!!";
    }
    database.setDatabaseName(dbName);
}
CarInfo_tb  DBService::getCarInfo_tb(const QString& carName)
{
    CarInfo_tb carInfo;
    if(!database.open())
    {
        qDebug()<<database.lastError();
        carInfo.isValid = false;
        return carInfo;
    }
    else
    {
        QString select_sql("select slm1,slm2 from tb_car_info where car_name=?");
        QSqlQuery sql_query(database);
        sql_query.prepare(select_sql);
        sql_query.addBindValue(carName);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            while(sql_query.next())
            {
                carInfo.carName = carName;
                carInfo.slm1 = sql_query.value(0).toString();
                carInfo.slm2 = sql_query.value(1).toString();
                carInfo.isValid = true;
                break;
            }
        }
    }
    database.close();
    return carInfo;

}
QVector<CarInfo_tb>  DBService::getAllCarInfo_tb()
{
    QVector<CarInfo_tb> carInfos;
    if(!database.open())
    {
        qDebug()<<database.lastError();
        return QVector<CarInfo_tb>();
    }
    else
    {
        QString select_sql("select slm1,slm2,car_name from tb_car_info;");
        QSqlQuery sql_query(database);
        sql_query.prepare(select_sql);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            while(sql_query.next())
            {

                CarInfo_tb carInfo;
                carInfo.slm1 = sql_query.value(0).toString();
                carInfo.slm2 = sql_query.value(1).toString();
                carInfo.carName = sql_query.value(2).toString();
                carInfo.isValid = true;
                carInfos.append(carInfo);
            }
        }
    }
    database.close();
    return carInfos;

}

bool  DBService::updateCarInfo_tb(const CarInfo_tb& carInfo)
{
    bool res = false;
    if(!database.open())
    {
        qDebug()<<database.lastError();
        return res;
    }
    else
    {

        QSqlQuery sql_query(database);
        QString update_sql("update tb_car_info set slm1=?,slm2=? where car_name=?");
        sql_query.prepare(update_sql);
        sql_query.addBindValue(carInfo.slm1);
        sql_query.addBindValue(carInfo.slm2);
        sql_query.addBindValue(carInfo.carName);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"updated!";
            res = true;
        }
    }
    database.close();
    return res;
}

bool  DBService::insertCarInfo_tb(const CarInfo_tb& carInfo)
{
    bool res = false;
    if(!database.open())
    {
        qDebug()<<database.lastError();
        return res;
    }
    else
    {

        QSqlQuery sql_query(database);
        QString update_sql("insert into tb_car_info (slm1,slm2,car_name) values(?,?,?);");
        sql_query.prepare(update_sql);
        sql_query.addBindValue(carInfo.slm1);
        sql_query.addBindValue(carInfo.slm2);
        sql_query.addBindValue(carInfo.carName);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"inserted!";
            res = true;
        }
    }
    database.close();
    return res;
}



CarNuMap_tb  DBService::getCarNuMap_tb(const QString& carName)
{
    CarNuMap_tb carNuMap;
    if(!database.open())
    {
        qDebug()<<database.lastError();
        carNuMap.isValid = false;
        return carNuMap;
    }
    else
    {
        QString select_sql("select car_nu_l,car_nu_g from tb_car_nu_map where car_name=?");
        QSqlQuery sql_query(database);
        sql_query.prepare(select_sql);
        sql_query.addBindValue(carName);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            while(sql_query.next())
            {
                carNuMap.carName = carName;
                carNuMap.car_nu_l = sql_query.value(0).toInt();
                carNuMap.car_nu_g = sql_query.value(1).toInt();
                carNuMap.isValid = true;
                break;
            }
        }
    }
    database.close();

    return carNuMap;

}
QVector<CarNuMap_tb>  DBService::getAllCarNuMap_tb()
{
    QVector<CarNuMap_tb> carNuMaps;
    if(!database.open())
    {
        qDebug()<<database.lastError();
        return QVector<CarNuMap_tb>();
    }
    else
    {
        QString select_sql("select car_nu_l,car_nu_g,car_name from tb_car_nu_map;");
        QSqlQuery sql_query(database);
        sql_query.prepare(select_sql);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            while(sql_query.next())
            {
                CarNuMap_tb carNuMap;

                carNuMap.car_nu_l = sql_query.value(0).toInt();
                carNuMap.car_nu_g = sql_query.value(1).toInt();
                carNuMap.carName = sql_query.value(2).toString();
                carNuMap.isValid = true;
                carNuMaps.append(carNuMap);
            }
        }
    }
    database.close();

    return carNuMaps;

}
bool  DBService::insertCarNuMap_tb(const CarNuMap_tb& carNuMap)
{
    bool res = false;
    if(!database.open())
    {
        qDebug()<<database.lastError();
        return res;
    }
    else
    {

        QSqlQuery sql_query(database);
        QString update_sql("insert into tb_car_nu_map (car_nu_l,car_nu_g,car_name) values(?,?,?);");
        sql_query.prepare(update_sql);
        sql_query.addBindValue(QString::number(carNuMap.car_nu_l));
        sql_query.addBindValue(QString::number(carNuMap.car_nu_g));
        sql_query.addBindValue(carNuMap.carName);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"inserted!";
            res = true;
        }
    }
    database.close();
    return res;
}
bool  DBService::updateCarNuMap_tb(const CarNuMap_tb& carNuMap)
{
    bool res = false;
    if(!database.open())
    {
        qDebug()<<database.lastError();
        return res;
    }
    else
    {

        QSqlQuery sql_query(database);
        QString update_sql("update tb_car_nu_map set car_nu_l=?,car_nu_g=? where car_name=?");
        sql_query.prepare(update_sql);
        sql_query.addBindValue(carNuMap.car_nu_l);
        sql_query.addBindValue(carNuMap.car_nu_g);
        sql_query.addBindValue(carNuMap.carName);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"updated!";
            res = true;
        }
    }
    database.close();
    return res;
}



