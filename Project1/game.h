#pragma once
#ifndef FIELD_CPP_08092017
#define FIELD_CPP_08092017
struct Field {
	char** field;
	int x, y;
};
struct Position {
	int X;
	int Y;
};
void Init(Field& fl);
void Delete(Field& fl);
void Print(Field& fl);
void StartGame(Field& fl);
bool Handler(Position& pt, Field& fl, int key, char s);
bool IfWin(Field fl, char symbol);
bool Winner(Field& fl, char symbol);
void EazyGame(Field &fl);
void Filling(Field&fl);
#endif