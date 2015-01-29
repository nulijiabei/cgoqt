/****************************************************************************
** Meta object code from reading C++ file 'examples.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../examples/examples.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'examples.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Examples[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      24,    9,    9,    9, 0x08,
      38,    9,    9,    9, 0x08,
      58,    9,    9,    9, 0x08,
      79,    9,    9,    9, 0x08,
     102,    9,    9,    9, 0x08,
     122,    9,    9,    9, 0x08,
     145,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Examples[] = {
    "Examples\0\0sendCommand()\0sendMessage()\0"
    "on_quit_triggered()\0on_clear_triggered()\0"
    "on_connect_triggered()\0on_help_triggered()\0"
    "on_disconn_triggered()\0on_network_triggered()\0"
};

void Examples::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Examples *_t = static_cast<Examples *>(_o);
        switch (_id) {
        case 0: _t->sendCommand(); break;
        case 1: _t->sendMessage(); break;
        case 2: _t->on_quit_triggered(); break;
        case 3: _t->on_clear_triggered(); break;
        case 4: _t->on_connect_triggered(); break;
        case 5: _t->on_help_triggered(); break;
        case 6: _t->on_disconn_triggered(); break;
        case 7: _t->on_network_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Examples::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Examples::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Examples,
      qt_meta_data_Examples, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Examples::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Examples::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Examples::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Examples))
        return static_cast<void*>(const_cast< Examples*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Examples::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
