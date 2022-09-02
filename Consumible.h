#pragma once
#include "Base.h"
#include "Laberint.h"
class Consumible : public Base
{
	bool _active;
	bool _type;
public:

	/*
	Descripció: Pintat dels consumibles.
	*/
	void render();

	/*
	Descripció: Li dona un tipus al consumible.
	Entrada: Un boolea, true si es espasa, false si es vida.
	*/
	void setType(bool T) { _type = T; };

	/*
	Descripció: Et diu si el consumible esta actiu o no.
	Retorna: Un boolea.
	*/
	bool isActive() { return _active; };

	/*
	Descripció: Et diu si es una espasa o una vida.
	Retorna: Un boolea.
	*/
	bool isSword() { return _type; };

	Consumible();
	~Consumible();
};

