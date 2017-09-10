#pragma once
/*
	Отображение меню
	Перемещение по меню
	Выбор пункта меню
*/
#include <vector>
#include <string>
#include "console.h"
using namespace std;

class menu:public console
{
	int count;// Количество пунктов меню
	int pos;// Позиция активного пункта меню
	int x;// Координата по Х для отображения меню
	int y;// Координата по Y для отображения меню
	int color_main;// Цвет пунктов меню
	int color_activ;// Цвет активного пункта меню
	char arrow;//Символ стрелки
	vector<string> data;// Меню
public:
	menu();
	~menu();
	void SetArrow(char s);
	void SetMainColor(int color);
	void SetActivColor(int color);
	void SetPosition(int x, int y);
	void SetPositionX(int x);
	void SetPositionY(int y);
	void Clear();// Очищаем экран от меню
	void Print();// Отображаем меню на экране
	void Add(string data);// Добавляем пункт меню
	int GetActivPosition();// Узнаём активную позицию
	bool isActivPosition(string data);// Узнаём активную позицию
	void handler(int key);// Обработчик меню
};

