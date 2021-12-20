#ifndef CHAINE_H_
#define CHAINE_H_

/**
 * @file Chaine.h
 * @brief Projet sem06-tp-Cpp1
 * @author l'�quipe p�dagogique
 * @version 1 25/01/05
 * Composant de cha�ne d'items avec simple cha�nage
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#include "Item.h"

/** Type Maillon avec le principe du simple cha�nage (maillon suivant)
 */
struct Maillon {
    Item elem;     // El�ment (du maillon) de la liste cha�n�e
    Maillon* suiv; // Pointeur sur le maillon suivant
};

/** Type Chaine 
 *  Rep�res du d�but de cha�ne et du  maillon courant
 */
struct Chaine {
    Maillon* tete;     // Pointeur sur le maillon de t�te
    Maillon** courant; // Superpointeur (pointeur du pointeur) 
    				   // d�signant le maillon courant		   		   
};

/** 
 * @brief Initialisation d'une cha�ne vide
 * la liste est allou�e en m�moire dynamique
 * @see detruire, la liste est � d�sallouer en fin d�utilisation
 * @param[out] c : la cha�ne
 */
void initialiser(Chaine& c);

/** 
 * @brief D�sallocation d'une cha�ne
 * @see initialiser, la liste a d�j� �t� allou�e en m�moire dynamique
 * @param[out] c : la cha�ne
 */
void detruire(Chaine& c);

/**
 * @brief Test de cha�ne vide
 * @param[in] c : la cha�ne test�e
 * @return true si c est vide, false sinon
 */
bool estVide(const Chaine& c);

/**
 * @brief Insertion d'un �l�ment avant le maillon courant
 * Le nouveau maillon devient le maillon courant 
 * @param[in,out] c : la cha�ne
 * @param[in] elem : l'�l�ment ins�r�
 */
void inserer(Chaine& c, const Item& elem);

/**
 * @brief Suppression du maillon courant
 * @param[in,out] c : la cha�ne
 * @pre Le maillon courant existe et ce n'est pas la fin de la cha�ne
 */
void supprimer(Chaine& c);

/**
 * @brief Modification de l'�l�ment stock� dans le maillon courant
 * @param[in,out] c : la cha�ne
 * @param[in] elem : l'�l�ment � �crire
 * @pre Le maillon courant existe et ce n'est pas la fin de la cha�ne
 */
void ecrire(Chaine& c, const Item& elem);

/**
 * @brief Lecture de l'�l�ment stock� dans le maillon courant 
 * @param[in] c : la cha�ne
 * @return l'�l�ment lu
 * @pre Le maillon courant existe et ce n'est pas la fin de la cha�ne
 */
Item lire(const Chaine& c);

/**
 * @brief Positionnement du maillon courant en d�but de cha�ne
 * @param[in,out] c : la cha�ne
 */
void debut(Chaine& c);

/**
 * @brief Test de debut de chaine
 * @param[in] c : la cha�ne test�e
 * @return true si le maillon courant est le d�but de cha�ne, false sinon
 */
bool estDebut(const Chaine& c);

/**
 * @brief Positionnement du maillon courant en fin de cha�ne
 * @param[in,out] c : la cha�ne
 * @return true si le maillon courant est la fin de cha�ne, false sinon
 */
void fin(Chaine& c);

/**
 * @brief Test de fin de cha�ne
 * @param[in] c : la cha�ne test�e
 * @return true si le maillon courant est la fin de cha�ne, false sinon.
 */
bool estFin(const Chaine& c);

/**
 * @brief Positionnement du maillon courant au maillon suivant
 * @param[in,out] c : la cha�ne
 * @pre Le maillon courant existe et ce n'est pas la fin de la cha�ne
 */
void suivant(Chaine& c);

#endif /*CHAINE_H_*/
