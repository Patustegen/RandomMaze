#pragma once
#include "Laberint.h"
#include "Base.h"

class Player : public Base
{
	bool sword;
public:
	/*
	Descripci�: El jugador agafa/utilitza una espasa.
	Entrada: Boolea, true si agafa, false si la utilitza.
	*/
	void setSword(bool S) { sword = S; };

	/*
	Descripci�: Diu si el jugador t� espasa o no.
	Retorna: Boolea, true si t�, false si no.
	*/
	bool hasSword() { return sword; };

	/*
	Descripci�: Inicia el jugador a la primera posici� del laberint.
	*/
	void init();

	/*
	Descripci�: Moviment del personatge, colisi�, etc...
	Entrada: La tecla que hem apretat.
	*/
	void update(int moviment);

	/*
	Descripci�: Pintat del jugador.
	*/
	void render();

	Player();
	~Player();
};

