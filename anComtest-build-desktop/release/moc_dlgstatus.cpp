/****************************************************************************
** Meta object code from reading C++ file 'dlgstatus.h'
**
** Created: Fri Sep 12 18:56:50 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dlgstatus.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgstatus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DlgStatus[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      32,   10,   10,   10, 0x08,
      38,   10,   10,   10, 0x08,
      48,   10,   10,   10, 0x08,
      60,   10,   10,   10, 0x08,
      69,   10,   10,   10, 0x08,
      77,   10,   10,   10, 0x08,
      86,   10,   10,   10, 0x08,
     110,   10,   10,   10, 0x08,
     131,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DlgStatus[] = {
    "DlgStatus\0\0on_butinit_clicked()\0rev()\0"
    "warming()\0sendallb0()\0sendd1()\0setd1()\0"
    "sendb1()\0on_pushButton_clicked()\0"
    "on_butquit_clicked()\0on_butfind_clicked()\0"
};

const QMetaObject DlgStatus::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DlgStatus,
      qt_meta_data_DlgStatus, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DlgStatus::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DlgStatus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DlgStatus::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DlgStatus))
        return static_cast<void*>(const_cast< DlgStatus*>(this));
    return QDialog::qt_metacast(_clname);
}

int DlgStatus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_butinit_clicked(); break;
        case 1: rev(); break;
        case 2: warming(); break;
        case 3: sendallb0(); break;
        case 4: sendd1(); break;
        case 5: setd1(); break;
        case 6: sendb1(); break;
        case 7: on_pushButton_clicked(); break;
        case 8: on_butquit_clicked(); break;
        case 9: on_butfind_clicked(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
