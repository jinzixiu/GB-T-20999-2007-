/****************************************************************************
** Meta object code from reading C++ file 'dialogphasestatus.h'
**
** Created: Fri Sep 12 14:15:13 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dialogphasestatus.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogphasestatus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogPhaseStatus[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      25,   18,   18,   18, 0x08,
      35,   18,   18,   18, 0x08,
      44,   18,   18,   18, 0x08,
      53,   18,   18,   18, 0x08,
      62,   18,   18,   18, 0x08,
      71,   18,   18,   18, 0x08,
      92,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogPhaseStatus[] = {
    "DialogPhaseStatus\0\0rev()\0warming()\0"
    "sendb1()\0setb96()\0sendd1()\0setbd1()\0"
    "on_butfind_clicked()\0on_butquit_clicked()\0"
};

const QMetaObject DialogPhaseStatus::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogPhaseStatus,
      qt_meta_data_DialogPhaseStatus, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogPhaseStatus::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogPhaseStatus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogPhaseStatus::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogPhaseStatus))
        return static_cast<void*>(const_cast< DialogPhaseStatus*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogPhaseStatus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: sendb1(); break;
        case 3: setb96(); break;
        case 4: sendd1(); break;
        case 5: setbd1(); break;
        case 6: on_butfind_clicked(); break;
        case 7: on_butquit_clicked(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
