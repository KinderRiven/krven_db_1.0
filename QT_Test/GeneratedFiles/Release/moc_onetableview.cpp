/****************************************************************************
** Meta object code from reading C++ file 'onetableview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../onetableview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'onetableview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_oneTableView_t {
    QByteArrayData data[3];
    char stringdata[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_oneTableView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_oneTableView_t qt_meta_stringdata_oneTableView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "oneTableView"
QT_MOC_LITERAL(1, 13, 5), // "kExit"
QT_MOC_LITERAL(2, 19, 0) // ""

    },
    "oneTableView\0kExit\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_oneTableView[] = {

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

void oneTableView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        oneTableView *_t = static_cast<oneTableView *>(_o);
        switch (_id) {
        case 0: _t->kExit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject oneTableView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_oneTableView.data,
      qt_meta_data_oneTableView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *oneTableView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *oneTableView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_oneTableView.stringdata))
        return static_cast<void*>(const_cast< oneTableView*>(this));
    return QWidget::qt_metacast(_clname);
}

int oneTableView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
