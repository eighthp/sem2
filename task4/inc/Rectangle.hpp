#pragma once
#include <SFML/Graphics.hpp>
namespace ag {
    class Rectangle {
        float m_x, m_y;
        float m_t;
        float m_len, m_wid;
        sf::RectangleShape m_shape;
    public:
        Rectangle() = default;

        Rectangle(float x, float y, float t, float len, float wid) {
            Setup(x, y, t, len, wid);
        }

        void Setup(float x, float y, float t, float len, float wid) {
            m_x = x;
            m_y = y;
            m_t = t;
            m_len = len;
            m_wid = wid;
            m_shape.setPosition(m_x, m_y);
            m_shape.setRotation(m_t);
            m_shape.setFillColor(sf::Color::Magenta);
            m_shape.setSize({m_len, m_wid});
        }

        sf::RectangleShape Get() {
            return m_shape;
        };
    };
}