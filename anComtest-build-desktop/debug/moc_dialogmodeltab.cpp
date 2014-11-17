/****************************************************************************
** Meta object code from reading C++ file 'dialogmodeltab.h'
**
** Created: Thu Sep 4 15:24:51 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dialogmodeltab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogmodeltab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogModelTab[] = {

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
      16,   15,   15,   15, 0x08,
      22,   15,   15,   15, 0x08,
      38,   32,   15,   15, 0x08,
      51,   15,   15,   15, 0x08,
      72,   15,   15,   15, 0x08,
      94,   15,   15,   15, 0x08,
     116,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogModelTab[] = {
    "DialogModelTab\0\0rev()\0warming()\0index\0"
    "send85(char)\0on_butfind_clicked()\0"
    "on_butfind2_clicked()\0on_butfind3_clicked()\0"
    "on_butfind4_clicked()\0"
};

const QMetaObject DialogModelTab::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogModelTab,
      qt_meta_data_DialogModelTab, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogModelTab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogModelTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogModelTab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogModelTab))
        return static_cast<void*>(const_cast< DialogModelTab*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogModelTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: send85((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 3: on_butfind_clicked(); break;
        case 4: on_butfind2_clicked(); break;
        case 5: on_butfind3_clicked(); break;
        case 6: on_butfind4_clicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
