#pragma once
#ifndef FIELD_CPP_08092017
#define FIELD_CPP_08092017
struct Field {
	char** field;
	int x, y;
};

void Init(Field& fl);
void Delete(Field& fl);
void Print(Field& fl,char s);
void StartGame(Field& fl);
#endif