#include <iostream>
#include "Laberint.h"
#include "Player.h"
#include "ConsoleControl.h"
#include "Base.h"
#include "Soldat.h"
#include "Consumible.h"
#include "Marcador.h"
#include "Scoreboard.h"
#include <string>

using namespace std;

void menu();
void game(int *scene, int *punts);
void gameOver();
void win(int p);
void scoreBoard();

int main() {
	int tecla = 0;
	int scene = 0;
	int punts = 0;
	
	while (tecla != KB_ESCAPE)
	{
		tecla = 0;
		tecla = ConsoleInKey();
		switch (scene)
		{
		case 0:
			menu();
			if (tecla == 49)
			{
				scene = 1;
			}
			else if (tecla == 50) {
				scene = 2;
			}
			break;
		case 1:
			game(&scene, &punts); //m'interessa que des de dins puguin canviar aquestes dues variables
			if (scene == 1)//si ha sortit de la funcio amb escena 1 es que no ha guanyat ni perdut
			{
				scene = 0;//reenvio a menu
			}
			break;
		case 2:
			scoreBoard();//mostra score
			system("pause");
			scene = 0;//reenvio a menu
			break;
		case 3:
			win(punts);//has guanyat, digam el teu nom
			scene = 2;//reenvio a score
			break;
		case 4:
			gameOver();//has perdut
			system("pause");
			scene = 0;//reenvio a menu
			break;
		default:
			break;
		}
		ConsoleWait(500);//Aqui nomes es repeteix text, aixi que poso un wait alt perque no fagi mal als ulls
	}

	return 0;
}

void menu() {
	ConsoleClear();
	ConsoleSetColor(YELLOW, BLACK);
	cout << "\n\n\n\t\t--------------------------------------------------------------------\n";
	cout << "\t\t  _____                 _                   __  __               \n";
	cout << "\t\t |  __ \\               | |                 |  \\/  |              \n";
	cout << "\t\t | |__) |__ _ _ __   __| | ___  _ __ ___   | \\  / | __ _ _______ \n";
	cout << "\t\t |  _  // _` | '_ \\ / _` |/ _ \\| '_ ` _ \\  | |\\/| |/ _` |_  / _ \\\n";
	cout << "\t\t | | \\ \\ (_| | | | | (_| | (_) | | | | | | | |  | | (_| |/ /  __/\n";
	cout << "\t\t |_|  \\_\\__,_|_| |_|\\__,_|\\___/|_| |_| |_| |_|  |_|\\__,_/___\\___|\n";
	cout << "\n\t\t--------------------------------------------------------------------\n\n\n";
	ConsoleSetColor(WHITE, BLACK);
	cout << "\t\t  ___               _ \n";
	cout << "\t\t | _ \\_ _ ___ _____(_)\t\tESCAPE to Close\n";
	cout << "\t\t |  _/ '_/ -_|_-<_-<_ \t\t1 to Play\n";
	cout << "\t\t |_| |_| \\___/__/__(_)\t\t2 to see ScoreBoard\n";
}

void game(int *scene, int *punts) {
	int L = 0;
	do//demano dificultat
	{
		cout << "\n\n\t\tSelect Difficulty (1-3): ";
		cin >> L;
	}while (L < 0 || L > 3);
	ConsoleClear();
	Laberint actualLab;
	Player Jugador;
	Marcador UI;
	vector<Soldat*> Enemies;
	Enemies.resize(0);
	vector<Consumible*> Consumibles;
	Consumibles.resize(0);
	int tecla = 0;

	//INIT
	UI.init();
	actualLab.init();
	Jugador.setLab(&actualLab);
	Jugador.init();
	for (int i = 0; i < L * 3; i++)//omplim depenent de la dificultat
	{
		Soldat *nSoldat = new Soldat();
		nSoldat->setLab(&actualLab);
		nSoldat->init();
		Consumible *nCons = new Consumible();
		nCons->setLab(&actualLab);
		nCons->init();
		if (i < L)//1/3 de cors 2/3 de espases
		{
			nCons->setType(false);
		}
		Enemies.push_back(nSoldat);
		Consumibles.push_back(nCons);
	}

	actualLab.render();//pintem un cop el laberint
	while (tecla != KB_ESCAPE)
	{
		tecla = 0;
		tecla = ConsoleInKey();

		//UPDATE
		Jugador.update(tecla);
		for (int i = 0; i < Enemies.size(); i++)
		{
			Enemies.at(i)->update();
			if (Enemies.at(i)->isColision(Jugador.getX(),Jugador.getY()))//jugador xoca amb enemic
			{
				if (Jugador.hasSword())
				{
					UI.setPunts(25);
					Jugador.setSword(false);
				}
				else
				{
					UI.setVida(-1);
				}
				Enemies.erase(Enemies.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < Consumibles.size(); i++)
		{
			if (Consumibles.at(i)->isColision(Jugador.getX(), Jugador.getY()))//jugador amb consumible
			{
				if (Consumibles.at(i)->isSword())//si es espasa
				{
					if (!Jugador.hasSword())
					{
						Jugador.setSword(true);
						Consumibles.erase(Consumibles.begin() + i);
						i--;
					}
				}
				else//si es cor
				{
					if (UI.getVida() == 3)
					{
						UI.setPunts(10);
					}
					else
					{
						UI.setVida(1);
					}
					Consumibles.erase(Consumibles.begin() + i);
					i--;
				}
			}
		}
		if (actualLab.isFinal(Jugador.getY(), Jugador.getX()))//si arribem al final
		{
			switch (UI.getVida())
			{
			case 1:
				*punts = UI.getPunts() + 25;
				break;
			case 2:
				*punts = UI.getPunts() + 50;
				break;
			case 3:
				*punts = UI.getPunts() + 100;
				break;
			default:
				break;
			}
			*scene = 3;//guanyes
			tecla = KB_ESCAPE;//surto
		}
		if (UI.getVida() <= 0)
		{
			*scene = 4;//perds
			tecla = KB_ESCAPE;//surto
		}

		//RENDER
		UI.render();
		for (int i = 0; i < Consumibles.size(); i++)
		{
			Consumibles.at(i)->render();
		}
		for (int i = 0; i < Enemies.size(); i++)
		{
			Enemies.at(i)->render();
		}
		Jugador.render();
		ConsoleWait(75);
	}
}

void gameOver() {
	ConsoleClear();
	ConsoleSetColor(YELLOW, BLACK);
	cout << "\n\n\n\n\t\t                   *              )               (     \n";
	cout << "\t\t (        (      (  `          ( /(               )\\ )  \n";
	ConsoleSetColor(DARKYELLOW, BLACK);
	cout << "\t\t )\\ )     )\\     )\\))(   (     )\\()) (   (   (   (()/(  \n";
	cout << "\t\t(()/(  ((((_)(  ((_)()\\  )\\   ((_)\\  )\\  )\\  )\\   /(_)) \n";
	ConsoleSetColor(RED, BLACK);
	cout << "\t\t /(_))_ )\\ _ )\\ (_()((_)((_)    ((_)((_)((_)((_) (_))   \n";
	cout << "\t\t(_)) __|(_)_\\(_)|  \\/  || __|  / _ \\\\ \\ / / | __|| _ \\  \n";
	ConsoleSetColor(DARKRED, BLACK);
	cout << "\t\t  | (_ | / _ \\  | |\\/| || _|  | (_) |\\ V /  | _| |   /  \n";
	cout << "\t\t   \\___|/_/ \\_\\ |_|  |_||___|  \\___/  \\_/   |___||_|_\\  \n\n\n";
	ConsoleSetColor(WHITE, BLACK);
	cout << "\t\tPress any Key to return to main Menu\n";
	ConsoleSetColor(BLACK, BLACK);
}

void win(int p) {
	bool correct = true;
	string name;
	Scoreboard table;
	do
	{
		correct = true;
		ConsoleClear();
		ConsoleSetColor(YELLOW,BLACK);
		cout << "\n\n\n\t\t __  __   ______   __  __       __     __   ______   __   __    \n";
		ConsoleSetColor(BLUE, BLACK);
		cout << "\t\t/\\ \\_\\ \\ /\\  __ \\ /\\ \\/\\ \\     /\\ \\  _ \\ \\ /\\  __ \\ /\\ \"-.\\ \\   \n";
		ConsoleSetColor(RED, BLACK);
		cout << "\t\t\\ \\____ \\\\ \\ \\/\\ \\\\ \\ \\_\\ \\    \\ \\ \\/ \".\\ \\\\ \\ \\/\\ \\\\ \\ \\-.  \\  \n";
		ConsoleSetColor(MAGENTA, BLACK);
		cout << "\t\t \\/\\_____\\\\ \\_____\\\\ \\_____\\    \\ \\__/\".~\\_\\\\ \\_____\\\\ \\_\\\\\"\\_\\ \n";
		ConsoleSetColor(GREEN, BLACK);
		cout << "\t\t  \\/_____/ \\/_____/ \\/_____/     \\/_/   \\/_/ \\/_____/ \\/_/ \\/_/ \n\n\n";
		ConsoleSetColor(WHITE, BLACK);
		cout << "\t\t Score: " << p << endl << endl;
		cout << "\t\t Enter your name (3 characters a-z or A-Z): ";
		getline(cin, name);
		if (name.length() > 3)
		{
			correct = false;
		}
		else
		{
			for (int i = 0; i < name.length(); i++)
			{
				if ((name[i] < 65 || name[i] > 90) && (name[i] < 97 || name[i] > 122))
				{
					correct = false;
				}
			}
		}
		ConsoleWait(400);
	} while (!correct);

	table.setName(&name);
	table.save(p);
	table.show();
}

void scoreBoard()
{
	ConsoleClear();
	Scoreboard table;
	table.show();
}
