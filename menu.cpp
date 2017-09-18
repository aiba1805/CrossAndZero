#include "menu.h"
#include <iostream>

menu::menu()
{
	count = 0;
	pos = 1;
	x = 0;
	y = 0;
	color_main = 0x4;
	color_activ = 0x8;
	arrow = ' ';
}


menu::~menu()
{
}

void menu::SetMainColor(int color) {
	if(color>=0 && color<=15)
		color_main = color;
}

void menu::SetActivColor(int color) {
	if (color >= 0 && color <= 15)
		color_activ = color;
}

void menu::SetPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

void menu::SetPositionX(int x) {
	this->x = x;
}

void menu::SetPositionY(int y) {
	this->y = y;
}

// Узнаём активную позицию
int menu::GetActivPosition() {
	return pos;
}

// Узнаём активную позицию сравнивая с переданной строкой
bool menu::isActivPosition(string data) {
	auto pi = this->data.begin();
	advance(pi, pos-1);
	if (!pi->compare(data))
		return true;
	return false;
}

// Добавляем пункт меню
void menu::Add(string data) {
	this->data.push_back(data);
	count++;
}

// Очищаем экран от меню
void menu::Clear() {
	int len,i=0;
	for (auto it = data.begin(); it != data.end(); it++) {
		SetPos(x, y+i++);
		len = it->size();
		for (int i = 0; i <= len; i++) { cout << " "; }
	}
}

void menu::SetArrow(char s) {
	arrow = s;
}

// Отображаем меню на экране
void menu::Print() {
	Clear();
	int len, i = 0;
	for (auto it = data.begin(); it != data.end(); it++) {
		SetPos(x, y + i);
		if (i++ == pos - 1) {// Активный пункт меню
			SetColor(color_activ);
			cout << arrow <<*it;
		}
		else {//Неактивный пункт меню
			SetColor(color_main);
			cout << ' ' << *it;
		}
	}
	SetColor(0x7);
}

void menu::handler(int key) {
	if (key == ARROW_UP) {
		if (pos > 1) {
			pos--;
		}
		else {
			pos = count;
		}
		Print();
	}
	else if (key == ARROW_DOWN) {
		if (pos < count) {
			pos++;
		}
		else {
			pos = 1;
		}
		Print();
	}
}