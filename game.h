#pragma once
#ifndef FIELD_CPP_08092017
#define FIELD_CPP_08092017
struct Field {
	char** field;
	int x, y;
	bool** thereIsforO;
	bool** thereIsforX;
};
struct Position {
	int X;
	int Y;
};
void Init(Field& fl);
void Delete(Field& fl);
void Print(Field& fl);
void StartGame(Field& fl, bool comp = false, int level = 1);
bool Handler(Position& pt, Field& fl, int key, char s);
bool IfWin(Field fl, char symbol);
bool IfDraw(Field fl);
bool Result(Field& fl, char symbol);
void Filling(Field&fl);
#endif