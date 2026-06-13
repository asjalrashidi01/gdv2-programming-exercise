#include "ui/SettingsWidget.h"

#include <QPushButton>

ui::SettingsWidget::SettingsWidget(bool render_mesh, bool render_wireframe, bool render_normals, bool render_volume, QWidget* parent):
    m_load_dialog(new ui::LoadDialog) {
    setupUi(this);
    assert(render_mesh != render_wireframe);

    m_mesh_check_box->setChecked(render_mesh);
    m_wireframe_check_box->setChecked(render_wireframe);
    m_normals_check_box->setChecked(render_normals);
    m_volume_check_box->setChecked(render_volume);

    connect(m_mesh_check_box, &QCheckBox::toggled, m_wireframe_check_box, [&](bool is_checked) -> void {
        {
            QSignalBlocker blocker(m_wireframe_check_box);
            m_wireframe_check_box->setChecked(!is_checked && m_wireframe_check_box->isChecked());
        }
        emit onRenderChecksChanged(m_mesh_check_box->isChecked(), m_wireframe_check_box->isChecked(), m_normals_check_box->isChecked(), m_volume_check_box->isChecked());
    });

    connect(m_wireframe_check_box, &QCheckBox::toggled, m_mesh_check_box, [&](bool is_checked) -> void {
        {
            QSignalBlocker blocker(m_mesh_check_box);
            m_mesh_check_box->setChecked(!is_checked && m_mesh_check_box->isChecked());
        }
        emit onRenderChecksChanged(m_mesh_check_box->isChecked(), m_wireframe_check_box->isChecked(), m_normals_check_box->isChecked(), m_volume_check_box->isChecked());
    });

    connect(m_normals_check_box, &QCheckBox::toggled, this, [&](bool is_checked) {
        emit onRenderChecksChanged(m_mesh_check_box->isChecked(), m_wireframe_check_box->isChecked(), m_normals_check_box->isChecked(), m_volume_check_box->isChecked());
    });

    connect(m_volume_check_box, &QCheckBox::toggled, this, [&](bool is_checked) {
        emit onRenderChecksChanged(m_mesh_check_box->isChecked(), m_wireframe_check_box->isChecked(), m_normals_check_box->isChecked(), m_volume_check_box->isChecked());
    });

    m_volume_infos.push_back({"/Users/asjalrashidi/TUDa/Academics/Spring 2026/CG II/Exercises/Programming Exercise 1/framework/data/neghip(size=64x64x64,spacing=1x1x1).raw", {64, 64, 64}});
    m_volume_source_combo_box->addItem("/Users/asjalrashidi/TUDa/Academics/Spring 2026/CG II/Exercises/Programming Exercise 1/framework/data/neghip(size=64x64x64,spacing=1x1x1).raw");

    m_volume_infos.push_back({"/Users/asjalrashidi/TUDa/Academics/Spring 2026/CG II/Exercises/Programming Exercise 1/framework/data/bonsai(size=256x256x256,spacing=1x1x1).raw", {256, 256, 256}});
    m_volume_source_combo_box->addItem("/Users/asjalrashidi/TUDa/Academics/Spring 2026/CG II/Exercises/Programming Exercise 1/framework/data/bonsai(size=256x256x256,spacing=1x1x1).raw");

    m_volume_infos.push_back({"/Users/asjalrashidi/TUDa/Academics/Spring 2026/CG II/Exercises/Programming Exercise 1/framework/data/Stanford_Bunny_sample(size=128x128x128,spacing=1x1x1).raw", {128, 128, 128}});
    m_volume_source_combo_box->addItem("/Users/asjalrashidi/TUDa/Academics/Spring 2026/CG II/Exercises/Programming Exercise 1/framework/data/Stanford_Bunny_sample(size=128x128x128,spacing=1x1x1).raw");

    m_volume_data_group_box->setChecked(true);
    m_triviate_function_group_box->setChecked(false);

    connect(m_volume_data_group_box, &QGroupBox::toggled, m_triviate_function_group_box, [&](bool is_checked) -> void {
        m_triviate_function_group_box->setChecked(!is_checked);
    });

    connect(m_triviate_function_group_box, &QGroupBox::toggled, m_volume_data_group_box, [&](bool is_checked) -> void {
        m_volume_data_group_box->setChecked(!is_checked);
    });

    connect(m_volume_source_tool_button, &QToolButton::clicked, m_load_dialog, &QDialog::exec);
    connect(m_load_dialog, &ui::LoadDialog::onLoad, this, [&](const std::string& path, const glm::ivec3 dimensions) {
        m_volume_infos.push_back({path, dimensions});
        m_volume_source_combo_box->addItem(QString::fromStdString(path));
    });

    connect(m_generate_button, &QPushButton::clicked, this, [&]() -> void {
        if(m_triviate_function_group_box->isChecked()) {
            emit onGenerateTriviate(
                {m_dimension_x->value(), m_dimension_y->value(), m_dimension_z->value()},
                m_algorithm_combo_box->currentIndex() == 1,
                m_iso_value_spin_box->value(),
                m_grid_snapping_check_box->isChecked(),
                m_grid_snapping_distance_spin_box->value(),
                m_optimize_mesh->isChecked()
            );
        } else {
            int index = m_volume_source_combo_box->currentIndex();
            emit onGenerateVolume(
                m_volume_infos[index].first,
                m_volume_infos[index].second,
                m_algorithm_combo_box->currentIndex() == 1,
                m_iso_value_spin_box->value(),
                m_grid_snapping_check_box->isChecked(),
                m_grid_snapping_distance_spin_box->value(),
                m_optimize_mesh->isChecked()
            );
        }
    });
}
