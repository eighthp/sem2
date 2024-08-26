#pragma once
#include <string>

namespace ag
{
    class Game
    {
        int m_width;
        int m_height;
        std::string m_capture;
        ag::Circle* m_c;
        ag::Triangle* m_t;
        ag::Line* m_l;
        ag::Rectangle* m_rect;
        int m_n;
        sf::RenderWindow m_window;

    public:
        Game(int width, int height, const std::string& capture)
        {
            m_width = width;
            m_height = height;
            m_capture = capture;
        }
        void Setup(int n)
        {
            m_n = n;
            m_window.create(sf::VideoMode(m_width, m_height),m_capture);
            m_window.setTitle(m_capture);
            srand(time(0));
            m_c = new ag::Circle[m_n];
            m_t = new ag::Triangle[m_n];
            m_l = new ag::Line[m_n];
            m_rect = new ag::Rectangle[m_n];

            ag::Circle* c;
            ag::Triangle* t;
            ag::Line* l;
            ag::Rectangle* rect;
            for (int i=0; i<m_n; i++)
            {
                int x = rand() % 1000;
                int y = rand() % 600;
                int r = rand() % 100 + 1;
                int rot = rand() % (360 + 1);
                int len = rand() % (200 + 5);
                int wid = rand() % (200 + 5);
                m_c[i].Setup(x+600, y, r);
                m_t[i].Setup(x+800+ i * 17, 400 + i * 5, r);
                m_l[i].Setup(x+900+i*13,250+y, rot, len);
                m_rect[i].Setup(60+x,y+30*i,rot,len,wid);

            }
        }
        void LifeCycle()
        {
            while (m_window.isOpen())
            {
                // События
                sf::Event event;

                // Обработка событий (нажатие кнопок, закрытие окна и т.д.)
                while (m_window.pollEvent(event))
                {
                    // Закрыть окно если нажата кнопка "Закрыть"
                    if (event.type == sf::Event::Closed)
                        m_window.close();
                }

                // Очистить окно и залить его черным цветом
                m_window.clear(sf::Color::Black);
                for (int i = 0; i < m_n; i++)
                {
                    m_window.draw(m_c[i].Get());
                    m_window.draw(m_t[i].Get());
                    m_window.draw(m_l[i].Get());
                    m_window.draw(m_rect[i].Get());
                }
                m_window.display();
            }


        }
    };

}