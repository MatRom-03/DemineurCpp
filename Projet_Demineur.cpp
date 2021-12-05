#include <iostream>
#include <ctime>
using namespace std;

#pragma warning(disable : 4996)

#define uiTailleMax (unsigned int) 16
#define demasquer (char)'D'
#define marquer (char)'M'


struct Historique {
	char cCommande;
	unsigned int uiPosition;
};

struct Demineur {
	unsigned int* puiPositionMines;
	Historique hHistorique;
	unsigned int uiNbMines;
	unsigned int uiNbLignes;
	unsigned int uiNbColonnes;
	unsigned int uiNbCoups;
};

void listeCommande()
{
	cout << "Liste des commandes :" << endl;
	cout << "1: Produire un probleme" << endl;
	cout << "2: Produire une grille" << endl;
	cout << "3: Determiner si la partie est gagnee" << endl;
	cout << "4: Determiner si la partie est perdue" << endl;
	cout << "5: Produire un nouveau coup" << endl;
	cout << "Entrez le nombre correspondant a la commande : ";
}

void perdu()
{
	system("CLS");
	cout << "You lose !" << endl;
	exit(0);
}

void afficher(const Demineur& D)
{
	system("CLS");
	char aff = '.';
	cout << D.uiNbLignes << " " << D.uiNbColonnes << endl;
	for (unsigned int i = 0; i < D.uiNbLignes; i++)
	{
		for (unsigned int j = 0; j < D.uiNbColonnes; j++)
		{
			cout << " ---";
		}
		cout << endl;
		for (unsigned int k = 0; k < D.uiNbColonnes; k++)
		{
			aff = '.';
			for (unsigned int l = 0; l < D.uiNbMines; l++)
			{
				if (D.puiPositionMines[l] == (i * D.uiNbColonnes + k))
				{
					if (D.hHistorique.cCommande == marquer && D.hHistorique.uiPosition == D.puiPositionMines[l])
					{
						aff = 'x';
					}
					else
					{
						aff = 'm';
					}
					if (D.hHistorique.cCommande == demasquer && D.hHistorique.uiPosition == D.puiPositionMines[l])
					{
						perdu();
					}
				}
			}
			cout << "| " << aff << ' ';
		}
		cout << "|" << endl;
	}
	for (unsigned int j = 0; j < D.uiNbColonnes; j++)
	{
		cout << " ---";
	}
	cout << endl << endl;
	listeCommande();
}

void probleme(Demineur& D)
{
	while (true)
	{
		cin >> D.uiNbLignes >> D.uiNbColonnes >> D.uiNbMines;
		if ((D.uiNbMines <= (D.uiNbLignes * D.uiNbColonnes)) && (D.uiNbColonnes <= uiTailleMax) && (D.uiNbLignes <= uiTailleMax))
			break;
		else
			if (D.uiNbMines > (D.uiNbLignes * D.uiNbColonnes))
			{
				cout << "Nombre de mines trop grand pour le tableau" << endl;
			}
			if (D.uiNbColonnes > uiTailleMax)
			{
				cout << "Nombre de colonnes trop grande" << endl;
			}
			if (D.uiNbLignes > uiTailleMax)
			{
				cout << "Nombre de lignes trop grand" << endl;
			}
	}

	// Allocation du tableau de position de mines
	D.puiPositionMines = new unsigned int[D.uiNbMines];

	for (unsigned int i = 0; i < D.uiNbMines; i++)
	{
		unsigned int uiNouvellePosition = 0;

		while (true)
		{
			uiNouvellePosition = (unsigned int)rand() % (D.uiNbLignes * D.uiNbColonnes);
			bool bFound = false;

			for (unsigned int j = 0; j < i; j++)
			{
				if (D.puiPositionMines[j] == uiNouvellePosition)
				{
					bFound = true;
					break;
				}
			}

			if (!bFound)
				break;
		}

		D.puiPositionMines[i] = uiNouvellePosition;
		cout << D.puiPositionMines[i] << " ";
	}
	cout << endl;
}

void grille(Demineur& D)
{
	char cHistoriqueEntree[4];
	char cHistoriqueTransition[3];
	cin >> D.uiNbLignes >> D.uiNbColonnes >> D.uiNbMines;
	D.puiPositionMines = new unsigned int[D.uiNbMines];
	for (unsigned int i = 0; i < D.uiNbMines; i++)
	{
		cin >> D.puiPositionMines[i];
	}

	cin >> D.uiNbCoups;
	for (unsigned int i = 0; i < D.uiNbCoups; i++)
	{
		cin >> cHistoriqueEntree;
		D.hHistorique.cCommande = cHistoriqueEntree[0];
		for (int i = 0; i < 2; i++)
		{
			cHistoriqueTransition[i] = cHistoriqueEntree[i + 1];
		}
		D.hHistorique.uiPosition = atoi(cHistoriqueTransition);
	}
	afficher(D);
}

void win()
{
	cout << "win" << endl;
}

void lose()
{
	cout << "lose" << endl;
}

void nouveau_coup(Demineur& D)
{
	char cHistoriqueEntree[4];
	char cHistoriqueTransition[3];
	while (true)
	{
		cin >> cHistoriqueEntree;
		for (int i = 0; i < 2; i++)
		{
			cHistoriqueTransition[i] = cHistoriqueEntree[i + 1];
		}
		if (cHistoriqueEntree[0] == demasquer || cHistoriqueEntree[0] == marquer)
		{
			D.hHistorique.cCommande = cHistoriqueEntree[0];
			D.hHistorique.uiPosition = atoi(cHistoriqueTransition);
			break;
				
		}
	}
	afficher(D);
}

int main()
{
	Demineur D;
	srand((unsigned int)time(NULL));
	unsigned int commande = 0;
	listeCommande();
	while (true)
	{
		cin >> commande;
		switch (commande)
		{
		case 1:
			probleme(D);
			break;
		case 2:
			grille(D);
			break;
		case 3:
			win();
			break;
		case 4:
			lose();
			break;
		case 5:
			nouveau_coup(D);
			break;
		case 6: afficher(D);
			break;
		default:
			break;
		}
	}
	delete[] D.puiPositionMines;
	return 0;
}