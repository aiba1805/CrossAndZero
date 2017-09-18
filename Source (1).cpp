#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include"menu.h"
#include"game.h"
#include"functions.h"
#include"win10h.h"

using namespace std;

/*
Написать игру крестики-нолики. Реализовать красивый интерфейс пользователя с меню в котором пользователь сможет выбрать:
- Размер игрового поля (минимальное 3х3, максимальное 15х15). При изменении игрового поля разрешено изменять размеры консоли на подходящие
(win10h.h) функция start
- Режим игры игрок vs игрок, игрок vs компьютер
- В случае выбора игрок vs компьютер реализовать 3 уровня сложности (лёгий, средний, сложный).
Лёгкий должен всегда проигрывать или сводить партию вничью. Средний должен выигрывать примерно в 50% случаях вне
зависимости от того на сколько хорошо или плохо играет игрок или сводить партию вничью. Сложный должен всегда выигрывать или сводить партию вничью
При реализации необходимо использовать двумерный динамический массив для игрового поля. Данную игру необходимо
будет дорабатывать в дальнейших тестах, добавляя новый функционал.

*/

int main() {
	setlocale(LC_ALL, "russian");
	srand(time(0));
	menu mn;
	menu comp;
	Field fl;
	int level;
	bool Comp;
	bool MainMenu = true;
	int key;
	mn.Add("Выбрать размер поля");
	mn.Add("Играть с компьютером");
	mn.Add("Играть с игроком");
	mn.Add("Выход");
	comp.Add("Легкий");
	comp.Add("Средний");
	comp.Add("Сложный");
	mn.Print();
	fl.x = 3;
	fl.y = 3;
	Init(fl);
	Filling(fl);
	
	for (;;) {
		if (_kbhit()) {
			key = _getch();
			if (MainMenu)
				mn.handler(key);
			else
				comp.handler(key);
			if (key == ENTER&&MainMenu&&mn.isActivPosition("Выбрать размер поля")) {
				mn.Clear();
				cout << "Введите размер поля" << endl;
				cin >> fl.x;
				fl.y = fl.x;
				Init(fl);
				Filling(fl);
				cout << "Нажмите чтобы продолжить" << endl;
				system("cls");
				mn.Print();
			}
			else if (key == ENTER&&MainMenu&&mn.isActivPosition("Играть с компьютером")) {
				mn.Clear();
				start(fl.x, fl.y);
				MainMenu = false;
				Comp = true;
				comp.Print();
			}
			else if (key == ENTER&&MainMenu&&mn.isActivPosition("Играть с игроком")) {
				start(fl.x, fl.y);
				StartGame(fl);
				mn.Print();
			}
			else if (key == ENTER&&MainMenu&&mn.isActivPosition("Выход")) {
				exit(0);
			}
			else if (key == ENTER && !MainMenu && comp.isActivPosition("Легкий")) {
				comp.Clear();
				SetPos(0, 0);
				level = 1;
				StartGame(fl,Comp,level);
				comp.Print();
			}
			else if (key == ENTER && !MainMenu&&comp.isActivPosition("Средний")) {
				comp.Clear();
				SetPos(0, 0);
				level = 2;
				StartGame(fl, Comp, level);
				comp.Print();
			}
			else if (key == ENTER && !MainMenu&&comp.isActivPosition("Сложный")) {
				comp.Clear();
				SetPos(0, 0);
				level = 3;
				StartGame(fl, Comp, level);
				comp.Print();
			}
		}
	}
	cin.get();
}