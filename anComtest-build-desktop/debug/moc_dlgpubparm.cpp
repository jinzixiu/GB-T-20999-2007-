/****************************************************************************
** Meta object code from reading C++ file 'dlgpubparm.h'
**
** Created: Fri Sep 12 14:15:05 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anComtest/dlgpubparm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgpubparm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DlgPubParm[] = {

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
      12,   11,   11,   11, 0x08,
      18,   11,   11,   11, 0x08,
      28,   11,   11,   11, 0x08,
      37,   11,   11,   11, 0x08,
      46,   11,   11,   11, 0x08,
      55,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      73,   11,   11,   11, 0x08,
      82,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     100,   11,   11,   11, 0x08,
     108,   11,   11,   11, 0x08,
     116,   11,   11,   11, 0x08,
     124,   11,   11,   11, 0x08,
     132,   11,   11,   11, 0x08,
     153,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DlgPubParm[] = {
    "DlgPubParm\0\0rev()\0warming()\0send81()\0"
    "send83()\0send84()\0send86()\0send87()\0"
    "send88()\0sendcf()\0sendd3()\0set81()\0"
    "set83()\0set88()\0setcf()\0on_butsend_clicked()\0"
    "on_butchange_clicked()\0"
};

const QMetaObject DlgPubParm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DlgPubParm,
      qt_meta_data_DlgPubParm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DlgPubParm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DlgPubParm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DlgPubParm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DlgPubParm))
        return static_cast<void*>(const_cast< DlgPubParm*>(this));
    return QDialog::qt_metacast(_clname);
}

int DlgPubParm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rev(); break;
        case 1: warming(); break;
        case 2: send81(); break;
        case 3: send83(); break;
        case 4: send84(); break;
        case 5: send86(); break;
        case 6: send87(); break;
        case 7: send88(); break;
        case 8: sendcf(); break;
        case 9: sendd3(); break;
        case 10: set81(); break;
        case 11: set83(); break;
        case 12: set88(); break;
        case 13: setcf(); break;
        case 14: on_butsend_clicked(); break;
        case 15: on_butchange_clicked(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
