#include "ui/RenderWidget.h"

#include <QMouseEvent>
#include <glm/common.hpp>

ui::RenderWidget::RenderWidget(QWidget* parent):
    QOpenGLWidget(parent),
    m_camera(1.f, INITIAL_VIEW_BOUNDS),
    m_volume_visualisation(INITIAL_VIEW_BOUNDS) {
}

ui::RenderWidget::~RenderWidget() { }

void ui::RenderWidget::setRenderChecks(bool draw_mesh, bool draw_wireframe, bool draw_normals, bool draw_volume) {
    m_draw_mesh = draw_mesh;
    m_draw_wireframe = draw_wireframe;
    m_draw_normals = draw_normals;
    m_draw_volume = draw_volume;
    update();
}

void ui::RenderWidget::generateVolumeMesh(std::string data_path, glm::ivec3 dimensions, bool dual, float iso_value, bool grid_snapping, float grid_snapping_distance, bool optimize_mesh) {
    gris::BoundingBox bounding_box = {
        -static_cast<glm::vec3>(dimensions) / static_cast<float>(glm::max(dimensions.x, glm::max(dimensions.y, dimensions.z))),
        static_cast<glm::vec3>(dimensions) / static_cast<float>(glm::max(dimensions.x, glm::max(dimensions.y, dimensions.z)))
    };

    m_camera.setViewArea(bounding_box);
    m_volume_visualisation.loadRawVolumeData(data_path, dimensions, bounding_box);
    m_volume_visualisation.generateMesh(iso_value, dual, grid_snapping, grid_snapping_distance, optimize_mesh);
    update();
}

void ui::RenderWidget::generateTriviateMesh(glm::ivec3 dimensions, bool dual, float iso_value, bool grid_snapping, float grid_snapping_distance, bool optimize_mesh) {
    gris::BoundingBox bounding_box = {
        -static_cast<glm::vec3>(dimensions) / static_cast<float>(glm::max(dimensions.x, glm::max(dimensions.y, dimensions.z))),
        static_cast<glm::vec3>(dimensions) / static_cast<float>(glm::max(dimensions.x, glm::max(dimensions.y, dimensions.z)))
    };

    m_camera.setViewArea(bounding_box);
    m_volume_visualisation.generateTriviateVolumeData(dimensions, bounding_box);
    m_volume_visualisation.generateMesh(iso_value, dual, grid_snapping, grid_snapping_distance, optimize_mesh);
    update();
}

void ui::RenderWidget::initializeGL() {
    m_f = new QOpenGLFunctions_2_1();
    m_f->initializeOpenGLFunctions();
    m_f->glClearColor(BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
    m_f->glShadeModel(GL_SMOOTH);

    m_f->glEnable(GL_LIGHT0);
    GLfloat ambient[4] = {0.3, 0.3, 0.3, 0.3};
    GLfloat white[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat gray[4] = {0.4, 0.4, 0.4, 0.0};
    GLfloat l0[4] = {0.0, 0.0, 1.0, 0.0};

    m_f->glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    m_f->glLightfv(GL_LIGHT0, GL_DIFFUSE, gray);
    m_f->glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    m_f->glLightfv(GL_LIGHT0, GL_POSITION, l0);

    m_f->glEnable(GL_COLOR_MATERIAL);
    m_f->glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, gray);
    m_f->glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
    m_f->glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, gray);
    m_f->glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 15.0);

    m_f->glEnable(GL_NORMALIZE);
    m_f->glEnable(GL_DEPTH_TEST);
    m_f->glEnable(GL_POINT_SMOOTH);
    m_f->glEnable(GL_PROGRAM_POINT_SIZE);

    m_f->glPointSize(1.5);
    m_f->glCullFace(GL_BACK);
}

void ui::RenderWidget::resizeGL(int w, int h) {
    m_camera.setAspectRatio(static_cast<float>(w) / static_cast<float>(h));
}

void ui::RenderWidget::paintGL() {
    m_f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glm::mat4 projection_matrix = m_camera.projectionMatrix();
    glm::mat4 model_view_matrix = m_camera.modelViewMatrix();
    m_f->glMatrixMode(GL_MODELVIEW);
    m_f->glLoadMatrixf(reinterpret_cast<const float*>(&model_view_matrix));
    m_f->glMatrixMode(GL_PROJECTION);
    m_f->glLoadMatrixf(reinterpret_cast<const float*>(&projection_matrix));

    if(m_draw_mesh) {
        m_f->glColor3fv(reinterpret_cast<const float*>(&MESH_COLOR));

        m_f->glEnable(GL_CULL_FACE);
        m_f->glEnable(GL_LIGHTING);
        m_f->glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        m_volume_visualisation.drawMesh(m_f);
    }
    if(m_draw_wireframe) {
        m_f->glColor3fv(reinterpret_cast<const float*>(&MESH_COLOR));

        m_f->glDisable(GL_CULL_FACE);
        m_f->glDisable(GL_LIGHTING);
        m_f->glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        m_volume_visualisation.drawMesh(m_f);
    }
    if(m_draw_normals) {
        m_f->glColor3fv(reinterpret_cast<const float*>(&NORMAL_COLOR));

        m_f->glDisable(GL_CULL_FACE);
        m_f->glDisable(GL_LIGHTING);
        m_f->glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        m_volume_visualisation.drawNormals(m_f);
    }
    if(m_draw_volume) {
        m_f->glColor3fv(reinterpret_cast<const float*>(&VOLUME_COLOR));

        m_f->glEnable(GL_CULL_FACE);
        m_f->glCullFace(GL_BACK);
        m_f->glDisable(GL_LIGHTING);
        m_f->glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        m_volume_visualisation.drawVolumeData(m_f);
    }
}

void ui::RenderWidget::mousePressEvent(QMouseEvent* event) {
    m_previous_mouse_position = {
        static_cast<float>(event->pos().x()) / static_cast<float>(height()),
        static_cast<float>(event->pos().y()) / static_cast<float>(height())
    };
}

void ui::RenderWidget::mouseMoveEvent(QMouseEvent* event) {
    glm::vec2 mouse_position = {
        static_cast<float>(event->pos().x()) / static_cast<float>(height()),
        static_cast<float>(event->pos().y()) / static_cast<float>(height())
    };

    m_camera.rotate(mouse_position - m_previous_mouse_position);
    m_previous_mouse_position = mouse_position;
    update();
}

void ui::RenderWidget::wheelEvent(QWheelEvent* event) {
    m_camera.zoom(glm::radians(static_cast<float>(event->angleDelta().y() / 8.f)));
    update();
}
