/****************************************************************************
** Meta object code from reading C++ file 'dialogchanneltab.h'
**
** Created: Thu Sep 11 12:33:53 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dialogchanneltab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogchanneltab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogChanneltab[] = {

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
      18,   17,   17,   17, 0x08,
      24,   17,   17,   17, 0x08,
      34,   17,   17,   17, 0x08,
      43,   17,   17,   17, 0x08,
      51,   17,   17,   17, 0x08,
      72,   17,   17,   17, 0x08,
      91,   17,   17,   17, 0x08,
     114,   17,   17,   17, 0x08,
     136,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogChanneltab[] = {
    "DialogChanneltab\0\0rev()\0warming()\0"
    "sendb0()\0setb0()\0on_butfind_clicked()\0"
    "on_butok_clicked()\0on_butcleaer_clicked()\0"
    "on_butquery_clicked()\0on_butclearall_clicked()\0"
};

const QMetaObject DialogChanneltab::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogChanneltab,
      qt_meta_data_DialogChanneltab, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogChanneltab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogChanneltab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogChanneltab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogChanneltab))
        return static_cast<void*>(const_cast< DialogChanneltab*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogChanneltab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: sendb0(); break;
        case 3: setb0(); break;
        case 4: on_butfind_clicked(); break;
        case 5: on_butok_clicked(); break;
        case 6: on_butcleaer_clicked(); break;
        case 7: on_butquery_clicked(); break;
        case 8: on_butclearall_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
