#include "Scoreboard.h"
#include <string>
#include "ConsoleControl.h"

using namespace std;

void Scoreboard::save(int p)
{
	string Line;
	_handler.open("scores.txt", ios::in);//obro fitxer
	if (!_handler.is_open()) {
		_handler.open("scores.txt", ios::out);//si no existeix creo un i guardo la puntuacio
		_handler << to_string(p) << ";" << *_name << endl;
		_handler.close();//tanco fitxer
	}
	else
	{
		_top10.resize(0);//reinicio a 0
		for (int i = 0; i < 10; i++) {//agafo les 10 linies
			if (_handler.eof()) {//o si s'acaba abans el fitxer
				break;
			}
			getline(_handler, Line);
			if (Line == "")//si la linia es un endl surto
			{
				break;
			}
			scores *score = new scores();
			int separador = Line.find(";");//busco el separador
			string P = Line.substr(0, separador); //del inici al separador es la puntuacio
			score->_punt = stoi(P); //guardo com a int
			string N = Line.substr(separador + 1); //despres va el nom
			score->_nom = N;//guardo string
			_top10.push_back(score);//vaig fent pushbacks
			score = nullptr;
		}
		scores *newScore = new scores();
		newScore->_punt = 0;
		newScore->_nom = "";
		_top10.push_back(newScore);//poso una posicio en blanc
		newScore = nullptr;
		for (int i = 0; i < _top10.size(); i++)
		{
			if (_top10[i]->_punt < p) //busco a partir de quina posicio del top 10 es quedaria la nova puntuacio
			{
				for (int j = _top10.size()-1; j > 0; j--)//envio a totes les posicions de sota una posicio mes abaix
				{
					_top10[j]->_punt = _top10[j - 1]->_punt;
					_top10[j]->_nom = _top10[j - 1]->_nom;
				}
				_top10[i]->_punt = p;//poso la nova puntuacio al seu lloc
				_top10[i]->_nom = *_name;
				break;
			}
		}
		_handler.close(); //tanco fitxer
		_handler.open("scores.txt", ios::out);//obro fitxer per escriure
		if (!_handler.is_open()) {
			cout << "There're no scores available.\n";
			return;
		}
		for (int i = 0; i < 10; i++)//escric el top 10
		{
			_handler << to_string(_top10[i]->_punt) << ";" << _top10[i]->_nom << endl;
		}
		_handler.close();
	}
	show();
}

void Scoreboard::show()
{
	string Line;
	_handler.open("scores.txt", ios::in);
	if (!_handler.is_open())
	{
		cout << "There're no scores available.\n";
		return;
	}
	else
	{
		cout << "\n\n\t\t----------------------------------------------\n";
		cout << "\t\t\t  _                  __   ___  \n";
		cout << "\t\t\t | |                /_ | / _ \\ \n";
		cout << "\t\t\t | |_  ___   _ __    | || | | |\n";
		cout << "\t\t\t | __|/ _ \\ | '_ \\   | || | | |\n";
		cout << "\t\t\t | |_| (_) || |_) |  | || |_| |\n";
		cout << "\t\t\t  \\__|\\___/ | .__/   |_| \\___/ \n";
		cout << "\t\t\t            | |                \n";
		cout << "\t\t\t            |_|                \n";
		cout << "\t\t----------------------------------------------\n\n\n";
		while (!_handler.eof()) {
			getline(_handler, Line);
			if (Line == "")
			{
				break;
			}
			int separador = Line.find_first_of(";");
			string P = Line.substr(0, separador);
			string N = Line.substr(separador +1);
			cout << "\t\t\t\t" << P << " - " << N << endl;
		}
	}
	ConsoleSetColor(BLACK, BLACK);
}

Scoreboard::Scoreboard()
{
	_top10.resize(0);
	_name = nullptr;
}

Scoreboard::~Scoreboard()
{
}