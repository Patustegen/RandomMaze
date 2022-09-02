#pragma once
class Marcador
{
	int _punts;
	int _vidas;
public:
	/*
	Descripció: Funció que et diu el numero de punts que tenim.
	Retorna: El numero de punts.
	*/
	int getPunts() { return _punts; };
	
	/*
	Descripció: Funció que suma P punts al total.
	Entrada: Un numero de punts.
	*/
	void setPunts(int p) { _punts += p; };
	
	/*
	Descripció: Funció que et diu el numero de vides que tens.
	Retorna: El numero de vides.
	*/
	int getVida() { return _vidas; };
	
	/*
	Descripció: Funció que suma/resta V a vida.
	Entrada: Un numero de vides.
	*/
	void setVida(int v) { _vidas += v; };

	/*
	Descripció: Inicia la UI.
	*/
	void init();

	/*
	Descripció: Pintat de la UI.
	*/
	void render();
	
	Marcador();
	~Marcador();
};

