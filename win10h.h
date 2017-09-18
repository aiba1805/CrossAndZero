#pragma once
#include <Windows.h>
#include <stdio.h>
typedef BOOL(WINAPI *SETCONSOLEFONT)(HANDLE, DWORD);
typedef BOOL(WINAPI *SETCURRENTCONSOLEFONTEX)(HANDLE, BOOL, PCONSOLE_FONT_INFOEX);
SETCONSOLEFONT SetConsoleFont;


void start(int row, int column) {
	OSVERSIONINFOEX osvi;
	CONSOLE_FONT_INFOEX cfon;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	GetVersionEx((OSVERSIONINFO *)&osvi);
	HMODULE hmod = GetModuleHandleA("KERNEL32.DLL");
	if (osvi.dwMajorVersion<6) {
		SetConsoleFont = (SETCONSOLEFONT)GetProcAddress(hmod, "SetConsoleFont");
		if (!SetConsoleFont) { exit(1); }
		SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
	else
	{
		if (!SetCurrentConsoleFontEx) { exit(1); }
		ZeroMemory(&cfon, sizeof(CONSOLE_FONT_INFOEX));

		cfon.cbSize = sizeof(CONSOLE_FONT_INFOEX);
		cfon.nFont = 5;
		cfon.FontFamily = 0;
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfon);
	}
	char buf[256] = { 0 };
	sprintf(buf, "mode con cols=%d lines=%d", column, row);
	system(buf);
	system("cls");
}