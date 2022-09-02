#include "Consumible.h"
#include "ConsoleControl.h"
#include <iostream>

using namespace std;


Consumible::Consumible()
{
	_active = false;
	_type = true;
}


Consumible::~Consumible()
{
}

void Consumible::render()
{
	ConsoleXY(_pX * 2, _pY);
	ConsoleSetColor(DARKYELLOW, WHITE);
	if (_type)
	{
		cout << "+-";
	}
	else 
	{
		cout << "<3";
	}
}
