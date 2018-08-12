/****************************************************************************
** Meta object code from reading C++ file 'response_for_javascript.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../response_for_javascript.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'response_for_javascript.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_response_for_javascript_t {
    QByteArrayData data[10];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_response_for_javascript_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_response_for_javascript_t qt_meta_stringdata_response_for_javascript = {
    {
QT_MOC_LITERAL(0, 0, 23), // "response_for_javascript"
QT_MOC_LITERAL(1, 24, 10), // "set_cookie"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "name"
QT_MOC_LITERAL(4, 41, 5), // "value"
QT_MOC_LITERAL(5, 47, 6), // "domain"
QT_MOC_LITERAL(6, 54, 8), // "httponly"
QT_MOC_LITERAL(7, 63, 4), // "path"
QT_MOC_LITERAL(8, 68, 6), // "MaxAge"
QT_MOC_LITERAL(9, 75, 10) // "set_header"

    },
    "response_for_javascript\0set_cookie\0\0"
    "name\0value\0domain\0httponly\0path\0MaxAge\0"
    "set_header"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_response_for_javascript[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    6,   39,    2, 0x02 /* Public */,
       1,    5,   52,    2, 0x22 /* Public | MethodCloned */,
       1,    4,   63,    2, 0x22 /* Public | MethodCloned */,
       1,    3,   72,    2, 0x22 /* Public | MethodCloned */,
       9,    2,   79,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Int,    3,    4,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString,    3,    4,    5,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

       0        // eod
};

void response_for_javascript::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        response_for_javascript *_t = static_cast<response_for_javascript *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_cookie((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 1: _t->set_cookie((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 2: _t->set_cookie((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 3: _t->set_cookie((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->set_header((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject response_for_javascript::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_response_for_javascript.data,
      qt_meta_data_response_for_javascript,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *response_for_javascript::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *response_for_javascript::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_response_for_javascript.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int response_for_javascript::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
