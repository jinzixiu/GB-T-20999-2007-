#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dlgpubparm.h"
#include "dlgtimebase.h"
#include "dlgphaseparm.h"
#include "dlgtimeinterval.h"
#include "dialogchanneltab.h"
#include "dialogtimeplan.h"
#include "dialogcontrlparm.h"
#include "dlgshowswitch.h"
#include "dialogphasetiming.h"
#include "dialogunitparm.h"
#include "dialogphasestatus.h"
#include "dialogphaseconflict.h"
#include "dialogparmrun.h"
#include "dialogmodel.h"
#include "dialogflowphase.h"
#include "dialogcartest.h"
#include "dialogevent.h"


#include <QtGui/QMainWindow>
//#include "win_qextserialport.h"//加入头文件
//#include "serialport.h"
#include "cpubsub.h"
//QT_BEGIN_NAMESPACE_SERIALPORT
//class SerialPort;
//QT_END_NAMESPACE_SERIALPORT

//QT_USE_NAMESPACE_SERIALPORT

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    CPubSub *com;
    CPubSub *nullcom;
    void showthis();
signals:
    void myquit();
private:
    Ui::MainWindow *ui;
    DlgPubParm dlgpubparm;    
private slots:

    void on_opencom_clicked();

    void on_closecom_clicked();

    void on_pushButton_clicked();

    void on_showPubParm_clicked();

    void on_showtimebase_clicked();

    void on_showphaseparm_clicked();

    void on_showtimeinterval_clicked();

    void on_showchanneltab_clicked();

    void on_showtimingplan_clicked();

    void on_showContrlParm_clicked();

    void on_showswitch_clicked();

    void on_showphasetiming_clicked();

    void on_showUnitParm_clicked();

    void on_showphasestatus_clicked();

    void on_showphaseconfli_clicked();

    void on_showParmRun_clicked();

    void on_showmodeltab_clicked();

    void on_showflowphase_clicked();

    void on_showcartest_clicked();

    void on_showevent_clicked();

    void on_status_clicked();

private:


};

#endif // MAINWINDOW_H
