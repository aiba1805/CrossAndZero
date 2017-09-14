#include"game.h"
#include"functions.h"
#include"console.h"
#include<iostream>
#include<conio.h>
using namespace std;
void Init(Field& fl) {
	fl.field = new char*[fl.x];
	for (int i = 0; i < fl.x; ++i) {
		fl.field[i] = new char[fl.y];
	}
}
void Filling(Field& fl) {
	for (int i = 0; i < fl.x; ++i) {
		for (int j = 0; j < fl.y; ++j) {
			fl.field[i][j] = '$';
		}
	}
}
void Print(Field& fl) {
	for (int i = 0; i < fl.x; ++i) {
		for (int j = 0; j < fl.y; ++j) {
			cout << fl.field[i][j];
		}
		cout << endl;
	}
}
void StartGame(Field& fl) {
	Print(fl);
	Position pt;
	pt.X = 0;
	pt.Y = 0;
	int key;
	char symbol;
	bool firstPlayer = true;

	for (;;) {
		if (_kbhit()) {
			key = _getch();
			if (firstPlayer) {
				symbol = 'O';
				if (Handler(pt, fl, key, symbol)) {
					if (fl.field[pt.X][pt.Y] == symbol) {
						SetPos(pt.X, pt.Y);
						cout << 'O';
						firstPlayer = false;
					}
				}
				if (Winner(fl, symbol)) {
					break;
				}
			}
			else {
				symbol = 'X';
				if (Handler(pt, fl, key, symbol)) {
					if (fl.field[pt.X][pt.Y] == symbol) {
						SetPos(pt.X, pt.Y);
						cout << 'X';
						firstPlayer = true;
					}
				}
				if (Winner(fl, symbol)) {
					break;
				}
			}

		}
	}
}
void Delete(Field& fl) {
	for (int i = 0; i < fl.x; ++i) {
		delete[] fl.field[i];
	}
	delete[] fl.field;
}
bool Handler(Position& pt, Field& fl, int key, char s) {
	if (key == ENTER) {
		if (!(fl.field[pt.X][pt.Y] == 'O' || fl.field[pt.X][pt.Y] == 'X')) {
			fl.field[pt.X][pt.Y] = s;
			return true;
		}
		else {
			return false;
		}
	}
	if (_kbhit()) {
		key = _getch();
		if (key == ARROW_UP && pt.Y > 0) {
			pt.Y--;
			SetPos(pt.X, pt.Y);
			return true;
		}
		else if (key == ARROW_DOWN && pt.Y < fl.y - 1) {
			pt.Y++;
			SetPos(pt.X, pt.Y);
			return true;
		}
		else if (key == ARROW_LEFT && pt.X > 0) {
			pt.X--;
			SetPos(pt.X, pt.Y);
			return true;
		}
		else if (key == ARROW_RIGHT && pt.X < fl.x - 1) {
			pt.X++;
			SetPos(pt.X, pt.Y);
			return true;
		}

	}
	return false;
}
bool IfWin(Field fl, char symbol) {
	int firstDiagonal = 0, secondDiagonal = 0;
	for (int i = 0, j = fl.x - 1; i < fl.x; i++, j--) {
		firstDiagonal += fl.field[i][i];
		secondDiagonal += fl.field[i][j];
	}
	if (firstDiagonal == symbol * 3 || secondDiagonal == symbol * 3) { return true; }
	for (int i = 0; i < fl.x; i++) {
		secondDiagonal = 0;
		for (int j = 0; j < fl.y; j++) {
			secondDiagonal += fl.field[i][j];
		}
		if (secondDiagonal == symbol * 3) { return true; }
	}

	for (int i = 0; i < fl.y; i++) {
		secondDiagonal = 0;
		for (int j = 0; j < fl.x; j++) {
			secondDiagonal += fl.field[j][i];
		}
		if (secondDiagonal == symbol * 3) { return true; }
	}
	return false;
}
bool Winner(Field&fl, char symbol) {
	if (IfWin(fl, symbol)) {
		Filling(fl);
		SetPos(fl.x + 5, fl.y + 5);
		cout << "Победитель "<<symbol << endl;
		cout << "Нажмите чтобы продолжить" << endl;
		cin.get();
		system("cls");
		return true;
	}
	return false;
}
void EazyGame(Field& fl) {
	SetPos(0, 0);
	Print(fl);
	Position pt;
	pt.X = 0;
	pt.Y = 0;
	int key;
	char symbol;
	bool firstPlayer = true;

	for (;;) {
		if (_kbhit()) {
			key = _getch();
			if (firstPlayer) {
				symbol = 'O';
				if (Handler(pt, fl, key, symbol)) {
					if (fl.field[pt.X][pt.Y] == symbol) {
						SetPos(pt.X, pt.Y);
						cout << 'O';
						firstPlayer = false;
					}
				}
				if (Winner(fl, symbol)) {
					break;
				}

			}
			else {
				symbol = 'X';
				do {
					do {
						pt.X = rand()%fl.x;
					} while (!(pt.X >= 0 && pt.X <= fl.x));
					do {
						pt.Y = rand() % fl.y;
					} while (!(pt.Y >= 0 && pt.Y <= fl.y));
				} while ((fl.field[pt.X][pt.Y] == 'O'));
				fl.field[pt.X][pt.Y] = 'X';
				if (fl.field[pt.X][pt.Y] == symbol) {
					SetPos(pt.X, pt.Y);
					cout << 'X';
					firstPlayer = true;
				}
				if (Winner(fl, symbol)) {
					break;
				}
			}

		}
	}
}