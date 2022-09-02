#pragma once
#include "Base.h"
#include <vector>
#include "Consumible.h"
#include "Laberint.h"

class Soldat : public Base
{
	int contador;
public:

	/*
	Descripció: Moviment dels enemics, colisió, etc...
	*/
	void update();

	/*
	Descripció: Pintat dels enemics.
	*/
	void render();

	Soldat();
	~Soldat();
};

