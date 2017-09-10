#pragma once
/*
	����������� ����
	����������� �� ����
	����� ������ ����
*/
#include <vector>
#include <string>
#include "console.h"
using namespace std;

class menu:public console
{
	int count;// ���������� ������� ����
	int pos;// ������� ��������� ������ ����
	int x;// ���������� �� � ��� ����������� ����
	int y;// ���������� �� Y ��� ����������� ����
	int color_main;// ���� ������� ����
	int color_activ;// ���� ��������� ������ ����
	char arrow;//������ �������
	vector<string> data;// ����
public:
	menu();
	~menu();
	void SetArrow(char s);
	void SetMainColor(int color);
	void SetActivColor(int color);
	void SetPosition(int x, int y);
	void SetPositionX(int x);
	void SetPositionY(int y);
	void Clear();// ������� ����� �� ����
	void Print();// ���������� ���� �� ������
	void Add(string data);// ��������� ����� ����
	int GetActivPosition();// ����� �������� �������
	bool isActivPosition(string data);// ����� �������� �������
	void handler(int key);// ���������� ����
};

