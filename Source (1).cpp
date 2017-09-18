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
�������� ���� ��������-������. ����������� �������� ��������� ������������ � ���� � ������� ������������ ������ �������:
- ������ �������� ���� (����������� 3�3, ������������ 15�15). ��� ��������� �������� ���� ��������� �������� ������� ������� �� ����������
(win10h.h) ������� start
- ����� ���� ����� vs �����, ����� vs ���������
- � ������ ������ ����� vs ��������� ����������� 3 ������ ��������� (����, �������, �������).
˸���� ������ ������ ����������� ��� ������� ������ ������. ������� ������ ���������� �������� � 50% ������� ���
����������� �� ���� �� ������� ������ ��� ����� ������ ����� ��� ������� ������ ������. ������� ������ ������ ���������� ��� ������� ������ ������
��� ���������� ���������� ������������ ��������� ������������ ������ ��� �������� ����. ������ ���� ����������
����� ������������ � ���������� ������, �������� ����� ����������.

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
	mn.Add("������� ������ ����");
	mn.Add("������ � �����������");
	mn.Add("������ � �������");
	mn.Add("�����");
	comp.Add("������");
	comp.Add("�������");
	comp.Add("�������");
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
			if (key == ENTER&&MainMenu&&mn.isActivPosition("������� ������ ����")) {
				mn.Clear();
				cout << "������� ������ ����" << endl;
				cin >> fl.x;
				fl.y = fl.x;
				Init(fl);
				Filling(fl);
				cout << "������� ����� ����������" << endl;
				system("cls");
				mn.Print();
			}
			else if (key == ENTER&&MainMenu&&mn.isActivPosition("������ � �����������")) {
				mn.Clear();
				start(fl.x, fl.y);
				MainMenu = false;
				Comp = true;
				comp.Print();
			}
			else if (key == ENTER&&MainMenu&&mn.isActivPosition("������ � �������")) {
				start(fl.x, fl.y);
				StartGame(fl);
				mn.Print();
			}
			else if (key == ENTER&&MainMenu&&mn.isActivPosition("�����")) {
				exit(0);
			}
			else if (key == ENTER && !MainMenu && comp.isActivPosition("������")) {
				comp.Clear();
				SetPos(0, 0);
				level = 1;
				StartGame(fl,Comp,level);
				comp.Print();
			}
			else if (key == ENTER && !MainMenu&&comp.isActivPosition("�������")) {
				comp.Clear();
				SetPos(0, 0);
				level = 2;
				StartGame(fl, Comp, level);
				comp.Print();
			}
			else if (key == ENTER && !MainMenu&&comp.isActivPosition("�������")) {
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