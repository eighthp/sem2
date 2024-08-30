#include <iostream>
#include <fstream>
#include <string>
#include <time.h>


int main()
{
    int n = 0;   // ���������� ����� ������
    std::ifstream fin("input.txt");
    std::string line;
    while (getline(fin, line))
    {
        n++;
    }

    struct tm* u; // ��������� ��� �������

    char s1[21] = { 0 };  // ������ ��� ������ �� ��������
    const time_t timer = time(NULL);  // ����� �������. ���������� ��� � 1 ������ 1970
    u = localtime(&timer);  // ����������� � ��� ����� ���� ...
    strftime(s1, sizeof(s1), "%Y-%m-%d %H:%M:%S ", u);
    std::cout << n;
    std::ofstream fout("input.txt", std::ios::app);
    if (fout.is_open())
    {
        fout << n+1 << " : " << s1 << std::endl;
    }
    fout.close();
}