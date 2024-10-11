#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    char c;
    HANDLE hStdOut;
    WORD wAttribute;
    cout << "input any char to change console attributes" << endl;
    cin >> c;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) {
        cout << "Get standard handle failed" << endl;
        return GetLastError();
    }
    wAttribute = BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_INTENSITY;
    if (!SetConsoleTextAttribute(hStdOut, wAttribute)) {
        cout << "Set console attributes failed" << endl;
        return GetLastError();
    }
    cout << "text attributes was changed" << endl;
    return 0;
}

