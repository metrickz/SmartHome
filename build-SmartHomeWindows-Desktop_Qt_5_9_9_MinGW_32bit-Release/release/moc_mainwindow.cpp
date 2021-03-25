/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SmartHomeWindows/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[334];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "updateWeatherUI"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "weatherCode"
QT_MOC_LITERAL(4, 40, 4), // "desc"
QT_MOC_LITERAL(5, 45, 18), // "server_New_Connect"
QT_MOC_LITERAL(6, 64, 16), // "socket_Read_Data"
QT_MOC_LITERAL(7, 81, 19), // "socket_Disconnected"
QT_MOC_LITERAL(8, 101, 14), // "serialReceived"
QT_MOC_LITERAL(9, 116, 22), // "on_btn_lightOn_clicked"
QT_MOC_LITERAL(10, 139, 23), // "on_btn_lightOff_clicked"
QT_MOC_LITERAL(11, 163, 25), // "on_btn_shuttersUp_clicked"
QT_MOC_LITERAL(12, 189, 27), // "on_btn_shuttersDown_clicked"
QT_MOC_LITERAL(13, 217, 19), // "on_btn_tilt_clicked"
QT_MOC_LITERAL(14, 237, 28), // "on_slider_light_valueChanged"
QT_MOC_LITERAL(15, 266, 5), // "value"
QT_MOC_LITERAL(16, 272, 27), // "on_slider_temp_valueChanged"
QT_MOC_LITERAL(17, 300, 13), // "updateWeather"
QT_MOC_LITERAL(18, 314, 19) // "updateWeatherUISlot"

    },
    "MainWindow\0updateWeatherUI\0\0weatherCode\0"
    "desc\0server_New_Connect\0socket_Read_Data\0"
    "socket_Disconnected\0serialReceived\0"
    "on_btn_lightOn_clicked\0on_btn_lightOff_clicked\0"
    "on_btn_shuttersUp_clicked\0"
    "on_btn_shuttersDown_clicked\0"
    "on_btn_tilt_clicked\0on_slider_light_valueChanged\0"
    "value\0on_slider_temp_valueChanged\0"
    "updateWeather\0updateWeatherUISlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   89,    2, 0x08 /* Private */,
       6,    0,   90,    2, 0x08 /* Private */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    1,   98,    2, 0x08 /* Private */,
      16,    1,  101,    2, 0x08 /* Private */,
      17,    0,  104,    2, 0x08 /* Private */,
      18,    2,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateWeatherUI((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->server_New_Connect(); break;
        case 2: _t->socket_Read_Data(); break;
        case 3: _t->socket_Disconnected(); break;
        case 4: _t->serialReceived(); break;
        case 5: _t->on_btn_lightOn_clicked(); break;
        case 6: _t->on_btn_lightOff_clicked(); break;
        case 7: _t->on_btn_shuttersUp_clicked(); break;
        case 8: _t->on_btn_shuttersDown_clicked(); break;
        case 9: _t->on_btn_tilt_clicked(); break;
        case 10: _t->on_slider_light_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_slider_temp_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->updateWeather(); break;
        case 13: _t->updateWeatherUISlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::updateWeatherUI)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::updateWeatherUI(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
