#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"functions.h"
#include"menu.h"
#include"game.h"
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
	CursorHide();
	menu mn;
	menu comp;
	Field fl;
	mn.Add("������� ������ ����");
	mn.Add("������ � �����������");
	mn.Add("������ � �������");
	mn.Add("�����");
	comp.Add("������");
	comp.Add("�������");
	comp.Add("�������");
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
			if (key == ENTER&&MainMenu&&mn.isActivPosition("������� ������ ����")) {
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
			else if (key == ENTER&&MainMenu&&mn.isActivPosition("������ � �����������")) {
				mn.Clear();
				MainMenu = false;
				comp.Print();
			}
			else if (key == ENTER&&MainMenu&&mn.isActivPosition("������ � �������")) {
				Print(fl,' ');
				char s;
				for (int i = 0; i < (fl.x*fl.y); ++i) {
					SetPos(0,fl.y + 5);
					cout << "������� O" << endl;
					cin >> s;
					
					SetPos(0, fl.y + 10);
					cout << "������� X" << endl;
					cin >> s;
				}
			}
			else if (key == ENTER&&MainMenu&&mn.isActivPosition("�����")) {
				exit(0);
			}
			else if (key == ENTER&&!MainMenu&&mn.isActivPosition("������")) {

			}
			else if (key == ENTER&&!MainMenu&&mn.isActivPosition("�������")) {

			}
			else if (key == ENTER&&!MainMenu&&mn.isActivPosition("�������")) {

			}
		}
	}
	cin.get();
}