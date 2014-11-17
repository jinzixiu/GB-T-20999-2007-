/****************************************************************************
** Meta object code from reading C++ file 'dlgtimebase.h'
**
** Created: Fri Sep 12 14:15:06 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dlgtimebase.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgtimebase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DlgTimeBase[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      19,   12,   12,   12, 0x08,
      29,   12,   12,   12, 0x08,
      38,   12,   12,   12, 0x08,
      46,   12,   12,   12, 0x08,
      67,   12,   12,   12, 0x08,
      87,   12,   12,   12, 0x08,
     109,   12,   12,   12, 0x08,
     146,   12,   12,   12, 0x08,
     184,   12,   12,   12, 0x08,
     221,   12,   12,   12, 0x08,
     243,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DlgTimeBase[] = {
    "DlgTimeBase\0\0rev()\0warming()\0send8d()\0"
    "set8d()\0on_butfind_clicked()\0"
    "on_butset_clicked()\0on_bufclear_clicked()\0"
    "on_checkBoxifofmon_stateChanged(int)\0"
    "on_checkBoxifofweek_stateChanged(int)\0"
    "on_checkBoxifofday_stateChanged(int)\0"
    "on_butquery_clicked()\0on_butclearall_clicked()\0"
};

const QMetaObject DlgTimeBase::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DlgTimeBase,
      qt_meta_data_DlgTimeBase, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DlgTimeBase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DlgTimeBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DlgTimeBase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DlgTimeBase))
        return static_cast<void*>(const_cast< DlgTimeBase*>(this));
    return QDialog::qt_metacast(_clname);
}

int DlgTimeBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: send8d(); break;
        case 3: set8d(); break;
        case 4: on_butfind_clicked(); break;
        case 5: on_butset_clicked(); break;
        case 6: on_bufclear_clicked(); break;
        case 7: on_checkBoxifofmon_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_checkBoxifofweek_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: on_checkBoxifofday_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: on_butquery_clicked(); break;
        case 11: on_butclearall_clicked(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
