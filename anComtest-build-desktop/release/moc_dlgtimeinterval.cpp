/****************************************************************************
** Meta object code from reading C++ file 'dlgtimeinterval.h'
**
** Created: Thu Sep 11 12:33:52 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dlgtimeinterval.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgtimeinterval.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DlgTimeInterval[] = {

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
      17,   16,   16,   16, 0x08,
      23,   16,   16,   16, 0x08,
      33,   16,   16,   16, 0x08,
      42,   16,   16,   16, 0x08,
      50,   16,   16,   16, 0x08,
      71,   16,   16,   16, 0x08,
      90,   16,   16,   16, 0x08,
     112,   16,   16,   16, 0x08,
     131,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DlgTimeInterval[] = {
    "DlgTimeInterval\0\0rev()\0warming()\0"
    "send8e()\0set8e()\0on_butfind_clicked()\0"
    "on_butok_clicked()\0on_butclear_clicked()\0"
    "on_query_clicked()\0on_clearall_clicked()\0"
};

const QMetaObject DlgTimeInterval::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DlgTimeInterval,
      qt_meta_data_DlgTimeInterval, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DlgTimeInterval::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DlgTimeInterval::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DlgTimeInterval::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DlgTimeInterval))
        return static_cast<void*>(const_cast< DlgTimeInterval*>(this));
    return QDialog::qt_metacast(_clname);
}

int DlgTimeInterval::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: send8e(); break;
        case 3: set8e(); break;
        case 4: on_butfind_clicked(); break;
        case 5: on_butok_clicked(); break;
        case 6: on_butclear_clicked(); break;
        case 7: on_query_clicked(); break;
        case 8: on_clearall_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
