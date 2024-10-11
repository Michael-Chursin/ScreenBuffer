#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    HANDLE hStdOutOld, hStdOutNew;
    DWORD dwWritten;
    hStdOutNew = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    if (hStdOutNew == INVALID_HANDLE_VALUE) {
        cout << "Creating screen buffer failed" << endl;
        cin.get();
        return GetLastError();
    }
    hStdOutOld = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Press any key to switch to a new buffer" << endl;
    cin.get();
    if (!SetConsoleActiveScreenBuffer(hStdOutNew)) {
        cout << "Setting new screen buffer failed" << endl;
        cin.get();
        return GetLastError();
    }
	string line;
    string l = "";
	ifstream in("C:/Users/217560/Desktop/input.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            l += line;
        }
    }
    if (!WriteConsole(hStdOutNew, &l, l.size(), &dwWritten, NULL)) {
        cout << "Write console failed" << endl;
        cin.get();
        return GetLastError();
    }
    cout << "\n\nPress any key to switch to a old buffer" << endl;
    cin.get();
    if (!SetConsoleActiveScreenBuffer(hStdOutOld)) {
        cout << "\nSetting old screen buffer failed" << endl;
        cin.get();
        return GetLastError();
    }
    cout << "\nThis is old screen buffer";
    CloseHandle(hStdOutNew);
    in.close();
	return 0;
}
