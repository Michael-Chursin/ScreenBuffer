#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

int main()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	const string text = "string";
	WORD attributes[6];
	attributes[0] = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE;
	attributes[1] = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE;
	attributes[2] = FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	attributes[3] = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED;
	attributes[4] = FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	attributes[5] = FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	DWORD dwWritten;
	COORD coords;
	CONSOLE_SCREEN_BUFFER_INFO buf;
	coords.X = 6;
	coords.Y = 9;
	WriteConsoleOutputCharacterA(hStdOut, text.c_str(), text.size(), coords, &dwWritten);
	WriteConsoleOutputAttribute(hStdOut, &attributes[0], text.size(), coords, &dwWritten);
	GetConsoleScreenBufferInfo(hStdOut, &buf);
	WORD a;
	DWORD dwRead;
	coords.X += 2;
	ReadConsoleOutputAttribute(hStdOut, &a, 1, coords, &dwRead);
	cout << dec << a << endl;
	return 0;
}