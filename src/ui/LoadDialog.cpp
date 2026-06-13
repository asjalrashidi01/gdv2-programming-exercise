#include "ui/LoadDialog.h"

#include <QFileDialog>

ui::LoadDialog::LoadDialog(QWidget* parent) {
    setupUi(this);

    connect(m_path_tool_button, &QToolButton::clicked, this, [&]() -> void {
        QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"));
        if(!file_name.isNull()) {
            m_path_line_edit->setText(file_name);
        }
    });

    connect(m_button_box, &QDialogButtonBox::accepted, this, [&]() -> void {
        emit onLoad(m_path_line_edit->text().toStdString(), {m_dimensions_x_spin_box->value(), m_dimensions_y_spin_box->value(), m_dimensions_z_spin_box->value()});
        accept();
    });

    connect(m_button_box, &QDialogButtonBox::rejected, this, [&]() -> void {
        reject();
    });
}
