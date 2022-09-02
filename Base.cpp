#include "Base.h"



Base::Base()
{
	_pX = 0;
	_pY = 0;
}


Base::~Base()
{
}

void Base::init()
{
	bool correct;
	do
	{
		correct = true;
		_pX = (rand() % HEIGHT) * 3 +1;
		_pY = (rand() % WIDTH) * 3 +1;
		if (mpLab->isParet(_pX, _pY))//si es paret repeteixo
		{
			correct = false;
		}
		if (((_pX < mpLab->getInitX() + 3) && (_pX > mpLab->getInitX() - 3)) && ((_pY < mpLab->getInitY() + 3) && (_pY > mpLab->getInitY() - 3)))
		{
			correct = false;//si es al voltant del principi repeteixo
		}
		if (mpLab->isFinal(_pY, _pX))//si es final repeteixo
		{
			correct = false;
		}

	} while (!correct);
}

bool Base::isColision(int x, int y)
{
	if (x == _pX && y == _pY)
	{
		return true;
	}
	else
	{
		return false;
	}
}
