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
	Descripci�: Inicia les posicions en llocs valids..
	*/
	void init();

	/*
	Descripci�: Guarda un punter al laberint.
	Entrada: Punter al laberint.
	*/
	void setLab(Laberint *L) { mpLab = L; };

	/*
	Descripci�: Funci� que retorna la posici� X.
	Retorna: Un valor int.
	*/
	int getX() { return _pX; };

	/*
	Descripci�: Funci� que retorna la posici� Y.
	Retorna: Un valor int.
	*/
	int getY() { return _pY; };

	/*
	Descripci�: Funci� que et diu si has colisionat.
	Entrada: Una posici� X i una posici� Y.
	Retorna: True si ha xocat, false si no.
	*/
	bool isColision(int x, int y);
};

