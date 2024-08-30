#include <iostream>
#include <string.h>
#include <algorithm>
class String {
private:
    char *str;
    int m_len;
public:
    // �����������
    String(int len)
    {
        m_len = len;
        str = new char[len];
    };

    // ����������� �����������
    String(const String &other) : String(other.m_len) {
        for (int i = 0; i < m_len; i++)
            str[i] = other.str[i];
    }

    // �������� ������������
    String &operator=(const String& other)
    {
//      String copy{assignment};
//      std::swap(m_len, copy.m_len);
//      std::swap(str, copy.str);
        delete[] str;
        m_len = other.m_len;
        str = new char[m_len];
        for (int i = 0; i < m_len; i++)
            str[i] = other.str[i];

        return *this;
    }

    void stringout()
    {
        std::cout << m_len << std::endl;
    }
    // ����������
    ~String()
    {
        delete[] str;
    }
};


int main()
{
    String A(5);
    A.stringout();
    String B(2);

    String C(B); // Copy
    C.stringout();

    B = A; // Assignment
    B.stringout();


    return 0;
}