/****************************************************************************
** Meta object code from reading C++ file 'dialogevent.h'
**
** Created: Fri Sep 12 14:15:17 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dialogevent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogevent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogEvent[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
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
      89,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogEvent[] = {
    "DialogEvent\0\0rev()\0warming()\0sendd2()\0"
    "set91()\0on_butfind_clicked()\0"
    "on_butclear_clicked()\0on_butsave_clicked()\0"
};

const QMetaObject DialogEvent::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogEvent,
      qt_meta_data_DialogEvent, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogEvent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogEvent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogEvent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogEvent))
        return static_cast<void*>(const_cast< DialogEvent*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogEvent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: sendd2(); break;
        case 3: set91(); break;
        case 4: on_butfind_clicked(); break;
        case 5: on_butclear_clicked(); break;
        case 6: on_butsave_clicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
