/****************************************************************************
** Meta object code from reading C++ file 'database_for_javascript.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../database_for_javascript.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database_for_javascript.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_database_for_javascript_t {
    QByteArrayData data[10];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_database_for_javascript_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_database_for_javascript_t qt_meta_stringdata_database_for_javascript = {
    {
QT_MOC_LITERAL(0, 0, 23), // "database_for_javascript"
QT_MOC_LITERAL(1, 24, 13), // "string_answer"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 10), // "db_request"
QT_MOC_LITERAL(4, 50, 17), // "qbytearray_answer"
QT_MOC_LITERAL(5, 68, 9), // "no_answer"
QT_MOC_LITERAL(6, 78, 8), // "set_file"
QT_MOC_LITERAL(7, 87, 14), // "bind_name_file"
QT_MOC_LITERAL(8, 102, 4), // "file"
QT_MOC_LITERAL(9, 107, 17) // "stringlist_answer"

    },
    "database_for_javascript\0string_answer\0"
    "\0db_request\0qbytearray_answer\0no_answer\0"
    "set_file\0bind_name_file\0file\0"
    "stringlist_answer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_database_for_javascript[] = {

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
       1,    1,   39,    2, 0x02 /* Public */,
       4,    1,   42,    2, 0x02 /* Public */,
       5,    1,   45,    2, 0x02 /* Public */,
       6,    3,   48,    2, 0x02 /* Public */,
       9,    1,   55,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QString, QMetaType::QString,    3,
    QMetaType::QByteArray, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QByteArray,    3,    7,    8,
    QMetaType::QStringList, QMetaType::QString,    3,

       0        // eod
};

void database_for_javascript::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        database_for_javascript *_t = static_cast<database_for_javascript *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->string_answer((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { QByteArray _r = _t->qbytearray_answer((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->no_answer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->set_file((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 4: { QStringList _r = _t->stringlist_answer((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject database_for_javascript::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_database_for_javascript.data,
      qt_meta_data_database_for_javascript,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *database_for_javascript::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *database_for_javascript::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_database_for_javascript.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int database_for_javascript::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
