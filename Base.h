#pragma once
#include "Laberint.h"

using namespace std;
class Base
{
protected:
	int _pX;
	int _pY;
	Laberint *mpLab;
public:
	Base();
	~Base();

	/*
	Descripció: Inicia les posicions en llocs valids..
	*/
	void init();

	/*
	Descripció: Guarda un punter al laberint.
	Entrada: Punter al laberint.
	*/
	void setLab(Laberint *L) { mpLab = L; };

	/*
	Descripció: Funció que retorna la posició X.
	Retorna: Un valor int.
	*/
	int getX() { return _pX; };

	/*
	Descripció: Funció que retorna la posició Y.
	Retorna: Un valor int.
	*/
	int getY() { return _pY; };

	/*
	Descripció: Funció que et diu si has colisionat.
	Entrada: Una posició X i una posició Y.
	Retorna: True si ha xocat, false si no.
	*/
	bool isColision(int x, int y);
};

