#pragma once
class Marcador
{
	int _punts;
	int _vidas;
public:
	/*
	Descripci�: Funci� que et diu el numero de punts que tenim.
	Retorna: El numero de punts.
	*/
	int getPunts() { return _punts; };
	
	/*
	Descripci�: Funci� que suma P punts al total.
	Entrada: Un numero de punts.
	*/
	void setPunts(int p) { _punts += p; };
	
	/*
	Descripci�: Funci� que et diu el numero de vides que tens.
	Retorna: El numero de vides.
	*/
	int getVida() { return _vidas; };
	
	/*
	Descripci�: Funci� que suma/resta V a vida.
	Entrada: Un numero de vides.
	*/
	void setVida(int v) { _vidas += v; };

	/*
	Descripci�: Inicia la UI.
	*/
	void init();

	/*
	Descripci�: Pintat de la UI.
	*/
	void render();
	
	Marcador();
	~Marcador();
};

