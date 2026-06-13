#pragma once

#include <QOpenGLFunctions_2_1>
#include <QOpenGLWidget>
#include <gris/VolumeData.h>

#include "VolumeVisualisation.h"
#include "gris/Camera.h"

namespace ui {
class RenderWidget: public QOpenGLWidget {
    Q_OBJECT
    static constexpr glm::vec4 BACKGROUND_COLOR = {1.f, 1.f, 1.f, 1.f};
    static constexpr glm::vec4 MESH_COLOR = {0.2f, 0.2f, 0.5f, 1.f};
    static constexpr glm::vec4 NORMAL_COLOR = {1.f, 0.f, 0.f, 1.f};
    static constexpr glm::vec4 VOLUME_COLOR = {0.5f, 0.5f, 0.5f, 1.f};

    static constexpr gris::BoundingBox INITIAL_VIEW_BOUNDS = {{-1.f, -1.f, -1.f}, {1.f, 1.f, 1.f}};

public:
    explicit RenderWidget(QWidget* parent = nullptr);
    ~RenderWidget();

public slots:
    void setRenderChecks(bool draw_mesh, bool draw_wireframe, bool draw_normals, bool draw_volume);
    void generateVolumeMesh(
        std::string data_path,
        glm::ivec3 dimensions,
        bool dual,
        float iso_value,
        bool grid_snapping,
        float grid_snapping_distance,
        bool optimize_mesh
    );

    void generateTriviateMesh(
        glm::ivec3 dimensions,
        bool dual,
        float iso_value,
        bool grid_snapping,
        float grid_snapping_distance,
        bool optimize_mesh
    );

protected:
    // QOpenGLWidget interface
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    // QWidget interface
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

private:
    bool m_draw_mesh;
    bool m_draw_wireframe;
    bool m_draw_normals;
    bool m_draw_volume;

    QOpenGLFunctions_2_1* m_f;
    gris::Camera m_camera;
    glm::vec2 m_previous_mouse_position;

    VolumeVisualisation m_volume_visualisation;
};
} // namespace ui
