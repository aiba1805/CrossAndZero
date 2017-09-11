#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"functions.h"
#include"menu.h"
#include"game.h"
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
	CursorHide();
	menu mn;
	menu comp;
	Field fl;
	mn.Add("Выбрать размер поля");
	mn.Add("Играть с компьютером");
	mn.Add("Играть с игроком");
	mn.Add("Выход");
	comp.Add("Легкий");
	comp.Add("Средний");
	comp.Add("Сложный");
	int key;
	mn.Print();
	bool MainMenu = true;
	for (;;) {
		if (kbhit()) {
			key = getch();
			if (MainMenu)
				mn.handler(key);
			else
				comp.handler(key);
			if (key == ENTER&&MainMenu&&mn.isActivPosition("Выбрать размер поля")) {
				mn.Clear();
				cout << "" << endl;
				cin >> fl.x;
				cout << "" << endl;
				cin >> fl.y;
				Init(fl);
				cout << "" << endl;
				system("cls");
				mn.Print();
			}
			else if (key == ENTER&&MainMenu&&mn.isActivPosition("Играть с компьютером")) {
				mn.Clear();
				MainMenu = false;
				comp.Print();
			}
			else if (key == ENTER&&MainMenu&&mn.isActivPosition("Играть с игроком")) {
				Print(fl,' ');
				char s;
				for (int i = 0; i < (fl.x*fl.y); ++i) {
					SetPos(0,fl.y + 5);
					cout << "Введите O" << endl;
					cin >> s;
					
					SetPos(0, fl.y + 10);
					cout << "Введите X" << endl;
					cin >> s;
				}
			}
			else if (key == ENTER&&MainMenu&&mn.isActivPosition("Выход")) {
				exit(0);
			}
			else if (key == ENTER&&!MainMenu&&mn.isActivPosition("Легкий")) {

			}
			else if (key == ENTER&&!MainMenu&&mn.isActivPosition("Средний")) {

			}
			else if (key == ENTER&&!MainMenu&&mn.isActivPosition("Сложный")) {

			}
		}
	}
	cin.get();
}