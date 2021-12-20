#include <iostream>
#include <ctime>
#include "Chaine.h"
using namespace std;

#pragma warning(disable : 4996)

#define uiTailleMax (unsigned int) 16
#define demasquer (char)'D'
#define marquer (char)'M'
#define decouvert (char)' '

struct Demineur {
	unsigned int* puiPositionMines;
	char* pcDemineur;
	Chaine CHistorique;
	unsigned int uiNbMines;
	unsigned int uiNbLignes;
	unsigned int uiNbColonnes;
	unsigned int uiNbCoups;
	unsigned int uiNbCases;
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


void construction(Demineur& D, unsigned int uiCommande)
{
	D.uiNbCases = D.uiNbColonnes * D.uiNbLignes;
	char aff = ' ';
	unsigned int uiPosCases = 0;
	for (unsigned int i = 0; i < D.uiNbLignes; i++) 
	{
		for (unsigned int j = 0; j < D.uiNbColonnes; j++)
		{
			uiPosCases = i * D.uiNbColonnes + j;
			if (uiCommande == 0)
			{
				D.pcDemineur[uiPosCases] = '.';
			}
		}
	}
	debut(D.CHistorique);
	while (!estFin(D.CHistorique)) {  
		for (unsigned int i = 0; i < D.uiNbLignes; i++)
		{
			for (unsigned int j = 0; j < D.uiNbColonnes; j++)
			{
				uiPosCases = i * D.uiNbColonnes + j;
				if (D.pcDemineur[uiPosCases] != decouvert)
				{
					for (unsigned int l = 0; l < D.uiNbMines; l++)
					{
						if (uiCommande == 1)
						{
							if (D.puiPositionMines[l] == uiPosCases)
							{
								if (lire(D.CHistorique).cCommande == marquer && lire(D.CHistorique).uiPosition == D.puiPositionMines[l])
								{
									D.pcDemineur[uiPosCases] = 'x';
								}
								if (lire(D.CHistorique).cCommande == demasquer && lire(D.CHistorique).uiPosition == D.puiPositionMines[l])
								{
									perdu();
								}
							}
						}
					}
					if (lire(D.CHistorique).cCommande == marquer && lire(D.CHistorique).uiPosition == uiPosCases)
					{
						D.pcDemineur[uiPosCases] = 'x';
					}
					if (lire(D.CHistorique).cCommande == demasquer && lire(D.CHistorique).uiPosition == uiPosCases)
					{
						D.pcDemineur[uiPosCases] = ' ';
						int droite = 0, gauche = 0, haut = 0, bas = 0;
						for (unsigned int l = 0; l < D.uiNbMines; l++)
						{
							int tmp1 = uiPosCases + 1;
							if ((uiPosCases + 1) == D.puiPositionMines[l] && (uiPosCases + 1) > 0 && tmp1 > 0)
							{
								if (D.pcDemineur[uiPosCases + 1] != decouvert)
									droite += 1;
							}
							int tmp2 = uiPosCases - 1;
							if ((uiPosCases - 1) == D.puiPositionMines[l] && (uiPosCases - 1) > 0 && tmp2 > 0)
							{
								if (D.pcDemineur[uiPosCases - 1] != decouvert)
									gauche += 1;
							}
							int tmp3 = uiPosCases + D.uiNbColonnes;
							if ((uiPosCases + D.uiNbColonnes) == D.puiPositionMines[l] && (uiPosCases + D.uiNbColonnes) > 0 && tmp3 > 0)
							{
								if (D.pcDemineur[uiPosCases + D.uiNbColonnes] != decouvert)
									bas += 1;
							}
							int tmp4 = uiPosCases - D.uiNbColonnes;
							if ((uiPosCases - D.uiNbColonnes) == D.puiPositionMines[l] && tmp4 > 0)
							{
								if (D.pcDemineur[uiPosCases - D.uiNbColonnes] != decouvert)
									haut += 1;
							}
						}
						if (droite > 0)
							D.pcDemineur[uiPosCases + 1] = ' ';
						if (gauche > 0)
							D.pcDemineur[uiPosCases - 1] = ' ';
						if (bas > 0)
							D.pcDemineur[uiPosCases + D.uiNbColonnes] = ' ';
						if (haut > 0)
							D.pcDemineur[uiPosCases - D.uiNbColonnes] = ' ';

					}
				}
			} //endfor
		} //endfor
		suivant(D.CHistorique);
	} //endwhile
}//endfunction

void afficher(const Demineur& D)
{
	//system("CLS");
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
			cout << "| " << D.pcDemineur[i * D.uiNbColonnes + k] << ' ';
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
	D.uiNbCases = D.uiNbColonnes * D.uiNbLignes;
	D.pcDemineur = new char[D.uiNbCases];
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

	D.uiNbCases = D.uiNbColonnes * D.uiNbLignes;
	D.pcDemineur = new char[D.uiNbCases];
	construction(D, 0);

	cin >> D.uiNbCoups;
	for (unsigned int i = 0; i < D.uiNbCoups; i++)
	{
		while (true)
		{
			cin >> cHistoriqueEntree;
			if (cHistoriqueEntree[0] == demasquer || cHistoriqueEntree[0] == marquer)
			{
				Historique hTmp;
				formater(hTmp, cHistoriqueEntree);
				inserer(D.CHistorique, hTmp);
				break;
			}
		}
		construction(D, 1);
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
		if (cHistoriqueEntree[0] == demasquer || cHistoriqueEntree[0] == marquer)
		{
			Historique hTmp;
			formater(hTmp, cHistoriqueEntree);
			inserer(D.CHistorique, hTmp);
			break;
		}
	}
	construction(D, 1);
	afficher(D);
}

int main()
{
	Demineur D;
	initialiser(D.CHistorique);
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
			construction(D, 0);
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
		case 6:
			afficher(D);
			break;
		default:
			break;
		}
	}
	delete[] D.puiPositionMines;
	delete[] D.pcDemineur;
	return 0;
}