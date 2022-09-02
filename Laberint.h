#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

struct pos {
	int pY;
	int pX;
};
#define WIDTH 10
#define REAL_WIDTH WIDTH * 3
#define HEIGHT 10
#define REAL_HEIGHT HEIGHT * 3
#define SIZE WIDTH * HEIGHT
#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4
class Laberint
{
	vector<pos> recorrido;
	bool mapaReal[REAL_HEIGHT][REAL_WIDTH];
	int _pX;
	int _pY;
	int _finalX;
	int _finalY;
public:
	/*
	Descripci�: Crea el laberint.
	*/
	void init();

	/*
	Descripci�: Pintat del laberint, un color per passad�s, un altre per les parets.
	*/
	void render();

	/*
	Descripci�: Funci� que et diu si estas al final.
	Entrada: Una posici� X i una posici� Y.
	Retorna: True si estas al final, false si no hi ets.
	*/
	bool isFinal(int x, int y);

	/*
	Descripci�: Funci� que et diu que hi ha en aquella posici� del laberint.
	Entrada: Una posici� X i una posici� Y.
	Retorna: True si hi ha paret, false si no hi ha paret.
	*/
	bool isParet(int x, int y) { return mapaReal[y][x]; };

	/*
	Descripci�: Funci� que et torna la posici� X inicial.
	Retorna: Retorna la posici� X en un int.
	*/
	int getInitX() { return _pX; };

	/*
	Descripci�: Funci� que et torna la posici� Y inicial.
	Retorna: Retorna la posici� Y en un int.
	*/
	int getInitY() { return _pY; };

	Laberint();
	~Laberint();
};

