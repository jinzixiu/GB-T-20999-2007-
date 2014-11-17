/****************************************************************************
** Meta object code from reading C++ file 'dialogtimeplan.h'
**
** Created: Thu Sep 11 12:33:53 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dialogtimeplan.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogtimeplan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogTimePlan[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      22,   15,   15,   15, 0x08,
      32,   15,   15,   15, 0x08,
      41,   15,   15,   15, 0x08,
      49,   15,   15,   15, 0x08,
      69,   15,   15,   15, 0x08,
      91,   15,   15,   15, 0x08,
     113,   15,   15,   15, 0x08,
     138,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogTimePlan[] = {
    "DialogTimePlan\0\0rev()\0warming()\0"
    "sendc0()\0setc0()\0on_butset_clicked()\0"
    "on_butclear_clicked()\0on_butquery_clicked()\0"
    "on_butclearall_clicked()\0on_butsend_clicked()\0"
};

const QMetaObject DialogTimePlan::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogTimePlan,
      qt_meta_data_DialogTimePlan, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogTimePlan::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogTimePlan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogTimePlan::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogTimePlan))
        return static_cast<void*>(const_cast< DialogTimePlan*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogTimePlan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: sendc0(); break;
        case 3: setc0(); break;
        case 4: on_butset_clicked(); break;
        case 5: on_butclear_clicked(); break;
        case 6: on_butquery_clicked(); break;
        case 7: on_butclearall_clicked(); break;
        case 8: on_butsend_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
