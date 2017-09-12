#include"game.h"
#include"functions.h"
#include<iostream>
using namespace std;
void Init(Field& fl) {
	fl.field = new char*[fl.x];
	for (int i = 0; i < fl.x; ++i) {
		fl.field[i] = new char[fl.y];
	}
}
void Print(Field& fl,char s) {
	for (int i = 0; i < fl.x; ++i) {
		for (int j = 0; j < fl.y; ++j) {
			cout << fl.field[i][j]<<"\t";
		}
		cout << endl;
	}
}
void StartGame(Field& fl) {

}
void Delete(Field& fl) {
	for (int i = 0; i < fl.x; ++i) {
		delete[] fl.field[i];
	}
	delete[] fl.field;
}