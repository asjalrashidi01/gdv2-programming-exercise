/****************************************************************************
** Meta object code from reading C++ file 'SettingsWidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/ui/SettingsWidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SettingsWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN2ui14SettingsWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto ui::SettingsWidget::qt_create_metaobjectdata<qt_meta_tag_ZN2ui14SettingsWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ui::SettingsWidget",
        "onRenderChecksChanged",
        "",
        "draw_mesh",
        "draw_wireframe",
        "draw_normals",
        "draw_volume",
        "onGenerateTriviate",
        "glm::ivec3",
        "dimensions",
        "dual",
        "iso_value",
        "grid_snapping",
        "grid_snapping_distance",
        "optimize_mesh",
        "onGenerateVolume",
        "std::string",
        "data_path"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'onRenderChecksChanged'
        QtMocHelpers::SignalData<void(bool, bool, bool, bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 }, { QMetaType::Bool, 4 }, { QMetaType::Bool, 5 }, { QMetaType::Bool, 6 },
        }}),
        // Signal 'onGenerateTriviate'
        QtMocHelpers::SignalData<void(glm::ivec3, bool, float, bool, float, bool)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 }, { QMetaType::Bool, 10 }, { QMetaType::Float, 11 }, { QMetaType::Bool, 12 },
            { QMetaType::Float, 13 }, { QMetaType::Bool, 14 },
        }}),
        // Signal 'onGenerateVolume'
        QtMocHelpers::SignalData<void(std::string, glm::ivec3, bool, float, bool, float, bool)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 16, 17 }, { 0x80000000 | 8, 9 }, { QMetaType::Bool, 10 }, { QMetaType::Float, 11 },
            { QMetaType::Bool, 12 }, { QMetaType::Float, 13 }, { QMetaType::Bool, 14 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SettingsWidget, qt_meta_tag_ZN2ui14SettingsWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ui::SettingsWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QDockWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2ui14SettingsWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2ui14SettingsWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2ui14SettingsWidgetE_t>.metaTypes,
    nullptr
} };

void ui::SettingsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SettingsWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onRenderChecksChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[4]))); break;
        case 1: _t->onGenerateTriviate((*reinterpret_cast<std::add_pointer_t<glm::ivec3>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[6]))); break;
        case 2: _t->onGenerateVolume((*reinterpret_cast<std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<glm::ivec3>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[7]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SettingsWidget::*)(bool , bool , bool , bool )>(_a, &SettingsWidget::onRenderChecksChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SettingsWidget::*)(glm::ivec3 , bool , float , bool , float , bool )>(_a, &SettingsWidget::onGenerateTriviate, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SettingsWidget::*)(std::string , glm::ivec3 , bool , float , bool , float , bool )>(_a, &SettingsWidget::onGenerateVolume, 2))
            return;
    }
}

const QMetaObject *ui::SettingsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ui::SettingsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2ui14SettingsWidgetE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::SettingsWidget"))
        return static_cast< Ui::SettingsWidget*>(this);
    return QDockWidget::qt_metacast(_clname);
}

int ui::SettingsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ui::SettingsWidget::onRenderChecksChanged(bool _t1, bool _t2, bool _t3, bool _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 1
void ui::SettingsWidget::onGenerateTriviate(glm::ivec3 _t1, bool _t2, float _t3, bool _t4, float _t5, bool _t6)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2, _t3, _t4, _t5, _t6);
}

// SIGNAL 2
void ui::SettingsWidget::onGenerateVolume(std::string _t1, glm::ivec3 _t2, bool _t3, float _t4, bool _t5, float _t6, bool _t7)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2, _t3, _t4, _t5, _t6, _t7);
}
QT_WARNING_POP
