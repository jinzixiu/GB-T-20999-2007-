#ifndef APPCONFIG_H
#define APPCONFIG_H
#include <QString>
#include <QSettings>

//const int g_nVersion = 1 ;
//const int g_nVersion = 3 ;//对应版本v2.0.0
//const int g_nVersion = 4 ; //对应版本v2.0.1
//const int g_nVersion = 5 ; //对应版本v2.0.1-v2.0.3
//const int g_nVersion = 6 ; //对应版本v2.0.4-V2.11
const int g_nVersion = 7 ; //对应版本v2.1.2

class Appconfig
{
public:
    Appconfig();

    static void writeConfig(QString configName);
    static void readConfig(QString configName);

    static QString stationName(){return m_stationname;}
    static void setStationName(QString is){ m_stationname = is ;}

    static QString officeName(){return m_officename;}
    static void setOfficeName(QString is){ m_officename = is ;}

    static QString stationId(){return m_stationid;}
    static void setStationId(QString is){ m_stationid = is ;}

    static QString controllerIp(){return m_controllerip;}
    static void setControllerIp(QString is){ m_controllerip = is ;}

    static QString controllerPort(){return m_controllerport;}
    static void setControllerPort(QString is){ m_controllerport = is ;}

    static QString hostStationIp(){return m_hoststationip;}
    static void setHostStationIp(QString is){ m_hoststationip = is ;}

    static QString hostStationPort(){return m_hoststationport;}
    static void setHostStationPort(QString is){ m_hoststationport = is ;}

    static QString hostStationId(){return m_hoststationid;}
    static void setHostStationId(QString is){ m_hoststationid = is ;}

    static QString servicePort(){return m_serviceport;}
    static void setServicePort(QString is){ m_serviceport = is ;}

    static bool isUseBorrow(){return m_isuseborrow;}
    static void setIsUseBorrow(bool is){ m_isuseborrow = is ;}

//    static bool isAutoRun(){return m_isautorun;}
//    static void setIsAutoRun(bool is){ m_isautorun = is ;}

    static bool isAutoCheck(){return m_isautocheck;}
    static void setIsAutoCheck(bool is){ m_isautocheck = is ;}

    static QString checkWarning(){return m_checkwarning;}
    static void setCheckWarning(QString is){ m_checkwarning = is ;}

    static QString checkTime(){return m_checktime;}
    static void setCheckTime(QString is){ m_checktime = is ;}

    static QString checkBeforeDay(){return m_checkbeforeday;}
    static void setCheckBeforeDay(QString is){ m_checkbeforeday = is ;}

    static bool isAddTestData(){return m_isAddTestData;}
    static void setIsAddTestData(bool is){m_isAddTestData = is;}

    static QString graphPort(){return m_graphport;}
    static void setGraphPort(QString is){ m_graphport = is ;}

    static int version() { return  m_nVersion; }
    static void setVersion( int nVersion ){ m_nVersion = nVersion ; }

    static bool reportToWFType(){return m_reportToWFType;}
    static void setReportToWFType(bool is){m_reportToWFType = is;}

    static bool isAutoAssign(){ return m_bIsAutoAssign;}
    static void setAutoAssign(bool is){ m_bIsAutoAssign = is;}

    static bool isMustReg(){ return m_bMustReg;}
    static void setMustReg(bool is){ m_bMustReg = is;}

    static QString webserviceIp(){return m_webip;}
    static void setWebserviceIp(QString is){ m_webip = is ;}

    static QString webservicePort(){return m_webport;}
    static void setWebservicePort(QString is){ m_webport = is ;}

    static bool isUseWeb(){ return m_isuseweb;}
    static void setIsUseWeb(bool is){ m_isuseweb = is;}

    static QString a2dSerialportName() { return m_a2dSerialportName; }
    static void setA2dSerialportName(QString name) { m_a2dSerialportName = name; }

private:
    static QString m_stationname;  //站名
    static QString m_officename;  //局名
    static QString m_stationid;    //站号

    static QString m_controllerip;  //控制器IP
    static QString m_controllerport;    //控制器端口号
    static bool m_isautorun;        //是否自动运行连接

    static bool m_isuseborrow;  //是否启用借用
    static QString m_hoststationip;     //主站IP
    static QString m_hoststationport; // 主站端口号
    static QString m_hoststationid;  // 主站站号
    static QString m_serviceport;  // 服务端口号

    static bool m_isautocheck;  //是否自动提示送检
    static QString m_checkwarning;  // 送检警示时长
    static QString m_checktime;  // 每天送检提示时间
    static QString m_checkbeforeday;  // 送检提前天数

    static QString m_graphport;  //五防端口

    static bool m_isAddTestData;     //是否添加测试数据

    static int m_nVersion;
    static bool m_reportToWFType;  //用于借用票向图形汇报 true：全解锁 、 false：全取走

    static bool m_bIsAutoAssign; //是否自动分配地线列表
    static bool m_bMustReg; //借用地线是否需要注册后方能使用

    static QString m_webip; //webservice地址
    static QString m_webport;//webservice端口
    static bool m_isuseweb; //是否启用webservice
    static QString m_a2dSerialportName;
};

#endif // APPCONFIG_H
