#include "gris/Camera.h"

#include <iostream>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>
#include <glm/gtx/extend.hpp>

gris::Camera::Camera(float vertical_field_of_view, const BoundingBox& view_area):
    m_distance(0.5f * glm::length(view_area.max - view_area.min) / glm::sin(0.5f * vertical_field_of_view)),
    m_vertical_field_of_view(vertical_field_of_view),
    m_radius(0.5f * glm::length(view_area.max - view_area.min)),
    m_center(0.5f * (view_area.min + view_area.max)),
    m_aspect_ratio(1.f),
    m_zoom_exponent(0.f),
    m_angles({0.f, 0.f}) {
    assert(m_vertical_field_of_view > 0.f);
    assert(m_vertical_field_of_view < glm::pi<float>());
}

void gris::Camera::setViewArea(const BoundingBox& view_area) {
    m_distance = 0.5f * glm::length(view_area.max - view_area.min) / glm::sin(0.5f * m_vertical_field_of_view);
    m_radius = 0.5f * glm::length(view_area.max - view_area.min);
    m_center = 0.5f * (view_area.min + view_area.max);
}

void gris::Camera::setAspectRatio(float aspect_ratio) {
    assert(aspect_ratio > 0.f);
    m_aspect_ratio = aspect_ratio;
}

void gris::Camera::rotate(const glm::vec2& delta) {
    m_angles = {
        glm::mod(m_angles.x + delta.x * ROTATE_SENSITIVITY + glm::pi<float>(), 2.f * glm::pi<float>()) - glm::pi<float>(),
        glm::clamp(m_angles.y + delta.y * ROTATE_SENSITIVITY, -0.5f * glm::pi<float>(), 0.5f * glm::pi<float>())
    };
}

void gris::Camera::zoom(float delta) {
    m_zoom_exponent = glm::max(m_zoom_exponent + delta * ZOOM_SENSITIVITY, 0.f);
}

glm::mat4 gris::Camera::projectionMatrix() const {
    return glm::perspective(
        2.f * glm::atan(glm::tan(0.5f * m_vertical_field_of_view) * glm::pow(0.5f, m_zoom_exponent)),
        m_aspect_ratio,
        m_distance - m_radius - 0.1f,
        m_distance + m_radius + 0.1f
    );
}

glm::mat4 gris::Camera::modelViewMatrix() const {
    glm::mat4 translate = glm::translate(-m_center);
    glm::mat4 rotation_x = glm::rotate(m_angles.x, glm::vec3(0.f, 1.f, 0.f));
    glm::mat4 rotation_y = glm::rotate(m_angles.y, glm::vec3(1.f, 0.f, 0.f));
    glm::mat4 offset = glm::translate(glm::vec3(0.f, 0.f, -m_distance));

    return offset * rotation_y * rotation_x * translate;
}

glm::vec3 gris::Camera::viewDirection() const {
    glm::mat4 rotation_x = glm::rotate(m_angles.x, glm::vec3(0.f, 1.f, 0.f));
    glm::mat4 rotation_y = glm::rotate(m_angles.y, glm::vec3(1.f, 0.f, 0.f));
    std::cout << "x=" << glm::vec3(glm::vec4(0, 0, 1, 1) * rotation_x * rotation_y).x << std::endl;
    std::cout << "y=" << glm::vec3(glm::vec4(0, 0, 1, 1) * rotation_x * rotation_y).y << std::endl;
    std::cout << "z=" << glm::vec3(glm::vec4(0, 0, 1, 1) * rotation_x * rotation_y).z << std::endl;
    return glm::vec3(glm::vec4(0, 0, 1, 1) * rotation_x * rotation_y);
}
