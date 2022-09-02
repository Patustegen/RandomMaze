#include "Player.h"
#include "ConsoleControl.h"
#include "Laberint.h"
#include <iostream>

using namespace std;

void Player::init()
{
	_pX = mpLab->getInitX();
	_pY = mpLab->getInitY();
}

void Player::update(int moviment)
{
	switch (moviment)
	{
	case KB_LEFT:
		if (_pX -1 >= 0)
		{
			if (!mpLab->isParet(_pX - 1, _pY))
			{
				ConsoleXY(_pX * 2, _pY);
				ConsoleSetColor(WHITE, WHITE);
				cout << "  ";
				_pX--;
			}
		}
		break;
	case KB_UP:
		if (_pY - 1 >= 0)
		{
			if (!mpLab->isParet(_pX, _pY - 1))
			{
				ConsoleXY(_pX * 2, _pY);
				ConsoleSetColor(WHITE, WHITE);
				cout << "  ";
				_pY--;
			}
		}
		break;
	case KB_RIGHT:
		if (_pX + 1 < REAL_WIDTH) 
		{
			if (!mpLab->isParet(_pX + 1, _pY))
			{
				ConsoleXY(_pX * 2, _pY);
				ConsoleSetColor(WHITE, WHITE);
				cout << "  ";
				_pX++;
			}
		}
		break;
	case KB_DOWN:
		if (_pY + 1 < REAL_HEIGHT) 
		{
			if (!mpLab->isParet(_pX, _pY + 1))
			{
				ConsoleXY(_pX * 2, _pY);
				ConsoleSetColor(WHITE, WHITE);
				cout << "  ";
				_pY++;
			}
		}
		break;
	default:
		break;
	}
}

void Player::render()
{
	ConsoleXY(_pX * 2, _pY);
	ConsoleSetColor(DARKBLUE, WHITE);
	cout << ":)";
	ConsoleSetColor(WHITE, BLACK);
}

Player::Player()
{
	sword = false;
	mpLab = nullptr;
}

Player::~Player()
{
}
