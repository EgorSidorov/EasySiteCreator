/****************************************************************************
** Meta object code from reading C++ file 'dialog_settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialog_settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dialog_settings_t {
    QByteArrayData data[7];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dialog_settings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dialog_settings_t qt_meta_stringdata_dialog_settings = {
    {
QT_MOC_LITERAL(0, 0, 15), // "dialog_settings"
QT_MOC_LITERAL(1, 16, 30), // "on_set_folder_database_clicked"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 27), // "on_set_way_database_clicked"
QT_MOC_LITERAL(4, 76, 29), // "on_set_folder_project_clicked"
QT_MOC_LITERAL(5, 106, 26), // "on_set_way_project_clicked"
QT_MOC_LITERAL(6, 133, 15) // "on_yes_accepted"

    },
    "dialog_settings\0on_set_folder_database_clicked\0"
    "\0on_set_way_database_clicked\0"
    "on_set_folder_project_clicked\0"
    "on_set_way_project_clicked\0on_yes_accepted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dialog_settings[] = {

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

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dialog_settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dialog_settings *_t = static_cast<dialog_settings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_set_folder_database_clicked(); break;
        case 1: _t->on_set_way_database_clicked(); break;
        case 2: _t->on_set_folder_project_clicked(); break;
        case 3: _t->on_set_way_project_clicked(); break;
        case 4: _t->on_yes_accepted(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject dialog_settings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialog_settings.data,
      qt_meta_data_dialog_settings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *dialog_settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dialog_settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dialog_settings.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int dialog_settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
