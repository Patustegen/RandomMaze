#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>

using namespace std;

struct scores
{
	int _punt;
	string _nom;
};

using namespace std;
class Scoreboard
{
	vector<scores*> _top10;
	string *_name;
	fstream _handler;
public:
	/*
	Descripci�: Guarda la puntuaci� si est� en el top10.
	Entrada: La puntuaci� en int.
	*/
	void save(int p);

	/*
	Descripci�: Mostra el top 10 per pantalla.
	*/
	void show();

	/*
	Descripci�: Guarda el nom del jugador per si entra al top 10.
	Entrada: Punter al string del nom.
	*/
	void setName(string *N) { _name = N; };

	Scoreboard();
	~Scoreboard();
};