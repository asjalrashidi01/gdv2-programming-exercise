/********************************************************************************
** Form generated from reading UI file 'SettingsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWIDGET_H
#define UI_SETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWidget
{
public:
    QWidget *_central_widget;
    QFormLayout *formLayout;
    QLabel *_render_label;
    QGridLayout *_render_grid_layout;
    QCheckBox *m_wireframe_check_box;
    QCheckBox *m_normals_check_box;
    QCheckBox *m_volume_check_box;
    QCheckBox *m_mesh_check_box;
    QFrame *_line;
    QGroupBox *m_volume_data_group_box;
    QFormLayout *formLayout_3;
    QLabel *_volume_source_label;
    QHBoxLayout *_horizontal_layout_2;
    QComboBox *m_volume_source_combo_box;
    QToolButton *m_volume_source_tool_button;
    QGroupBox *m_triviate_function_group_box;
    QFormLayout *formLayout_2;
    QLabel *m_dimensions_label;
    QHBoxLayout *_horizontal_layout_1;
    QSpinBox *m_dimension_x;
    QSpinBox *m_dimension_y;
    QSpinBox *m_dimension_z;
    QLabel *_algorithm_label;
    QComboBox *m_algorithm_combo_box;
    QLabel *_iso_value_label;
    QDoubleSpinBox *m_iso_value_spin_box;
    QLabel *_grid_snapping_label;
    QCheckBox *m_grid_snapping_check_box;
    QLabel *_grid_snapping_distance_label;
    QDoubleSpinBox *m_grid_snapping_distance_spin_box;
    QLabel *_optimize_mesh_label;
    QCheckBox *m_optimize_mesh;
    QPushButton *m_generate_button;

    void setupUi(QDockWidget *SettingsWidget)
    {
        if (SettingsWidget->objectName().isEmpty())
            SettingsWidget->setObjectName("SettingsWidget");
        SettingsWidget->resize(308, 426);
        SettingsWidget->setMinimumSize(QSize(308, 426));
        _central_widget = new QWidget();
        _central_widget->setObjectName("_central_widget");
        formLayout = new QFormLayout(_central_widget);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        _render_label = new QLabel(_central_widget);
        _render_label->setObjectName("_render_label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, _render_label);

        _render_grid_layout = new QGridLayout();
        _render_grid_layout->setObjectName("_render_grid_layout");
        m_wireframe_check_box = new QCheckBox(_central_widget);
        m_wireframe_check_box->setObjectName("m_wireframe_check_box");

        _render_grid_layout->addWidget(m_wireframe_check_box, 0, 1, 1, 1);

        m_normals_check_box = new QCheckBox(_central_widget);
        m_normals_check_box->setObjectName("m_normals_check_box");

        _render_grid_layout->addWidget(m_normals_check_box, 1, 0, 1, 1);

        m_volume_check_box = new QCheckBox(_central_widget);
        m_volume_check_box->setObjectName("m_volume_check_box");

        _render_grid_layout->addWidget(m_volume_check_box, 1, 1, 1, 1);

        m_mesh_check_box = new QCheckBox(_central_widget);
        m_mesh_check_box->setObjectName("m_mesh_check_box");

        _render_grid_layout->addWidget(m_mesh_check_box, 0, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::ItemRole::FieldRole, _render_grid_layout);

        _line = new QFrame(_central_widget);
        _line->setObjectName("_line");
        _line->setMinimumSize(QSize(0, 0));
        _line->setFrameShape(QFrame::Shape::HLine);
        _line->setFrameShadow(QFrame::Shadow::Sunken);

        formLayout->setWidget(1, QFormLayout::ItemRole::SpanningRole, _line);

        m_volume_data_group_box = new QGroupBox(_central_widget);
        m_volume_data_group_box->setObjectName("m_volume_data_group_box");
        m_volume_data_group_box->setCheckable(true);
        m_volume_data_group_box->setChecked(true);
        formLayout_3 = new QFormLayout(m_volume_data_group_box);
        formLayout_3->setObjectName("formLayout_3");
        _volume_source_label = new QLabel(m_volume_data_group_box);
        _volume_source_label->setObjectName("_volume_source_label");

        formLayout_3->setWidget(0, QFormLayout::ItemRole::LabelRole, _volume_source_label);

        _horizontal_layout_2 = new QHBoxLayout();
        _horizontal_layout_2->setObjectName("_horizontal_layout_2");
        m_volume_source_combo_box = new QComboBox(m_volume_data_group_box);
        m_volume_source_combo_box->setObjectName("m_volume_source_combo_box");

        _horizontal_layout_2->addWidget(m_volume_source_combo_box);

        m_volume_source_tool_button = new QToolButton(m_volume_data_group_box);
        m_volume_source_tool_button->setObjectName("m_volume_source_tool_button");

        _horizontal_layout_2->addWidget(m_volume_source_tool_button);


        formLayout_3->setLayout(0, QFormLayout::ItemRole::FieldRole, _horizontal_layout_2);


        formLayout->setWidget(2, QFormLayout::ItemRole::SpanningRole, m_volume_data_group_box);

        m_triviate_function_group_box = new QGroupBox(_central_widget);
        m_triviate_function_group_box->setObjectName("m_triviate_function_group_box");
        m_triviate_function_group_box->setCheckable(true);
        m_triviate_function_group_box->setChecked(false);
        formLayout_2 = new QFormLayout(m_triviate_function_group_box);
        formLayout_2->setObjectName("formLayout_2");
        m_dimensions_label = new QLabel(m_triviate_function_group_box);
        m_dimensions_label->setObjectName("m_dimensions_label");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, m_dimensions_label);

        _horizontal_layout_1 = new QHBoxLayout();
        _horizontal_layout_1->setObjectName("_horizontal_layout_1");
        m_dimension_x = new QSpinBox(m_triviate_function_group_box);
        m_dimension_x->setObjectName("m_dimension_x");
        m_dimension_x->setMinimum(2);
        m_dimension_x->setMaximum(256);
        m_dimension_x->setSingleStep(1);
        m_dimension_x->setValue(32);

        _horizontal_layout_1->addWidget(m_dimension_x);

        m_dimension_y = new QSpinBox(m_triviate_function_group_box);
        m_dimension_y->setObjectName("m_dimension_y");
        m_dimension_y->setMinimum(2);
        m_dimension_y->setMaximum(256);
        m_dimension_y->setValue(32);

        _horizontal_layout_1->addWidget(m_dimension_y);

        m_dimension_z = new QSpinBox(m_triviate_function_group_box);
        m_dimension_z->setObjectName("m_dimension_z");
        m_dimension_z->setMinimum(2);
        m_dimension_z->setMaximum(256);
        m_dimension_z->setValue(32);

        _horizontal_layout_1->addWidget(m_dimension_z);


        formLayout_2->setLayout(0, QFormLayout::ItemRole::FieldRole, _horizontal_layout_1);


        formLayout->setWidget(3, QFormLayout::ItemRole::SpanningRole, m_triviate_function_group_box);

        _algorithm_label = new QLabel(_central_widget);
        _algorithm_label->setObjectName("_algorithm_label");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, _algorithm_label);

        m_algorithm_combo_box = new QComboBox(_central_widget);
        m_algorithm_combo_box->addItem(QString());
        m_algorithm_combo_box->addItem(QString());
        m_algorithm_combo_box->setObjectName("m_algorithm_combo_box");
        m_algorithm_combo_box->setDuplicatesEnabled(false);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, m_algorithm_combo_box);

        _iso_value_label = new QLabel(_central_widget);
        _iso_value_label->setObjectName("_iso_value_label");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, _iso_value_label);

        m_iso_value_spin_box = new QDoubleSpinBox(_central_widget);
        m_iso_value_spin_box->setObjectName("m_iso_value_spin_box");
        m_iso_value_spin_box->setMaximum(1.000000000000000);
        m_iso_value_spin_box->setSingleStep(0.010000000000000);
        m_iso_value_spin_box->setValue(0.500000000000000);

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, m_iso_value_spin_box);

        _grid_snapping_label = new QLabel(_central_widget);
        _grid_snapping_label->setObjectName("_grid_snapping_label");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, _grid_snapping_label);

        m_grid_snapping_check_box = new QCheckBox(_central_widget);
        m_grid_snapping_check_box->setObjectName("m_grid_snapping_check_box");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, m_grid_snapping_check_box);

        _grid_snapping_distance_label = new QLabel(_central_widget);
        _grid_snapping_distance_label->setObjectName("_grid_snapping_distance_label");

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, _grid_snapping_distance_label);

        m_grid_snapping_distance_spin_box = new QDoubleSpinBox(_central_widget);
        m_grid_snapping_distance_spin_box->setObjectName("m_grid_snapping_distance_spin_box");
        m_grid_snapping_distance_spin_box->setDecimals(4);
        m_grid_snapping_distance_spin_box->setSingleStep(0.010000000000000);

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, m_grid_snapping_distance_spin_box);

        _optimize_mesh_label = new QLabel(_central_widget);
        _optimize_mesh_label->setObjectName("_optimize_mesh_label");

        formLayout->setWidget(8, QFormLayout::ItemRole::LabelRole, _optimize_mesh_label);

        m_optimize_mesh = new QCheckBox(_central_widget);
        m_optimize_mesh->setObjectName("m_optimize_mesh");

        formLayout->setWidget(8, QFormLayout::ItemRole::FieldRole, m_optimize_mesh);

        m_generate_button = new QPushButton(_central_widget);
        m_generate_button->setObjectName("m_generate_button");

        formLayout->setWidget(9, QFormLayout::ItemRole::SpanningRole, m_generate_button);

        SettingsWidget->setWidget(_central_widget);

        retranslateUi(SettingsWidget);

        QMetaObject::connectSlotsByName(SettingsWidget);
    } // setupUi

    void retranslateUi(QDockWidget *SettingsWidget)
    {
        SettingsWidget->setWindowTitle(QCoreApplication::translate("SettingsWidget", "Settings", nullptr));
        _render_label->setText(QCoreApplication::translate("SettingsWidget", "Render:", nullptr));
        m_wireframe_check_box->setText(QCoreApplication::translate("SettingsWidget", "Wireframe", nullptr));
        m_normals_check_box->setText(QCoreApplication::translate("SettingsWidget", "Normals", nullptr));
        m_volume_check_box->setText(QCoreApplication::translate("SettingsWidget", "Volume", nullptr));
        m_mesh_check_box->setText(QCoreApplication::translate("SettingsWidget", "Mesh", nullptr));
        m_volume_data_group_box->setTitle(QCoreApplication::translate("SettingsWidget", "Use Volume Data", nullptr));
        _volume_source_label->setText(QCoreApplication::translate("SettingsWidget", "Volume Source:", nullptr));
        m_volume_source_tool_button->setText(QCoreApplication::translate("SettingsWidget", "...", nullptr));
        m_triviate_function_group_box->setTitle(QCoreApplication::translate("SettingsWidget", "Use Triviate Function", nullptr));
        m_dimensions_label->setText(QCoreApplication::translate("SettingsWidget", "Dimensions:", nullptr));
        _algorithm_label->setText(QCoreApplication::translate("SettingsWidget", "Algorithm:", nullptr));
        m_algorithm_combo_box->setItemText(0, QCoreApplication::translate("SettingsWidget", "Marching Cubes", nullptr));
        m_algorithm_combo_box->setItemText(1, QCoreApplication::translate("SettingsWidget", "Dual Marching Cubes", nullptr));

        _iso_value_label->setText(QCoreApplication::translate("SettingsWidget", "Iso Value:", nullptr));
        _grid_snapping_label->setText(QCoreApplication::translate("SettingsWidget", "Grid Snapping:", nullptr));
        m_grid_snapping_check_box->setText(QCoreApplication::translate("SettingsWidget", "Enable", nullptr));
        _grid_snapping_distance_label->setText(QCoreApplication::translate("SettingsWidget", "Grid Snapping Distance:", nullptr));
        _optimize_mesh_label->setText(QCoreApplication::translate("SettingsWidget", "Optimize Mesh:", nullptr));
        m_optimize_mesh->setText(QCoreApplication::translate("SettingsWidget", "Enable", nullptr));
        m_generate_button->setText(QCoreApplication::translate("SettingsWidget", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWidget: public Ui_SettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWIDGET_H
