#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    char c;
    HANDLE hSTdOut;
    COORD coord;
    hSTdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "input x" << endl;
    cin >> coord.X;
    cout << "input y" << endl;
    cin >> coord.Y;
    if (!SetConsoleCursorPosition(hSTdOut, coord)) {
        cout << "Set cursor position failed" << endl;
        return GetLastError();
    }
    cout << "Input any char to exit" << endl;
    cin >> c;
    return 0;
}