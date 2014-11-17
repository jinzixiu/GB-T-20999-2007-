/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Sep 13 13:15:46 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      33,   11,   11,   11, 0x08,
      55,   11,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     130,   11,   11,   11, 0x08,
     157,   11,   11,   11, 0x08,
     187,   11,   11,   11, 0x08,
     215,   11,   11,   11, 0x08,
     243,   11,   11,   11, 0x08,
     271,   11,   11,   11, 0x08,
     295,   11,   11,   11, 0x08,
     324,   11,   11,   11, 0x08,
     350,   11,   11,   11, 0x08,
     379,   11,   11,   11, 0x08,
     408,   11,   11,   11, 0x08,
     433,   11,   11,   11, 0x08,
     459,   11,   11,   11, 0x08,
     486,   11,   11,   11, 0x08,
     511,   11,   11,   11, 0x08,
     534,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_opencom_clicked()\0"
    "on_closecom_clicked()\0on_pushButton_clicked()\0"
    "on_showPubParm_clicked()\0"
    "on_showtimebase_clicked()\0"
    "on_showphaseparm_clicked()\0"
    "on_showtimeinterval_clicked()\0"
    "on_showchanneltab_clicked()\0"
    "on_showtimingplan_clicked()\0"
    "on_showContrlParm_clicked()\0"
    "on_showswitch_clicked()\0"
    "on_showphasetiming_clicked()\0"
    "on_showUnitParm_clicked()\0"
    "on_showphasestatus_clicked()\0"
    "on_showphaseconfli_clicked()\0"
    "on_showParmRun_clicked()\0"
    "on_showmodeltab_clicked()\0"
    "on_showflowphase_clicked()\0"
    "on_showcartest_clicked()\0"
    "on_showevent_clicked()\0on_status_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_opencom_clicked(); break;
        case 1: on_closecom_clicked(); break;
        case 2: on_pushButton_clicked(); break;
        case 3: on_showPubParm_clicked(); break;
        case 4: on_showtimebase_clicked(); break;
        case 5: on_showphaseparm_clicked(); break;
        case 6: on_showtimeinterval_clicked(); break;
        case 7: on_showchanneltab_clicked(); break;
        case 8: on_showtimingplan_clicked(); break;
        case 9: on_showContrlParm_clicked(); break;
        case 10: on_showswitch_clicked(); break;
        case 11: on_showphasetiming_clicked(); break;
        case 12: on_showUnitParm_clicked(); break;
        case 13: on_showphasestatus_clicked(); break;
        case 14: on_showphaseconfli_clicked(); break;
        case 15: on_showParmRun_clicked(); break;
        case 16: on_showmodeltab_clicked(); break;
        case 17: on_showflowphase_clicked(); break;
        case 18: on_showcartest_clicked(); break;
        case 19: on_showevent_clicked(); break;
        case 20: on_status_clicked(); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
