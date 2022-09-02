#include "Laberint.h"
#include <iostream>
#include "ConsoleControl.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Laberint::init()
{
	srand(time(NULL));
	int mapaLogic[HEIGHT][WIDTH];
	int casellaCount = 1;
	
	for (int X = 0; X < WIDTH; X++) {
		for (int Y = 0; Y < HEIGHT; Y++) {
			mapaLogic[X][Y] = 0; //Primer s’omple de 0 una array de 2 dimensions (en el meu cas de 10 X 10).
		}
	}
	int X = rand() % WIDTH;
	int Y = rand() % HEIGHT;
	_pX = (X * 3) +1;
	_pY = (Y * 3) +1;
	//S’agafa una X i Y inicials de forma random i es guarden en variables de la classe.
	
	vector<int> moved; //Amb un vector de ints, comprovaré les posicions que no pot anar.
	while (casellaCount != SIZE) { //Mentres no omplim totes les caselles.

		moved.resize(0); 
		pos newPos;
		bool repeat = true;
		if (X == 0) { //A cada volta miro si estic en algun limit del mapa i faig pushback al vector de les posicions que no puc fer.
			moved.push_back(WEST);
		}
		else if (X == WIDTH - 1) {
			moved.push_back(EAST);
		}
		if (Y == 0) {
			moved.push_back(NORTH);
		}
		else if (Y == HEIGHT - 1) {
			moved.push_back(SOUTH);
		}
		if ((Y - 1 < 0 || mapaLogic[X][Y - 1] != 0) && (Y + 1 >= HEIGHT || mapaLogic[X][Y + 1] != 0) && (X - 1 < 0 || mapaLogic[X - 1][Y] != 0) && (X + 1 >= WIDTH || mapaLogic[X + 1][Y] != 0))
		{
			repeat = false; //Miro si esta envoltat de caselles omplertes o inaccessibles i si ho està, vol dir que hem de tirar enrere.
		}
		do
		{
			int Move = 0;
			bool numRepeat = true;
			if (moved.size() == 4) { //mirem si el vector de moviments que hem triat està a 4 (hem intentat tots els moviments), si ho està hem de tirar enrere.
				repeat = false;
			}
			if (repeat) {
				while (numRepeat == true) { //Fem un bucle traient numeros random mentre no siguin els que tenim al vector.
					numRepeat = false;
					Move = (rand() % 4) + 1;
					for (int i = 0; i < moved.size(); i++)
					{
						if (Move == moved.at(i))
						{
							numRepeat = true;
						}
					}
				}
				switch (Move) {
				case NORTH:
					if (mapaLogic[X][Y - 1] == 0 && Y - 1 >= 0) {
						mapaLogic[X][Y] += 1;//obrim porta cap aquella direcció
						newPos.pX = X;//omplim un struct de posició
						newPos.pY = Y;
						recorrido.push_back(newPos);//fem pushback al recorregut
						Y--; //Movem la posició
						mapaLogic[X][Y] += 2; //creem la porta en el sentit contrari a la nova posició
						casellaCount++; //Sumem un al total de caselles.
						repeat = false;
					}
					else {
						moved.push_back(Move);//si no podem anar, fem pushback de la posicio
					}
					break;
				case SOUTH:
					if (mapaLogic[X][Y + 1] == 0 && Y + 1 < HEIGHT) {
						mapaLogic[X][Y] += 2;
						newPos.pX = X;
						newPos.pY = Y;
						recorrido.push_back(newPos);
						Y++;
						mapaLogic[X][Y] += 1;
						casellaCount++;
						repeat = false;
					}
					else {
						moved.push_back(Move);
					}
					break;
				case EAST:
					if (mapaLogic[X + 1][Y] == 0 && X + 1 < WIDTH) {
						mapaLogic[X][Y] += 4;
						newPos.pX = X;
						newPos.pY = Y;
						recorrido.push_back(newPos);
						X++;
						mapaLogic[X][Y] += 8;
						casellaCount++;
						repeat = false;
					}
					else {
						moved.push_back(Move);
					}
					break;
				case WEST:
					if (mapaLogic[X - 1][Y] == 0 && X - 1 >= 0) {
						mapaLogic[X][Y] += 8;
						newPos.pX = X;
						newPos.pY = Y;
						recorrido.push_back(newPos);
						X--;
						mapaLogic[X][Y] += 4;
						casellaCount++;
						repeat = false;
					}
					else {
						moved.push_back(Move);
					}
					break;
				default:
					break;
				}
			}
			else { //Si hem de tirar enrere
				X = recorrido.at(recorrido.size() - 1).pX; //assignem les X i Y a les x i y de la ulitma posició del vector
				Y = recorrido.at(recorrido.size() - 1).pY;
				recorrido.resize(recorrido.size() - 1);//li traiem la ultima posicio
			}
		} while (repeat);
	}
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			switch (mapaLogic[i][j])
			{
			case 0:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 1; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 1; mapaReal[i * 3 + 1][j * 3 + 1] = 1; mapaReal[i * 3 + 2][j * 3 + 1] = 1;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 1; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 1:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 0; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 1; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 1;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 1; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 2:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 1; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 1; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 1;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 0; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 3:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 0; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 1; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 1;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 0; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 4:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 1; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 1; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 0;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 1; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 5:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 0; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 1; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 0;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 1; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 6:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 1; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 1; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 0;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 0; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 7:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 0; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 1; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 0;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 0; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 8:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 1; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 0; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 1;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 1; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 9:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 0; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 0; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 1;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 1; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 10:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 1; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 0; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 1;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 0; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 11:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 0; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 0; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 1;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 0; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 12:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 1; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 0; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 0;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 1; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 13:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 0; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 0; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 0;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 1; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 14:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 1; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 0; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 0;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 0; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			case 15:
				mapaReal[i * 3][j * 3] = 1; mapaReal[i * 3 + 1][j * 3] = 0; mapaReal[i * 3 + 2][j * 3] = 1;
				mapaReal[i * 3][j * 3 + 1] = 0; mapaReal[i * 3 + 1][j * 3 + 1] = 0; mapaReal[i * 3 + 2][j * 3 + 1] = 0;
				mapaReal[i * 3][j * 3 + 2] = 1; mapaReal[i * 3 + 1][j * 3 + 2] = 0; mapaReal[i * 3 + 2][j * 3 + 2] = 1;
				break;
			default:
				break;
			}
		}
	}
	_finalX = (X * 3) +1;
	_finalY = (Y * 3) +1;
}

void Laberint::render()
{
	for (int i = 0; i < REAL_HEIGHT; i++)
	{
		for (int j = 0; j < REAL_WIDTH; j++)
		{
			if (isFinal(i,j))
			{
				ConsoleSetColor(DARKYELLOW, WHITE);
				cout << "()";//Final
			}
			else if (mapaReal[i][j])
			{
				ConsoleSetColor(DARKGREY, DARKGREY); //paret
				cout << "  ";
			}
			else {
				ConsoleSetColor(WHITE, WHITE);//terra
				cout << "  ";
			}
		}
		ConsoleSetColor(WHITE, BLACK);
		if (i != REAL_HEIGHT -1)
		{
			cout << endl;
		}
	}
	ConsoleSetColor(WHITE, BLACK);
}

bool Laberint::isFinal(int x, int y)
{
	if (x == _finalX && y == _finalY) {
		return true;
	}
	else
	{
		return false;
	}
}


Laberint::Laberint()
{
	recorrido.resize(0);
	_finalX = 0;
	_finalY = 0;
}

Laberint::~Laberint()
{
}
