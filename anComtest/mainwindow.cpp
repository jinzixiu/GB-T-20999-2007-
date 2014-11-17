#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "dlgstatus.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    com=new CPubSub();
    nullcom=new CPubSub();
    //setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    ui->opencom->setVisible(true);
    ui->closecom->setVisible(false);
    ui->showchanneltab->setEnabled(false);
    ui->showContrlParm->setEnabled(false);
    ui->showphaseconfli->setEnabled(false);
    ui->showphaseparm->setEnabled(false);
    ui->showphasestatus->setEnabled(false);
    ui->showphasetiming->setEnabled(false);
    ui->showPubParm->setEnabled(false);
    ui->showswitch->setEnabled(false);
    ui->showtimebase->setEnabled(false);
    ui->showtimeinterval->setEnabled(false);
    ui->showtimingplan->setEnabled(false);
    ui->showUnitParm->setEnabled(false);
    ui->showParmRun->setEnabled(false);
    ui->showmodeltab->setEnabled(false);
    ui->showflowphase->setEnabled(false);
    ui->showcartest->setEnabled(false);
    ui->showevent->setEnabled(false);
    ui->status->setEnabled(false);
    ui->pushButton->setFocus();
    ui->comboBox_2->setCurrentIndex(7);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete com;
    delete nullcom;
}

void MainWindow::showthis()
{
    qDebug()<<"hhhhhhhhhhhhhhhhhhhhhhhhhhh";   
}

void MainWindow::on_opencom_clicked()
{
    QString witchcom =ui->comboBox->currentText();
    int i=ui->comboBox_2->currentIndex();
    if(this->com->OpenCom(witchcom,i))
    {        
        ui->opencom->setVisible(false);
        ui->closecom->setVisible(true);
        ui->showchanneltab->setEnabled(true);
        ui->showContrlParm->setEnabled(true);
        ui->showphaseconfli->setEnabled(true);
        ui->showphaseparm->setEnabled(true);
        ui->showphasestatus->setEnabled(true);
        ui->showphasetiming->setEnabled(true);
        ui->showPubParm->setEnabled(true);
        ui->showswitch->setEnabled(true);
        ui->showtimebase->setEnabled(true);
        ui->showtimeinterval->setEnabled(true);
        ui->showtimingplan->setEnabled(true);
        ui->showUnitParm->setEnabled(true);
        ui->showParmRun->setEnabled(true);
        ui->showcartest->setEnabled(true);
        ui->showmodeltab->setEnabled(true);
        ui->showflowphase->setEnabled(true);
         ui->showevent->setEnabled(true);
         ui->status->setEnabled(true);
    }
}

void MainWindow::on_closecom_clicked()
{
    if(this->com->CloseCom())
    {
        ui->opencom->setVisible(true);
        ui->closecom->setVisible(false);

        ui->showchanneltab->setEnabled(false);
        ui->showContrlParm->setEnabled(false);
        ui->showphaseconfli->setEnabled(false);
        ui->showphaseparm->setEnabled(false);
        ui->showphasestatus->setEnabled(false);
        ui->showphasetiming->setEnabled(false);
        ui->showPubParm->setEnabled(false);
        ui->showswitch->setEnabled(false);
        ui->showtimebase->setEnabled(false);
        ui->showtimeinterval->setEnabled(false);
        ui->showtimingplan->setEnabled(false);
        ui->showcartest->setEnabled(false);
        ui->showUnitParm->setEnabled(false);
        ui->showParmRun->setEnabled(false);
        ui->showmodeltab->setEnabled(false);
        ui->showflowphase->setEnabled(false);
         ui->showevent->setEnabled(false);
         ui->status->setEnabled(false);
    }
}

void MainWindow::on_pushButton_clicked()
{
//    this->close();
//    this->~MainWindow();
    emit myquit();
}

void MainWindow::on_showPubParm_clicked()
{
    this->close();
//    //DlgPubParm dlgpubparm;

    dlgpubparm.setcom(this->com);
    dlgpubparm.show();
    dlgpubparm.exec();
    dlgpubparm.setcom(this->nullcom);
//    this->showthis();
    this->show();
}

void MainWindow::on_showtimebase_clicked()
{
    this->close();
    DlgTimeBase dlgtimebase;
    dlgtimebase.setcom(this->com);
    dlgtimebase.show();
    dlgtimebase.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showphaseparm_clicked()
{
    this->close();
    DlgPhaseParm dlgphaseparm;    
    dlgphaseparm.setcom(this->com);
    dlgphaseparm.show();
    dlgphaseparm.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showtimeinterval_clicked()
{
    this->close();
    DlgTimeInterval dlgtimeinterval;
    dlgtimeinterval.setcom(this->com);
    dlgtimeinterval.show();    
    dlgtimeinterval.exec();
    dlgpubparm.setcom(this->nullcom);
    dlgtimeinterval.deleteLater();
    this->show();
}

void MainWindow::on_showchanneltab_clicked()
{
    this->close();
    DialogChanneltab dialogchanneltab;
    dialogchanneltab.setcom(this->com);
    dialogchanneltab.show();
    dialogchanneltab.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showtimingplan_clicked()
{
    this->close();
    DialogTimePlan dlgtimeplan;
    dlgtimeplan.setcom(this->com);
    dlgtimeplan.show();
    dlgtimeplan.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showContrlParm_clicked()
{
    this->close();
    DialogContrlParm dialogcontrlparm;
    dialogcontrlparm.setcom(this->com);
    dialogcontrlparm.show();
    dialogcontrlparm.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showswitch_clicked()
{
    this->close();
    DlgShowSwitch dlgshowswitch;
    dlgshowswitch.setcom(this->com);
    dlgshowswitch.show();
    dlgshowswitch.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showphasetiming_clicked()
{
    this->close();
    DialogPhaseTiming dialogphasetiming;
    dialogphasetiming.setcom(this->com);
    dialogphasetiming.show();
    dialogphasetiming.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showUnitParm_clicked()
{
    this->close();
    DialogUnitParm dialogunitparm;
    dialogunitparm.setcom(this->com);
    dialogunitparm.show();
    dialogunitparm.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showphasestatus_clicked()
{

    this->close();
    DialogPhaseStatus dialogphasestatus;
    dialogphasestatus.setcom(this->com);
    dialogphasestatus.show();
    dialogphasestatus.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showphaseconfli_clicked()
{
    this->close();
    DialogPhaseConflict dialogphaseconflict;
    dialogphaseconflict.setcom(this->com);
    dialogphaseconflict.show();
    dialogphaseconflict.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showParmRun_clicked()
{
    this->close();
    DialogParmRun dialogparmrun;
    dialogparmrun.setcom(this->com);
    dialogparmrun.show();
    dialogparmrun.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showmodeltab_clicked()
{
    this->close();
    DialogModel dialogmodeltab;
    dialogmodeltab.setcom(this->com);
    dialogmodeltab.show();
    dialogmodeltab.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showflowphase_clicked()
{
    this->close();
    DialogFlowPhase dialogflowphase;
    dialogflowphase.setcom(this->com);
    dialogflowphase.show();
    dialogflowphase.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showcartest_clicked()
{
    this->close();
    DialogCarTest dialogcartest;
    dialogcartest.setcom(this->com);
    dialogcartest.show();
    dialogcartest.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_showevent_clicked()
{
    this->close();
    DialogEvent dialogevent;
    dialogevent.setcom(this->com);
    dialogevent.show();
    dialogevent.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();
}

void MainWindow::on_status_clicked()
{
    this->close();
    DlgStatus dlgstatus;
    dlgstatus.setcom(this->com);
    dlgstatus.show();
    dlgstatus.exec();
    dlgpubparm.setcom(this->nullcom);
    this->show();

}
