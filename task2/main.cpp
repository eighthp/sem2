#include <math.h>
#include <iostream>

class Rectangle
{
private:
    float m_x;
    float m_y;

public:
    Rectangle() = default;
    Rectangle (float x, float y)
    {
        setX(x);
        setY(y);
    }
    void setX(float x)
    {
        if (x <= 0)
            std::cout << "Invalid value entered x" << std::endl;
        m_x = x;
    }
    void setY(float y)
    {
        if (y <= 0)
            std::cout << "Invalid value entered y" << std::endl;
        m_y = y;
    }
    double perimeter() {return (m_x+m_y)*2;}
    double square() {return (m_x*m_y);}
    double diagonal() {return sqrt(pow(m_x,2) + pow(m_y,2));}
};


int main()
{
    Rectangle x(3.4,8);
    std::cout << x.perimeter() << std::endl;
    std::cout << x.square() << std::endl;
    std::cout << x.diagonal() << std::endl;

    return 0;
}
