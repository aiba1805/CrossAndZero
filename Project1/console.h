#pragma once
#include <Windows.h>

enum
{
	ESC = 27, ENTER = 13, ARROW_UP = 72, ARROW_DOWN = 80, F1=33,ARROW_RIGHT=77,ARROW_LEFT=75
};

class console
{
public:
	console();
	~console();

	// ������� ��� ������ �����
	void SetColor(WORD wAttributes) {// ������� ��� ����� �����
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, wAttributes);
	}

	// ������� ��� ������ �������
	void SetPos(COORD dwCursorPosition) {// ������� ��� ��������� ������� ������� �� �����������
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwCursorPosition);
	}

	// ������� ��� ������ �������
	void SetPos(int x, int y) {
		COORD cd;
		cd.X = x;
		cd.Y = y;
		SetPos(cd);
	}
};

