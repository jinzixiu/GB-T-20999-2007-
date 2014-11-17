#include "appconfig.h"

#include <QDebug>

QString Appconfig::m_stationname = QObject::tr("备用站");  //站名
QString Appconfig::m_officename = QObject::tr("YUAN");  //局名
QString Appconfig::m_stationid = QObject::tr("1");    //站号
QString Appconfig::m_controllerip = QObject::tr("192.168.1.1");  //控制器IP
QString Appconfig::m_controllerport = QObject::tr("4001");    //控制器端口号
//bool    Appconfig::m_isautorun = false; //是否自动连接
bool    Appconfig::m_isuseborrow = true;  //是否启用借用
QString Appconfig::m_hoststationip = QObject::tr("192.168.2.1");     //主站IP
QString Appconfig::m_hoststationport = QObject::tr("3002"); // 主站端口号
QString Appconfig::m_hoststationid = QObject::tr("hs0001");  // 主站站号
QString Appconfig::m_serviceport = QObject::tr("3333");  // 服务端口号
bool    Appconfig::m_isautocheck = true;  //是否自动提示送检
QString Appconfig::m_checkwarning = QObject::tr("0");  // 送检警示时长
QString Appconfig::m_checktime = QObject::tr("10:30:30");  // 每天送检提示时间
QString Appconfig::m_checkbeforeday =QObject::tr("30");  // 送检提前天数
//bool Appconfig::m_isusegraph = true;     //是否启用五防通讯
QString Appconfig::m_graphport = QObject::tr("5555");   //五防端口
bool Appconfig::m_isAddTestData = false;     //是否添加测试数据 true == 添加
int  Appconfig::m_nVersion = -1 ;
bool Appconfig::m_reportToWFType = false;

bool Appconfig::m_bIsAutoAssign = false;
bool Appconfig::m_bMustReg = false;

QString Appconfig::m_webip = "localhost";
QString Appconfig::m_webport = "1960";
bool Appconfig::m_isuseweb = true;

QString Appconfig::m_a2dSerialportName = "COM1";

Appconfig::Appconfig()
{
}

void Appconfig::writeConfig(QString configName)
{
    QSettings *writeConfig = new QSettings(configName,QSettings::IniFormat);
    if(writeConfig)
    {
        writeConfig->remove ("STATION");
        writeConfig->remove ("CONTROLLER");
        writeConfig->remove ("USEBORROW");
        writeConfig->remove ("CHECKDX");
        writeConfig->remove ("GRAPH");
        writeConfig->remove ("REPORTTOWFTYPE");
        writeConfig->remove ("WEBSERVICE");
        writeConfig->remove ("A2D");
//        writeConfig->remove ("APPLICATION");

        writeConfig->beginGroup("STATION");
        writeConfig->setValue("officeName", Appconfig::officeName ());
        writeConfig->setValue("stationName", Appconfig::stationName ());
        writeConfig->setValue("stationid", Appconfig::stationId ());
        writeConfig->endGroup();

        writeConfig->beginGroup ("CONTROLLER");
        writeConfig->setValue ("controllerip",Appconfig::controllerIp ());
        writeConfig->setValue ("controllerport",Appconfig::controllerPort ());
//        writeConfig->setValue ("isautorun",Appconfig::isAutoRun ());
        writeConfig->endGroup ();


        writeConfig->beginGroup ("USEBORROW");
        writeConfig->setValue ("isuseborrow",Appconfig::isUseBorrow ());
        writeConfig->setValue ("hoststationip",Appconfig::hostStationIp ());
        writeConfig->setValue ("hoststationport",Appconfig::hostStationPort ());
        writeConfig->setValue ("hoststationid",Appconfig::hostStationId ());
        writeConfig->endGroup ();

        if(Appconfig::isUseBorrow ())
        {
            writeConfig->remove ("USEBORROW");
            writeConfig->beginGroup ("USEBORROW");
            writeConfig->setValue ("isuseborrow",Appconfig::isUseBorrow ());
            writeConfig->setValue ("serviceport",Appconfig::servicePort ());
            writeConfig->endGroup ();
        }

        writeConfig->beginGroup ("CHECKDX");
        writeConfig->setValue ("isautocheck",Appconfig::isAutoCheck ());
        writeConfig->setValue ("checkwarning",Appconfig::checkWarning ());
        writeConfig->setValue ("checktime",Appconfig::checkTime ());
        writeConfig->setValue ("checkbeforeday",Appconfig::checkBeforeDay ());
        writeConfig->endGroup ();

        writeConfig->beginGroup ("GRAPH");
//        writeConfig->setValue ("isusegraph",Appconfig::isUseGraph ());
//        writeConfig->setValue ("graphip",Appconfig::graphIp ());
        writeConfig->setValue ("graphport",Appconfig::graphPort ());
        writeConfig->endGroup ();

        writeConfig->beginGroup ("REPORTTOWFTYPE");
//        writeConfig->setValue ("type",Appconfig::reportToWFType ());
        writeConfig->setValue ("type",true);
        writeConfig->endGroup ();

        //add by : v2.0.1
        writeConfig->beginGroup("ISAUTOASSIGN");
        writeConfig->setValue("autoAssign" , Appconfig::isAutoAssign());
        writeConfig->endGroup();

        writeConfig->beginGroup("ISMUSTREG");
        writeConfig->setValue("mustReg" , Appconfig::isMustReg());
        writeConfig->endGroup();
        //add end : v2.0.1

//        if(!Appconfig::isUseGraph ())
//        {
//            writeConfig->remove ("GRAPH");
//            writeConfig->beginGroup ("GRAPH");
//            writeConfig->setValue ("isusegraph",Appconfig::isUseGraph ());
//            writeConfig->endGroup ();
//        }

//        writeConfig->beginGroup ("APPLICATION");
//        writeConfig->setValue ("isserver",Appconfig::isServer ());
//        writeConfig->endGroup ();

        writeConfig->beginGroup("WEBSERVICE");
        writeConfig->setValue("isuseweb",Appconfig::isUseWeb());
        writeConfig->setValue("webip",Appconfig::webserviceIp());
        writeConfig->setValue("webport",Appconfig::webservicePort());
        writeConfig->endGroup();

        writeConfig->beginGroup("A2D");
        writeConfig->setValue("SerialportName" , Appconfig::m_a2dSerialportName);
        writeConfig->endGroup();

        delete writeConfig;
    }
}

void Appconfig::readConfig(QString configName)
{
    QSettings *readConfig = new QSettings(configName,QSettings::IniFormat);
    if(readConfig)
    {
        QString m_stationname = readConfig->value ("STATION/officeName").toString ();
        if(m_stationname.isEmpty ())
            qDebug ()<< "000000";
        QString m_officename =readConfig->value ("STATION/stationName").toString ();
        QString m_stationid =readConfig->value ("STATION/stationid").toString ();

        QString m_controllerip =readConfig->value ("CONTROLLER/controllerip").toString ();
        QString m_controllerport =readConfig->value ("CONTROLLER/controllerport").toString ();
//        bool m_isautorun = readConfig->value ("CONTROLLER/isautorun").toBool ();

        Appconfig::setStationName (m_stationname);
        Appconfig::setOfficeName (m_officename);
        Appconfig::setStationId (m_stationid);

        Appconfig::setControllerIp (m_controllerip);
        Appconfig::setControllerPort (m_controllerport);
//        Appconfig::setIsAutoRun (m_isautorun);

        bool m_isuseborrow =readConfig->value ("USEBORROW/isuseborrow").toBool ();

        Appconfig::setIsUseBorrow (m_isuseborrow);

        if(!m_isuseborrow)
        {
            QString m_hoststationip =readConfig->value ("USEBORROW/hoststationip").toString ();
            QString m_hoststationport =readConfig->value ("USEBORROW/hoststationport").toString ();
            QString m_hoststationid =readConfig->value ("USEBORROW/hoststationid").toString ();

            Appconfig::setHostStationIp (m_hoststationip);
            Appconfig::setHostStationId (m_hoststationid);
            Appconfig::setHostStationPort (m_hoststationport);
            Appconfig::setServicePort ("");
        }
         else
        {
            QString m_serviceport =readConfig->value ("USEBORROW/serviceport").toString ();

            Appconfig::setHostStationIp ("");
            Appconfig::setHostStationId ("");
            Appconfig::setHostStationPort ("");
            Appconfig::setServicePort (m_serviceport);
        }

        bool m_isautocheck = readConfig->value ("CHECKDX/isautocheck").toBool ();
        QString m_checkwarning = readConfig->value ("CHECKDX/checkwarning").toString ();
        QString m_checktime = readConfig->value ("CHECKDX/checktime").toString ();
        QString m_checkbeforeday = readConfig->value ("CHECKDX/checkbeforeday").toString ();

        Appconfig::setIsAutoCheck (m_isautocheck);
        Appconfig::setCheckWarning (m_checkwarning);
        Appconfig::setCheckTime (m_checktime);
        Appconfig::setCheckBeforeDay (m_checkbeforeday);

//        bool m_isusegraph = readConfig->value ("GRAPH/isusegraph").toBool ();
//        if(m_isusegraph)
//        {
//            QString m_graphip = readConfig->value ("GRAPH/graphip").toString ();
            QString m_graphport = readConfig->value ("GRAPH/graphport").toString ();

//            Appconfig::setIsUseGraph (m_isusegraph);
//            Appconfig::setGraphIp (m_graphip);
            Appconfig::setGraphPort (m_graphport);
//        }
//        else
//        {
//            Appconfig::setIsUseGraph (m_isusegraph);
////            Appconfig::setGraphIp ("");
//            Appconfig::setGraphPort ("");
//        }

//            bool m_isServer = readConfig->value ("APPLICATION/isserver").toBool ();
//            Appconfig::setIsServer (m_isServer);
        //bool type = readConfig->value ("REPORTTOWFTYPE/type",true).toBool ();
//        Appconfig::setReportToWFType (type);
        Appconfig::setReportToWFType (true);

        bool bIsAutoAssign = true;
        bIsAutoAssign = readConfig->value ("ISAUTOASSIGN/autoAssign" , true).toBool();
        Appconfig::setAutoAssign(bIsAutoAssign);

        bool bIsMustReg = false;
        bIsMustReg = readConfig->value ("ISMUSTREG/mustReg" , false).toBool();
        Appconfig::setMustReg(bIsMustReg);

        bool isuseweb = readConfig->value("WEBSERVICE/isuseweb").toBool();
        QString webip = readConfig->value("WEBSERVICE/webip").toString();
        QString webport = readConfig->value("WEBSERVICE/webport").toString();

        Appconfig::setIsUseWeb(isuseweb);
        Appconfig::setWebserviceIp(webip);
        Appconfig::setWebservicePort(webport);

        Appconfig::m_a2dSerialportName = readConfig->value("A2D/SerialportName").toString();

        delete readConfig;
    }
}
