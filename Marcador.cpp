#include "Marcador.h"
#include "ConsoleControl.h"
#include <iostream>
#include "Laberint.h"

using namespace std;

void Marcador::init()
{
	_punts = 0;
	_vidas = 3;
}

void Marcador::render()
{
	ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8);
	switch (_vidas)//doom face mes o menys
	{
	case 3:
		ConsoleSetColor(GREEN, BLACK);
		cout << "    .-\"\"\"\"\"\"-.";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 +1);
		cout << "  .'          '.";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 +2);
		cout << " /   O      O   \\";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 3);
		cout << ":                :";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 4);
		cout << "|                |";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 5);
		cout << ": ',          ,' :";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 6);
		cout << " \\  '-......-'  /";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 7);
		cout << "  '.          .'";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 8);
		cout << "    '-......-'";
		ConsoleXY(REAL_WIDTH * 2 + 10, REAL_HEIGHT / 8 + 10);
		ConsoleSetColor(RED, BLACK);
		cout << '\3' << "    " << '\3' << "    " << '\3';
		break;
	case 2:
		ConsoleSetColor(YELLOW, BLACK);
		cout << "    .-\"\"\"\"\"\"-.";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 1);
		cout << "  .'          '.";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 2);
		cout << " /   O      O   \\";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 3);
		cout << ":           `    :";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 4);
		cout << "|                |";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 5);
		cout << ":    .------.    :";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 6);
		cout << " \\  '        '  /";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 7);
		cout << "  '.          .'";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 8);
		cout << "    '-......-'";
		ConsoleXY(REAL_WIDTH * 2 + 10, REAL_HEIGHT / 8 + 10);
		ConsoleSetColor(RED, BLACK);
		cout << '\3' << "    " << '\3' << "      ";
		break;
	case 1:
		ConsoleSetColor(RED, BLACK);
		cout << "    .-\"\"\"\"\"\"-.";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 1);
		cout << "  .'  \\\\  //  '.";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 2);
		cout << " /   O      O   \\";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 3);
		cout << ":           `    :";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 4);
		cout << "|                |";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 5);
		cout << ":       __       :";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 6);
		cout << " \\  .-\"`  `\"-.  / ";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 7);
		cout << "  '.          .'";
		ConsoleXY(REAL_WIDTH * 2 + 7, REAL_HEIGHT / 8 + 8);
		cout << "    '-......-'";
		ConsoleXY(REAL_WIDTH * 2 + 10, REAL_HEIGHT / 8 + 10);
		cout << '\3' << "           ";
		break;
	default:
		break;
	}
	ConsoleSetColor(WHITE, BLACK);
	ConsoleXY(REAL_WIDTH * 2 + 10, REAL_HEIGHT / 2);
	cout << "Score: " << _punts;
}

Marcador::Marcador()
{
	_punts = 0;
	_vidas = 3;
}

Marcador::~Marcador()
{
}
