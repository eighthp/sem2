#pragma once
#include <string>
#include <thread>
#include <math.h>
#include <iostream>
#include <Ship.hpp>
namespace ag
{
    const float pi = acos(-1);
    class Game
    {
        int m_width;
        int m_height;
        std::string m_capture;
        ag::Circle* m_c;
        int m_n;
        sf::RenderWindow m_window;
        sf::Texture m_textureBackground;
        sf::Sprite m_spriteBackground;
        Ship m_ship;
        sf::Font m_font;
        sf::Text m_fpsText;

    public:
        Game(int width, int height, const std::string& capture)
        {
            m_width = width;
            m_height = height;
            m_capture = capture;
        }

        bool Setup(int n)
        {

            m_n = n;
            // Создание окна
            m_window.create(sf::VideoMode(m_width, m_height), m_capture);
            m_window.setFramerateLimit(120);
            // Загрузка текстуры фона
            if (!m_textureBackground.loadFromFile("assets\\maxresdefault.png"))
            {
                std::cout << "Error while loading maxresdefault.png" << std::endl;
                return false;
            }
            m_spriteBackground.setTexture(m_textureBackground);

            // Загрузка шрифта
            if (!m_font.loadFromFile("assets\\ArialRegular.ttf"))
            {
                std::cout << "Error while loading arial.ttf" << std::endl;
                return false;
            }
            m_fpsText.setFont(m_font);

            // Создание корабля игрока
            if (!m_ship.Setup(100,100))
                return false;

            srand(time(0));

            m_c = new ag::Circle[m_n];
            for (int i = 0; i < m_n; i++)
            {
                int r = rand() % 100 + 1;
                int x = rand() % (1000 - 2 * r) + r;
                int y = rand() % (600 - 2 * r) + r;
                int v = rand() % 50 + 20;
                float alfa = rand() % 7;
                m_c[i].Setup(x, y, r, v, alfa);
            }
            return true;
        }

        void TouchBorder(Circle& obj)
        {
            float x = obj.X();
            float y = obj.Y();
            float r = obj.R();

            if(x+r >= m_width || x - r <= 0)
            {
                obj.Alfa(pi - obj.Alfa());
            }
            if (y+r >= m_height || y - r <= 0)
            {
                obj.Alfa(2*pi - obj.Alfa());
            }
        }

        void LifeCycle()
        {
            sf::Clock clock;
            float fps = 100;
            int fpstextviewcnt = 0;

            while (m_window.isOpen())
            {
                sf::Event event;
                while (m_window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        m_window.close();
                }
                // Обработка клавиатуры
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    m_ship.setVelocity(0.05);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    m_ship.setVelocity(-0.05);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    m_ship.Rotate(-2);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    m_ship.Rotate(2);
                }


                // Логика
                float dt = clock.getElapsedTime().asSeconds();
                /* if(1/fps > dt)
                {
                    sf::Time t = sf::seconds(1 / fps - dt);
                    sf::sleep(t);
                }
                dt = clock.getElapsedTime().asSeconds();
                std::cout << 1 / dt << std::endl;
                */
                //std::this_thread::sleep_for(std::chrono::seconds(1000));
                clock.restart();
                fpstextviewcnt++;
                if (fpstextviewcnt > fps)
                {
                    fpstextviewcnt = 0;
                    m_fpsText.setString(std::to_string(int(1/dt)));
                }
                //std::cout << 1 / dt << std::endl;

                // Перемещение корабля
                m_ship.Move(0.001);

                // Перемещение шарика
                for (int i = 0; i < m_n; i++)
                    m_c[i].Move(dt);
                // Перемещение шарика
                for (int i = 0; i < m_n; i++)
                    TouchBorder(m_c[i]);

                // Отображение
                m_window.clear();
                m_window.draw(m_spriteBackground);
                m_window.draw(m_ship.Get());
                m_window.draw(m_fpsText);
                for (int i = 0; i < m_n; i++)
                    m_window.draw(m_c[i].Get());
                m_window.display();
            }
        }
    };
}