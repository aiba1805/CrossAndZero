#include"game.h"
#include"functions.h"
#include"console.h"
#include<iostream>
#include<conio.h>
using namespace std;
void Init(Field& fl) {
	fl.field = new char*[fl.x];
	fl.thereIsforO= new bool*[fl.x];
	fl.thereIsforX = new bool*[fl.x];
	for (int i = 0; i < fl.x; ++i) {
		fl.field[i] = new char[fl.y];
		fl.thereIsforO[i] = new bool[fl.y];
		fl.thereIsforX[i] = new bool[fl.y];
	}
}
void Filling(Field& fl) {
	for (int i = 0; i < fl.x; ++i) {
		for (int j = 0; j < fl.y; ++j) {
			fl.field[i][j] = '$';
			fl.thereIsforO[i][j] = false;
			fl.thereIsforX[i][j] = false;
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
void StartGame(Field& fl,bool comp,int level) {
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
					if (fl.field[pt.X][pt.Y] == symbol && !fl.thereIsforO[pt.X][pt.Y]) {
						SetPos(pt.X, pt.Y);
						cout << 'O';
						fl.thereIsforO[pt.X][pt.Y] = true;
						firstPlayer = false;
					}
				}
				if (Result(fl, symbol)) {
					break;
				}
			}
			else {
				symbol = 'X';
				if (!comp) {
					if (Handler(pt, fl, key, symbol)) {
						if (fl.field[pt.X][pt.Y] == symbol && !fl.thereIsforX[pt.X][pt.Y]) {
							SetPos(pt.X, pt.Y);
							cout << 'X';
							fl.thereIsforX[pt.X][pt.Y] = true;
							firstPlayer = true;
						}
					}
				}
				else {
					if (level == 1) {
						int j, i;
						for (i = 0; i < fl.x; ++i) {
							for (j = 0; j < fl.y; ++j) {
								if (!fl.thereIsforO[i][j] && !fl.thereIsforX[i][j]) {
									SetPos(i, j);
									cout << 'X';
									fl.thereIsforX[i][j] = true;
									firstPlayer = true;
									break;
								}
							}
							if (fl.thereIsforX[i][j]) {
								break;
							}
						}
					}
					else if (level == 2) {
						
						do {
							do {
								pt.X = rand() % fl.x;
							} while (!(pt.X >= 0 && pt.X <= fl.x));
							do {
								pt.Y = rand() % fl.y;
							} while (!(pt.Y >= 0 && pt.Y <= fl.y));
						} while ((fl.field[pt.X][pt.Y] == 'O'));

						fl.field[pt.X][pt.Y] = 'X';

						if (fl.field[pt.X][pt.Y] == symbol) {
							SetPos(pt.X, pt.Y);
							cout << 'X';
							fl.thereIsforX[pt.X][pt.Y] = true;
							firstPlayer = true;
						}

					}
					else if (level == 3) {

					}
				}
				if (Result(fl, symbol)) {
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
	int firstSum = 0, secondSum = 0;
	for (int i = 0, j = fl.x - 1; i < fl.x; i++, j--) {
		firstSum += fl.field[i][i];
		secondSum += fl.field[i][j];
	}
	if (firstSum == symbol * fl.x || secondSum == symbol * fl.x) { return true; }
	for (int i = 0; i < fl.x; i++) {
		secondSum = 0;
		for (int j = 0; j < fl.y; j++) {
			secondSum += fl.field[i][j];
		}
		if (secondSum == symbol * fl.x) { return true; }
	}

	for (int i = 0; i < fl.y; i++) {
		secondSum = 0;
		for (int j = 0; j < fl.x; j++) {
			secondSum += fl.field[j][i];
		}
		if (secondSum == symbol * fl.x) { return true; }
	}
	return false;
}
bool IfDraw(Field fl) {
	int count = 0;
	for (int i = 0; i < fl.x; ++i) {
		for (int j = 0; j < fl.y; ++j) {
			if (fl.thereIsforO[i][j] == true|| fl.thereIsforX[i][j] == true) {
				count++;
			}
		}
	}
	if (count == (fl.x*fl.y)) {
		return true;
	}
	return false;
}
bool Result(Field&fl, char symbol) {
	if (IfWin(fl, symbol)) {
		Filling(fl);
		SetPos(fl.x + 5, fl.y + 5);
		cout << "Победитель "<<symbol << endl;
		cout << "Нажмите чтобы продолжить" << endl;
		cin.get();
		system("cls");
		return true;
	}
	else if (IfDraw(fl)) {
		Filling(fl);
		SetPos(fl.x + 5, fl.y + 5);
		cout << "Ничья"<<endl;
		cout << "Нажмите чтобы продолжить" << endl;
		cin.get();
		system("cls");
		return true;
	}
	return false;
}