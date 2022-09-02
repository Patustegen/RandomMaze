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
	Descripci�: Moviment dels enemics, colisi�, etc...
	*/
	void update();

	/*
	Descripci�: Pintat dels enemics.
	*/
	void render();

	Soldat();
	~Soldat();
};

