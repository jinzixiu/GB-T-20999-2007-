/****************************************************************************
** Meta object code from reading C++ file 'dialogunitparm.h'
**
** Created: Fri Sep 12 14:15:12 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dialogunitparm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogunitparm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogUnitParm[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
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
      50,   15,   15,   15, 0x08,
      59,   15,   15,   15, 0x08,
      68,   15,   15,   15, 0x08,
      77,   15,   15,   15, 0x08,
      86,   15,   15,   15, 0x08,
      95,   15,   15,   15, 0x08,
     104,   15,   15,   15, 0x08,
     113,   15,   15,   15, 0x08,
     121,   15,   15,   15, 0x08,
     129,   15,   15,   15, 0x08,
     137,   15,   15,   15, 0x08,
     145,   15,   15,   15, 0x08,
     153,   15,   15,   15, 0x08,
     161,   15,   15,   15, 0x08,
     182,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogUnitParm[] = {
    "DialogUnitParm\0\0rev()\0warming()\0"
    "senda3()\0senda4()\0senda5()\0senda6()\0"
    "senda8()\0senda7()\0sendab()\0sendaa()\0"
    "senda9()\0seta3()\0seta4()\0seta5()\0"
    "seta6()\0setaa()\0setab()\0on_butfind_clicked()\0"
    "on_butok_clicked()\0"
};

const QMetaObject DialogUnitParm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogUnitParm,
      qt_meta_data_DialogUnitParm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogUnitParm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogUnitParm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogUnitParm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogUnitParm))
        return static_cast<void*>(const_cast< DialogUnitParm*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogUnitParm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: senda3(); break;
        case 3: senda4(); break;
        case 4: senda5(); break;
        case 5: senda6(); break;
        case 6: senda8(); break;
        case 7: senda7(); break;
        case 8: sendab(); break;
        case 9: sendaa(); break;
        case 10: senda9(); break;
        case 11: seta3(); break;
        case 12: seta4(); break;
        case 13: seta5(); break;
        case 14: seta6(); break;
        case 15: setaa(); break;
        case 16: setab(); break;
        case 17: on_butfind_clicked(); break;
        case 18: on_butok_clicked(); break;
        default: ;
        }
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
