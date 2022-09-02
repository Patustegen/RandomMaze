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
	Descripció: Crea el laberint.
	*/
	void init();

	/*
	Descripció: Pintat del laberint, un color per passadís, un altre per les parets.
	*/
	void render();

	/*
	Descripció: Funció que et diu si estas al final.
	Entrada: Una posició X i una posició Y.
	Retorna: True si estas al final, false si no hi ets.
	*/
	bool isFinal(int x, int y);

	/*
	Descripció: Funció que et diu que hi ha en aquella posició del laberint.
	Entrada: Una posició X i una posició Y.
	Retorna: True si hi ha paret, false si no hi ha paret.
	*/
	bool isParet(int x, int y) { return mapaReal[y][x]; };

	/*
	Descripció: Funció que et torna la posició X inicial.
	Retorna: Retorna la posició X en un int.
	*/
	int getInitX() { return _pX; };

	/*
	Descripció: Funció que et torna la posició Y inicial.
	Retorna: Retorna la posició Y en un int.
	*/
	int getInitY() { return _pY; };

	Laberint();
	~Laberint();
};

