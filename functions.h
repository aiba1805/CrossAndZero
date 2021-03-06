#pragma once
/*
	***********************************************
	*	������������ ���� � ��������� WIN API	  *
	*	������: 0.01							  *
	*	�����: ���������						  *
	*	email: admin@saa.kz						  *
	*	���� ��������: 03.04.2017 19:38			  *
	***********************************************
	*	���������� ������ ������: 100%			  *
	***********************************************
	*	SetColor - ����� ����� ��� ��������� �	  *
	*			�������							  *
	***********************************************
	*	SetConsoleColor - ����������� �����		  *
	*			���� � ����� ������ ��� SetColor  *
	*	��������������� deprecated �������		  *
	*	� ����� � ����������� ����� ��������	  *
	*	������� color.h							  *
	***********************************************
	*	SetPosMain - ����� ������� � �����		  *
	*			WIN API							  *
	***********************************************
	*	SetPos - ����� ������� ���� ��������	  *
	*			������� �� � � Y				  *
	***********************************************
	*	CursorHide - ������� �������/�������	  *
	***********************************************
	*	CursorShow - ����������� �������/�������  *
	***********************************************
	*	color - ������������ � 16 �����������	  *
	*			�������							  *
	***********************************************

*/
#include <Windows.h>

// ������� ��� ������ �����
void SetColor(WORD wAttributes);

// ������� ��� ������ �������
void SetPosMain(COORD dwCursorPosition);

// ������� ��� ������ �������
void SetPos(int x, int y);

// ������� ��� ������� �������
void CursorHide();

// ������� ��� ����������� �������
void CursorShow();
// ������������� ���� ������ � ����
int SetConsoleColor(int symbolColor, int backgroundColor);
/*
0x1			0x7
0000 0001	0000 0111
0000 0001	0111 0000

0000 0001
|0111 0000
----------
0111 0001

*/

