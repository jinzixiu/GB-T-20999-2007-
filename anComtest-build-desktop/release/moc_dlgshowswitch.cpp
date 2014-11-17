/****************************************************************************
** Meta object code from reading C++ file 'dlgshowswitch.h'
**
** Created: Thu Sep 11 14:18:26 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dlgshowswitch.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgshowswitch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DlgShowSwitch[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      21,   14,   14,   14, 0x08,
      31,   14,   14,   14, 0x08,
      40,   14,   14,   14, 0x08,
      49,   14,   14,   14, 0x08,
      57,   14,   14,   14, 0x08,
      65,   14,   14,   14, 0x08,
      86,   14,   14,   14, 0x08,
     105,   14,   14,   14, 0x08,
     133,   14,   14,   14, 0x08,
     161,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DlgShowSwitch[] = {
    "DlgShowSwitch\0\0rev()\0warming()\0sendcc()\0"
    "sendcb()\0setcc()\0setcb()\0on_butfind_clicked()\0"
    "on_butok_clicked()\0on_checkr_stateChanged(int)\0"
    "on_checky_stateChanged(int)\0"
    "on_checkg_stateChanged(int)\0"
};

const QMetaObject DlgShowSwitch::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DlgShowSwitch,
      qt_meta_data_DlgShowSwitch, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DlgShowSwitch::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DlgShowSwitch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DlgShowSwitch::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DlgShowSwitch))
        return static_cast<void*>(const_cast< DlgShowSwitch*>(this));
    return QDialog::qt_metacast(_clname);
}

int DlgShowSwitch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: sendcc(); break;
        case 3: sendcb(); break;
        case 4: setcc(); break;
        case 5: setcb(); break;
        case 6: on_butfind_clicked(); break;
        case 7: on_butok_clicked(); break;
        case 8: on_checkr_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: on_checky_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: on_checkg_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
