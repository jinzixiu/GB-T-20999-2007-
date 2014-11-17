/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Sep 13 18:44:12 2014
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
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      21,   11,   11,   11, 0x08,
      42,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      88,   11,   11,   11, 0x08,
     113,   11,   11,   11, 0x08,
     139,   11,   11,   11, 0x08,
     166,   11,   11,   11, 0x08,
     196,   11,   11,   11, 0x08,
     224,   11,   11,   11, 0x08,
     252,   11,   11,   11, 0x08,
     280,   11,   11,   11, 0x08,
     304,   11,   11,   11, 0x08,
     333,   11,   11,   11, 0x08,
     359,   11,   11,   11, 0x08,
     388,   11,   11,   11, 0x08,
     417,   11,   11,   11, 0x08,
     442,   11,   11,   11, 0x08,
     468,   11,   11,   11, 0x08,
     495,   11,   11,   11, 0x08,
     520,   11,   11,   11, 0x08,
     543,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0myquit()\0on_opencom_clicked()\0"
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
        case 0: myquit(); break;
        case 1: on_opencom_clicked(); break;
        case 2: on_closecom_clicked(); break;
        case 3: on_pushButton_clicked(); break;
        case 4: on_showPubParm_clicked(); break;
        case 5: on_showtimebase_clicked(); break;
        case 6: on_showphaseparm_clicked(); break;
        case 7: on_showtimeinterval_clicked(); break;
        case 8: on_showchanneltab_clicked(); break;
        case 9: on_showtimingplan_clicked(); break;
        case 10: on_showContrlParm_clicked(); break;
        case 11: on_showswitch_clicked(); break;
        case 12: on_showphasetiming_clicked(); break;
        case 13: on_showUnitParm_clicked(); break;
        case 14: on_showphasestatus_clicked(); break;
        case 15: on_showphaseconfli_clicked(); break;
        case 16: on_showParmRun_clicked(); break;
        case 17: on_showmodeltab_clicked(); break;
        case 18: on_showflowphase_clicked(); break;
        case 19: on_showcartest_clicked(); break;
        case 20: on_showevent_clicked(); break;
        case 21: on_status_clicked(); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::myquit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
