#pragma once
#include <SFML/Graphics.hpp>
namespace ag
{
    class Line
    {
        float m_x, m_y;
        float m_t;
        float m_len;
        sf::RectangleShape m_shape;
    public:
        Line() = default;

        Line(float x, float y, float t, float len)
        {
            Setup(x,y,t, len);
        }
        void Setup(float x, float y, float t, float len)
        {
            m_x = x;
            m_y = y;
            m_t = t;
            m_len = len;
            m_shape.setPosition(m_x,m_y);
            m_shape.setRotation(m_t);
            m_shape.setFillColor(sf::Color(0,0,255,255));
            m_shape.setSize({m_len,6});
        }
        sf::RectangleShape Get()
        {
            return m_shape;
        };
    };

}