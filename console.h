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

	// Функция для выбора цвета
	void SetColor(WORD wAttributes) {// функция для смена цвета
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, wAttributes);
	}

	// Функция для выбора позиции
	void SetPos(COORD dwCursorPosition) {// функция для установки позиции каретки по координатам
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwCursorPosition);
	}

	// Функция для выбора позиции
	void SetPos(int x, int y) {
		COORD cd;
		cd.X = x;
		cd.Y = y;
		SetPos(cd);
	}
};

