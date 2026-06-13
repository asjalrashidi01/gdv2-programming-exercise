#pragma once

#include <QDockWidget>
#include <glm/glm.hpp>

#include "ui/LoadDialog.h"
#include "ui_SettingsWidget.h"

namespace ui {
class SettingsWidget: public QDockWidget, Ui::SettingsWidget {
    Q_OBJECT

public:
    explicit SettingsWidget(bool render_mesh, bool render_wireframe, bool render_normals, bool render_volume, QWidget* parent = nullptr);

signals:
    void onRenderChecksChanged(bool draw_mesh, bool draw_wireframe, bool draw_normals, bool draw_volume);
    void onGenerateTriviate(
        glm::ivec3 dimensions,
        bool dual,
        float iso_value,
        bool grid_snapping,
        float grid_snapping_distance,
        bool optimize_mesh
    );
    void onGenerateVolume(
        std::string data_path,
        glm::ivec3 dimensions,
        bool dual,
        float iso_value,
        bool grid_snapping,
        float grid_snapping_distance,
        bool optimize_mesh
    );

private:
    std::vector<std::pair<std::string, glm::ivec3>> m_volume_infos;
    ui::LoadDialog* m_load_dialog;
};
} // namespace ui
