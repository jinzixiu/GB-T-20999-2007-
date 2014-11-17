/****************************************************************************
** Meta object code from reading C++ file 'dialogphasetiming.h'
**
** Created: Thu Sep 11 12:33:55 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dialogphasetiming.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogphasetiming.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogPhaseTiming[] = {

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
      19,   18,   18,   18, 0x08,
      25,   18,   18,   18, 0x08,
      35,   18,   18,   18, 0x08,
      53,   18,   18,   18, 0x08,
      70,   18,   18,   18, 0x08,
      91,   18,   18,   18, 0x08,
     110,   18,   18,   18, 0x08,
     132,   18,   18,   18, 0x08,
     157,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogPhaseTiming[] = {
    "DialogPhaseTiming\0\0rev()\0warming()\0"
    "sendPhaseTiming()\0setPhaseTiming()\0"
    "on_butfind_clicked()\0on_butok_clicked()\0"
    "on_butquery_clicked()\0on_butclearall_clicked()\0"
    "on_butclear_clicked()\0"
};

const QMetaObject DialogPhaseTiming::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogPhaseTiming,
      qt_meta_data_DialogPhaseTiming, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogPhaseTiming::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogPhaseTiming::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogPhaseTiming::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogPhaseTiming))
        return static_cast<void*>(const_cast< DialogPhaseTiming*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogPhaseTiming::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: sendPhaseTiming(); break;
        case 3: setPhaseTiming(); break;
        case 4: on_butfind_clicked(); break;
        case 5: on_butok_clicked(); break;
        case 6: on_butquery_clicked(); break;
        case 7: on_butclearall_clicked(); break;
        case 8: on_butclear_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
