#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    char c;
    HANDLE hStdOut;
    WORD wAttribute;
    DWORD dwLength, dwWritten;
    COORD coord;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    cout << "input any char to change console parameters" << endl;
    cin >> c;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) {
        cout << "Get standard handle failed" << endl;
        return GetLastError();
    }
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        cout << "Get standard handle failed" << endl;
        return GetLastError();
    }
    dwLength = csbi.dwSize.X * csbi.dwSize.Y;
    coord.X = 0;
    coord.Y = 0;
    wAttribute = BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    if (!FillConsoleOutputAttribute(hStdOut, wAttribute, dwLength, coord, &dwWritten)) {
        cout << "fill console failed" << endl;
        return GetLastError();
    }
    cout << "Console colors was changed" << endl;
    return 0;
}