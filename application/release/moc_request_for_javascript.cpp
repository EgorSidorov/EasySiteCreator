/****************************************************************************
** Meta object code from reading C++ file 'request_for_javascript.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../request_for_javascript.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'request_for_javascript.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_request_for_javascript_t {
    QByteArrayData data[9];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_request_for_javascript_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_request_for_javascript_t qt_meta_stringdata_request_for_javascript = {
    {
QT_MOC_LITERAL(0, 0, 22), // "request_for_javascript"
QT_MOC_LITERAL(1, 23, 8), // "get_body"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "get_cookie"
QT_MOC_LITERAL(4, 44, 4), // "name"
QT_MOC_LITERAL(5, 49, 13), // "get_parameter"
QT_MOC_LITERAL(6, 63, 10), // "get_header"
QT_MOC_LITERAL(7, 74, 8), // "get_path"
QT_MOC_LITERAL(8, 83, 24) // "get_parameter_byte_array"

    },
    "request_for_javascript\0get_body\0\0"
    "get_cookie\0name\0get_parameter\0get_header\0"
    "get_path\0get_parameter_byte_array"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_request_for_javascript[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x02 /* Public */,
       3,    1,   45,    2, 0x02 /* Public */,
       5,    1,   48,    2, 0x02 /* Public */,
       6,    1,   51,    2, 0x02 /* Public */,
       7,    0,   54,    2, 0x02 /* Public */,
       8,    1,   55,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::QString,
    QMetaType::QByteArray, QMetaType::QString,    4,

       0        // eod
};

void request_for_javascript::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        request_for_javascript *_t = static_cast<request_for_javascript *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->get_body();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->get_cookie((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->get_parameter((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->get_header((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->get_path();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QByteArray _r = _t->get_parameter_byte_array((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject request_for_javascript::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_request_for_javascript.data,
      qt_meta_data_request_for_javascript,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *request_for_javascript::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *request_for_javascript::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_request_for_javascript.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int request_for_javascript::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
