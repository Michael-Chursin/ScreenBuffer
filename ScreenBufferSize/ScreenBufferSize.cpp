#include <iostream>
#include <Windows.h>

int main()
{
    COORD coord;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "Set new console size:" << std::endl;
    std::cout << "X:" << std::endl;
    std::cin >> coord.X;
    std::cout << "Y:" << std::endl;
    std::cin >> coord.Y;
    if (!SetConsoleScreenBufferSize(hStdOut, coord)) {
        std::cout << "Set new console size file failed" << std::endl;
        return GetLastError();
    }
    return 0;
}

