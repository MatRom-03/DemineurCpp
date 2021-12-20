/**
 * @file Chaine.cpp
 * @brief Projet sem06-tp-Cpp1
 * @author l'�quipe p�dagogique
 * @version 1 25/01/05
 * Composant de cha�ne d'items avec simple cha�nage
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#include <iostream>
#include <cassert>
using namespace std;

#include "Chaine.h"

/** 
 * brief Initialisation d'une cha�ne vide
 * la liste est allou�e en m�moire dynamique
 * @see detruire, la liste est � d�sallouer en fin d�utilisation
 * @param[out] c : la cha�ne
 */
void initialiser(Chaine& c) {
    c.tete = NULL;
    c.courant = &c.tete;
}

/** 
 * brief D�sallocation d'une cha�ne
 * @see initialiser, la liste a d�j� �t� allou�e en m�moire dynamique
 * @param[out] c : la cha�ne
 */
void detruire(Chaine& c) {
    debut(c);
    while (!estVide(c)) 
        supprimer(c);
}

/**
 * @brief Test de cha�ne vide
 * @param[in] c : la cha�ne test�e
 * @return true si c est vide, false sinon
 */
bool estVide(const Chaine& c) {
    return c.tete == NULL;
}

/**
 * @brief Insertion d'un �l�ment avant le maillon courant
 * Le nouveau maillon devient le maillon courant 
 * @param[in,out] c : la cha�ne
 * @param[in] elem : l'�l�ment ins�r�
 */
void inserer(Chaine& c, const Item& elem) {
    Maillon* m = new Maillon;
    m->elem = elem;
    m->suiv = *(c.courant);
    *(c.courant) = m;
}

/**
 * @brief Suppression du maillon courant
 * @param[in,out] c : la cha�ne
 * @pre Le maillon courant existe et ce n'est pas la fin de la cha�ne
 */
void supprimer(Chaine& c) {
    assert(!estFin(c));
	Maillon* pmCopie = *c.courant;
    *c.courant = (*c.courant)->suiv;
    delete pmCopie;
}

/**
 * @brief Modification de l'�l�ment stock� dans le maillon courant
 * @param[in,out] c : la cha�ne
 * @param[in] elem : l'�l�ment � �crire
 * @pre Le maillon courant existe et ce n'est pas la fin de la cha�ne
 */
void ecrire(Chaine& c, const Item& elem) {
    assert(!estFin(c));
    (*(c.courant))->elem = elem;
}

/**
 * @brief Lecture de l'�l�ment stock� dans le maillon courant 
 * @param[in] c : la cha�ne
 * @return l'�l�ment lu
 * @pre Le maillon courant existe et ce n'est pas la fin de la cha�ne
 */
Item lire(const Chaine& c) {
    assert(!estFin(c));
    return (*(c.courant))->elem;
}

/**
 * @brief Positionnement du maillon courant en d�but de cha�ne
 * @param[in,out] c : la cha�ne
 */
void debut(Chaine& c) {
    c.courant = &(c.tete);
}

/**
 * @brief Test de debut de chaine
 * @param[in] c : la cha�ne test�e
 * @return true si le maillon courant est le d�but de cha�ne, false sinon
 */
bool estDebut(const Chaine& c) {
    return c.courant == &(c.tete);
}

/**
 * @brief Positionnement du maillon courant en fin de cha�ne
 * @param[in,out] c : la cha�ne
 * @return true si le maillon courant est la fin de cha�ne, false sinon
 */
void fin(Chaine& c) {
    while (!estFin(c))
        suivant(c);
}

/**
 * @brief Test de fin de cha�ne
 * @param[in] c : la cha�ne test�e
 * @return true si le maillon courant est la fin de cha�ne, false sinon.
 */
bool estFin(const Chaine& c) {
    return *(c.courant) == NULL;
}

/**
 * @brief Positionnement du maillon courant au maillon suivant
 * @param[in,out] c : la cha�ne
 * @pre Le maillon courant existe et ce n'est pas la fin de la cha�ne
 */
void suivant(Chaine& c) {
    assert(!estFin(c));
    c.courant = &((*(c.courant))->suiv);
}
