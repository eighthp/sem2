#include <iostream>
#include <fstream>
#include <string>
#include <time.h>


int main()
{
    int n = 0;   // порядковый номер строки
    std::ifstream fin("input.txt");
    std::string line;
    while (getline(fin, line))
    {
        n++;
    }

    struct tm* u; // структура для времени

    char s1[21] = { 0 };  // массив для строки со временем
    const time_t timer = time(NULL);  // время запуска. количество сек с 1 января 1970
    u = localtime(&timer);  // преобразуем в год месяц день ...
    strftime(s1, sizeof(s1), "%Y-%m-%d %H:%M:%S ", u);
    std::cout << n;
    std::ofstream fout("input.txt", std::ios::app);
    if (fout.is_open())
    {
        fout << n+1 << " : " << s1 << std::endl;
    }
    fout.close();
}