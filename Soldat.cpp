#include "Soldat.h"
#include "ConsoleControl.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


Soldat::Soldat()
{
	contador = 0;
	mpLab = nullptr;
}


Soldat::~Soldat()
{
}


void Soldat::update()
{
	if (contador <= 0)
	{
		int newPos = rand() % 4 +1;
		switch (newPos)
		{
		case NORTH:
			if (_pY - 1 >= 0)
			{
				if (!mpLab->isParet(_pX, _pY - 1) && !mpLab->isFinal(_pX, _pY - 1))
				{
					ConsoleXY(_pX * 2, _pY);
					ConsoleSetColor(WHITE, WHITE);
					cout << "  ";
					contador = 20;
					_pY--;
				}
			}
			break;
		case SOUTH:
			if (_pY + 1 < REAL_HEIGHT)
			{
				if (!mpLab->isParet(_pX, _pY + 1) && !mpLab->isFinal(_pX, _pY + 1))
				{
					ConsoleXY(_pX * 2, _pY);
					ConsoleSetColor(WHITE, WHITE);
					cout << "  ";
					contador = 20;
					_pY++;
				}
			}
			break;
		case EAST:
			if (_pX + 1 < REAL_WIDTH)
			{
				if (!mpLab->isParet(_pX + 1, _pY) && !mpLab->isFinal(_pX + 1, _pY))
				{
					ConsoleXY(_pX * 2, _pY);
					ConsoleSetColor(WHITE, WHITE);
					cout << "  ";
					contador = 20;
					_pX++;
				}
			}
			break;
		case WEST:
			if (_pX - 1 >= 0)
			{
				if (!mpLab->isParet(_pX - 1, _pY) && !mpLab->isFinal(_pX - 1, _pY))
				{
					ConsoleXY(_pX * 2, _pY);
					ConsoleSetColor(WHITE, WHITE);
					cout << "  ";
					contador = 20;
					_pX--;
				}
			}
			break;
		default:
			break;
		}
	}
	else {

		contador -= rand() % 4;;
	}
}

void Soldat::render()
{
	ConsoleXY(_pX * 2, _pY);
	ConsoleSetColor(RED, WHITE);
	cout << ":(";
}
