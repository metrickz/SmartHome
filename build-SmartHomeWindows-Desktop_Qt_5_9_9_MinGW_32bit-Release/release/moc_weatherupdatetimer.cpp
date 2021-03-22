/****************************************************************************
** Meta object code from reading C++ file 'weatherupdatetimer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SmartHomeWindows/weatherupdatetimer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weatherupdatetimer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WeatherUpdateTimer_t {
    QByteArrayData data[3];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeatherUpdateTimer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeatherUpdateTimer_t qt_meta_stringdata_WeatherUpdateTimer = {
    {
QT_MOC_LITERAL(0, 0, 18), // "WeatherUpdateTimer"
QT_MOC_LITERAL(1, 19, 9), // "TimerSlot"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "WeatherUpdateTimer\0TimerSlot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherUpdateTimer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void WeatherUpdateTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeatherUpdateTimer *_t = static_cast<WeatherUpdateTimer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TimerSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject WeatherUpdateTimer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WeatherUpdateTimer.data,
      qt_meta_data_WeatherUpdateTimer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WeatherUpdateTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherUpdateTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherUpdateTimer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WeatherUpdateTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
