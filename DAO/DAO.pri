INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD
QT += sql
HEADERS += \
    DAO/dbservice.h \
    DAO/carnumap_tb.h \
    DAO/carinfo_tb.h \
    DAO/db_dao.h


SOURCES += \
    DAO/dbservice.cpp \
    DAO/carnumap_tb.cpp \
    DAO/carinfo_tb.cpp

