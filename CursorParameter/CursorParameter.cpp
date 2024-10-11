#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    char c;
    HANDLE hStdOut;
    CONSOLE_CURSOR_INFO cci;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!GetConsoleCursorInfo(hStdOut, &cci)) {
        cout << "Get console cursor failed" << endl;
    }
    cout << "Size: " << cci.dwSize << endl;
    cout << "Visibility: " << cci.bVisible << endl;
    cout << "Input size of cursor: " << endl;
    cin >> cci.dwSize;
    if (!SetConsoleCursorInfo(hStdOut, &cci)) {
        cout << "Set cursor size failed" << endl;
        return GetLastError();
    }
    cci.bVisible = FALSE;
    if (!SetConsoleCursorInfo(hStdOut, &cci)) {
        cout << "Set cursor visibility failed" << endl;
        return GetLastError();
    }
    cout << "Abracadabra - now cursor is invisible" << endl;
    cout << "input any char to make cursor visible" << endl;
    cin >> c;
    cci.bVisible = TRUE;
    if (!SetConsoleCursorInfo(hStdOut, &cci)) {
        cout << "Set cursor visibility failed" << endl;
        return GetLastError();
    }
    cout << "Peek-a-boo, cursor is back";
    return 0;
}
