/****************************************************************************
** Meta object code from reading C++ file 'dlgphaseparm.h'
**
** Created: Fri Sep 12 14:15:07 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dlgphaseparm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgphaseparm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DlgPhaseParm[] = {

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
      14,   13,   13,   13, 0x08,
      20,   13,   13,   13, 0x08,
      30,   13,   13,   13, 0x08,
      39,   13,   13,   13, 0x08,
      47,   13,   13,   13, 0x08,
      68,   13,   13,   13, 0x08,
      87,   13,   13,   13, 0x08,
     109,   13,   13,   13, 0x08,
     131,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DlgPhaseParm[] = {
    "DlgPhaseParm\0\0rev()\0warming()\0send95()\0"
    "set95()\0on_butfind_clicked()\0"
    "on_butok_clicked()\0on_butclear_clicked()\0"
    "on_butquery_clicked()\0on_butclearall_clicked()\0"
};

const QMetaObject DlgPhaseParm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DlgPhaseParm,
      qt_meta_data_DlgPhaseParm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DlgPhaseParm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DlgPhaseParm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DlgPhaseParm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DlgPhaseParm))
        return static_cast<void*>(const_cast< DlgPhaseParm*>(this));
    return QDialog::qt_metacast(_clname);
}

int DlgPhaseParm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: send95(); break;
        case 3: set95(); break;
        case 4: on_butfind_clicked(); break;
        case 5: on_butok_clicked(); break;
        case 6: on_butclear_clicked(); break;
        case 7: on_butquery_clicked(); break;
        case 8: on_butclearall_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
