#pragma once
#include <glm/glm.hpp>
#include <gris/BoundingBox.h>

namespace gris {
class Camera {
    static constexpr float ROTATE_SENSITIVITY = 1.5f;
    static constexpr float ZOOM_SENSITIVITY = 1.5f;

public:
    Camera(float vertical_field_of_view, const gris::BoundingBox& view_area);

    void setViewArea(const gris::BoundingBox& view_area);
    void setAspectRatio(float aspect_ratio);
    void rotate(const glm::vec2& delta);
    void zoom(float delta);
    glm::mat4 projectionMatrix() const;
    glm::mat4 modelViewMatrix() const;
    glm::vec3 viewDirection() const;

private:
    const float m_vertical_field_of_view;
    glm::vec2 m_angles;
    glm::vec3 m_center;
    float m_distance;
    float m_radius;
    float m_aspect_ratio;
    float m_zoom_exponent;
};
} // namespace gris
