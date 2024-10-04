#include <Windows.h>
#include <conio.h>

int main()
{
	HANDLE hStdOutOld, hStdOutNew;
	DWORD dwWritten;
	hStdOutNew = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (hStdOutNew == INVALID_HANDLE_VALUE) {
		_cputs("Creating screen buffer failed");
		return GetLastError();
	}
	hStdOutOld = GetStdHandle(STD_INPUT_HANDLE);
	_cputs("Press any key to set new screen buffer active");
	getch();
	if (!SetConsoleActiveScreenBuffer(hStdOutNew)) {
		_cputs("Setting new screen buffer failed");
		return GetLastError();
	}
	char text[] = "this is new text buffer";
	if (!WriteConsole(hStdOutNew, text, sizeof(text), &dwWritten, NULL)) {
		_cputs("Write console 1 failed");
		return GetLastError();
	}
	char str[] = "\nPress any key to set old screen buffer";
	if (!WriteConsole(hStdOutNew, str, sizeof(str), &dwWritten, NULL)) {
		_cputs("Write console 2 failed");
		return GetLastError();
	}
	getch();
	if (!SetConsoleActiveScreenBuffer(hStdOutOld)) {
		_cputs("Setting old screen buffer failed");
		return GetLastError();
	}
	_cputs("This is old screen buffer");
	CloseHandle(hStdOutNew);
	_cputs("Press any key to finish");
	getch();
}

