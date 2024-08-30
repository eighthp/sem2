#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
namespace ag
{
    class Ship
    {
        float m_x, m_y;
        float m_alfa;
        float m_v;
        sf::Texture m_textureShip;
        sf::Sprite m_spriteShip;
    public:
        Ship() = default;

        bool Setup(float x, float y)
        {
            m_x = x;
            m_y = y;
            m_alfa = 0;
            m_v = 0;
            // Загрузка текстуры фона
            if (!m_textureShip.loadFromFile(
                    "assets\\ship.png")) {
                std::cout << "Error while loading ship.png" << std::endl;
                return false;
            }
            m_spriteShip.setTexture(m_textureShip);
            m_spriteShip.scale(0.45f,0.45f);
            m_spriteShip.setOrigin(m_textureShip.getSize().x/2,m_textureShip.getSize().y/2);
            m_spriteShip.setPosition(m_x,m_y);
            m_spriteShip.setRotation(m_alfa);
            return true;
        }

        void setVelocity(float dv)
        {
            m_v += dv;

        }
        void Move(float dv)
        {
            float alphaRad = acos(-1) * m_alfa / 180;
            m_x +=m_v*cos(alphaRad);
            m_y +=m_v*sin(alphaRad);
            m_spriteShip.setPosition(m_x,m_y);
        }
        void Rotate(float dalfa)
        {
            m_alfa += dalfa;
            m_spriteShip.setRotation(m_alfa);
        }
        sf::Sprite Get()
        {
            return m_spriteShip;
        }
    };

}