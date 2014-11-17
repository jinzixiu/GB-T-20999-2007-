/****************************************************************************
** Meta object code from reading C++ file 'dialogcontrlparm.h'
**
** Created: Thu Sep 11 12:33:54 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dialogcontrlparm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogcontrlparm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogContrlParm[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      24,   17,   17,   17, 0x08,
      34,   17,   17,   17, 0x08,
      43,   17,   17,   17, 0x08,
      52,   17,   17,   17, 0x08,
      61,   17,   17,   17, 0x08,
      70,   17,   17,   17, 0x08,
      79,   17,   17,   17, 0x08,
      88,   17,   17,   17, 0x08,
      97,   17,   17,   17, 0x08,
     106,   17,   17,   17, 0x08,
     115,   17,   17,   17, 0x08,
     135,  130,   17,   17, 0x08,
     154,   17,   17,   17, 0x08,
     175,   17,   17,   17, 0x08,
     194,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogContrlParm[] = {
    "DialogContrlParm\0\0rev()\0warming()\0"
    "sendb5()\0sendb6()\0sendb7()\0sendb8()\0"
    "sendb9()\0sendba()\0sendbb()\0sendbd()\0"
    "sendcd()\0setCountDown()\0parm\0"
    "sendquerymsg(char)\0on_butfind_clicked()\0"
    "on_butok_clicked()\0on_checkBox_stateChanged(int)\0"
};

const QMetaObject DialogContrlParm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogContrlParm,
      qt_meta_data_DialogContrlParm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogContrlParm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogContrlParm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogContrlParm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogContrlParm))
        return static_cast<void*>(const_cast< DialogContrlParm*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogContrlParm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: sendb5(); break;
        case 3: sendb6(); break;
        case 4: sendb7(); break;
        case 5: sendb8(); break;
        case 6: sendb9(); break;
        case 7: sendba(); break;
        case 8: sendbb(); break;
        case 9: sendbd(); break;
        case 10: sendcd(); break;
        case 11: setCountDown(); break;
        case 12: sendquerymsg((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 13: on_butfind_clicked(); break;
        case 14: on_butok_clicked(); break;
        case 15: on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
