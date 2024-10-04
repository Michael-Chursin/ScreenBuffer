#include <iostream>
#include <Windows.h>

int main()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        std::cout << "Getting console buffer info failed" << std::endl;
    }
    std::cout << "Console buffer info:" << std::endl;
    std::cout << "Number of columns: " << csbi.dwSize.X << std::endl;
    std::cout << "Number of rows: " << csbi.dwSize.Y << std::endl;
    std::cout << "Cursor X: " << csbi.dwCursorPosition.X << std::endl;
    std::cout << "Cursor Y: " << csbi.dwCursorPosition.Y << std::endl;
    std::cout << "Attributes: " << std::hex << csbi.wAttributes << std::dec << std::endl;
    std::cout << "Upper corner: " << csbi.srWindow.Top << " , " << csbi.srWindow.Left << std::endl;
    std::cout << "Lower corner: " << csbi.srWindow.Bottom << " , " << csbi.srWindow.Right << std::endl;
    std::cout << "Maximum number of columns: " << csbi.dwMaximumWindowSize.X << std::endl;
    std::cout << "Maximum number of rows: " << csbi.dwMaximumWindowSize.Y << std::endl;
    return 0;
}

