/********************************************************************************
** Form generated from reading UI file 'LoadDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADDIALOG_H
#define UI_LOADDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_LoadDialog
{
public:
    QFormLayout *formLayout;
    QLabel *_path_label;
    QHBoxLayout *_path_layout;
    QLineEdit *m_path_line_edit;
    QToolButton *m_path_tool_button;
    QLabel *_dimensions_label;
    QHBoxLayout *_horizontal_layout_1;
    QSpinBox *m_dimensions_x_spin_box;
    QSpinBox *m_dimensions_y_spin_box;
    QSpinBox *m_dimensions_z_spin_box;
    QSpacerItem *_vertical_spacer;
    QDialogButtonBox *m_button_box;

    void setupUi(QDialog *LoadDialog)
    {
        if (LoadDialog->objectName().isEmpty())
            LoadDialog->setObjectName("LoadDialog");
        LoadDialog->resize(238, 192);
        formLayout = new QFormLayout(LoadDialog);
        formLayout->setObjectName("formLayout");
        _path_label = new QLabel(LoadDialog);
        _path_label->setObjectName("_path_label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, _path_label);

        _path_layout = new QHBoxLayout();
        _path_layout->setObjectName("_path_layout");
        m_path_line_edit = new QLineEdit(LoadDialog);
        m_path_line_edit->setObjectName("m_path_line_edit");

        _path_layout->addWidget(m_path_line_edit);

        m_path_tool_button = new QToolButton(LoadDialog);
        m_path_tool_button->setObjectName("m_path_tool_button");

        _path_layout->addWidget(m_path_tool_button);


        formLayout->setLayout(0, QFormLayout::ItemRole::FieldRole, _path_layout);

        _dimensions_label = new QLabel(LoadDialog);
        _dimensions_label->setObjectName("_dimensions_label");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, _dimensions_label);

        _horizontal_layout_1 = new QHBoxLayout();
        _horizontal_layout_1->setObjectName("_horizontal_layout_1");
        m_dimensions_x_spin_box = new QSpinBox(LoadDialog);
        m_dimensions_x_spin_box->setObjectName("m_dimensions_x_spin_box");
        m_dimensions_x_spin_box->setMinimum(2);
        m_dimensions_x_spin_box->setMaximum(999);
        m_dimensions_x_spin_box->setValue(2);

        _horizontal_layout_1->addWidget(m_dimensions_x_spin_box);

        m_dimensions_y_spin_box = new QSpinBox(LoadDialog);
        m_dimensions_y_spin_box->setObjectName("m_dimensions_y_spin_box");
        m_dimensions_y_spin_box->setMinimum(2);
        m_dimensions_y_spin_box->setMaximum(999);

        _horizontal_layout_1->addWidget(m_dimensions_y_spin_box);

        m_dimensions_z_spin_box = new QSpinBox(LoadDialog);
        m_dimensions_z_spin_box->setObjectName("m_dimensions_z_spin_box");
        m_dimensions_z_spin_box->setMinimum(2);
        m_dimensions_z_spin_box->setMaximum(999);

        _horizontal_layout_1->addWidget(m_dimensions_z_spin_box);


        formLayout->setLayout(1, QFormLayout::ItemRole::FieldRole, _horizontal_layout_1);

        _vertical_spacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(2, QFormLayout::ItemRole::SpanningRole, _vertical_spacer);

        m_button_box = new QDialogButtonBox(LoadDialog);
        m_button_box->setObjectName("m_button_box");
        m_button_box->setOrientation(Qt::Orientation::Horizontal);
        m_button_box->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        formLayout->setWidget(3, QFormLayout::ItemRole::SpanningRole, m_button_box);


        retranslateUi(LoadDialog);
        QObject::connect(m_button_box, &QDialogButtonBox::accepted, LoadDialog, qOverload<>(&QDialog::accept));
        QObject::connect(m_button_box, &QDialogButtonBox::rejected, LoadDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(LoadDialog);
    } // setupUi

    void retranslateUi(QDialog *LoadDialog)
    {
        LoadDialog->setWindowTitle(QCoreApplication::translate("LoadDialog", "Dialog", nullptr));
        _path_label->setText(QCoreApplication::translate("LoadDialog", "Path:", nullptr));
        m_path_tool_button->setText(QCoreApplication::translate("LoadDialog", "...", nullptr));
        _dimensions_label->setText(QCoreApplication::translate("LoadDialog", "Dimensions:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadDialog: public Ui_LoadDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADDIALOG_H
