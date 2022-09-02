#pragma once
#include "Laberint.h"
#include "Base.h"

class Player : public Base
{
	bool sword;
public:
	/*
	Descripció: El jugador agafa/utilitza una espasa.
	Entrada: Boolea, true si agafa, false si la utilitza.
	*/
	void setSword(bool S) { sword = S; };

	/*
	Descripció: Diu si el jugador té espasa o no.
	Retorna: Boolea, true si té, false si no.
	*/
	bool hasSword() { return sword; };

	/*
	Descripció: Inicia el jugador a la primera posició del laberint.
	*/
	void init();

	/*
	Descripció: Moviment del personatge, colisió, etc...
	Entrada: La tecla que hem apretat.
	*/
	void update(int moviment);

	/*
	Descripció: Pintat del jugador.
	*/
	void render();

	Player();
	~Player();
};

