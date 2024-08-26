#pragma once
#include <SFML/Graphics.hpp>
namespace ag
{
    class Triangle
    {
        float m_r;
        float m_x, m_y;
        sf::CircleShape m_shape;
    public:
        Triangle() = default;

        Triangle(float x, float y, float r)
        {
            Setup(x,y,r);
        }
        void Setup(float x, float y, float r)
        {
            m_x = x;
            m_y = y;
            m_r = r;
            m_shape.setRadius(m_r);
            m_shape.setPosition(m_x,m_y);
            m_shape.setPointCount(3);
            m_shape.setFillColor(sf::Color(0,255,0,255));
        }
        sf::CircleShape Get()
        {
            return m_shape;
        };
    };

}
