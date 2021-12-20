#ifndef _HISTORIQUE_
#define _HISTORIQUE_

/**
 * @file Historique.h
 * @author Kita Etienne
 * @version 1 17/12/2021
 * @brief Projet Demineur SDA, structure Historique
 * 
 */
 
/**
 * @brief Type historique
 */
struct Historique {
	char cCommande;
	unsigned int uiPosition;
};

/** 
 * @brief formater une chaine de charactère en historique
 * @param[out] h : l'historique
 * @param[in] s : Chaine de charactères
 * @pre La chaine doitêtre de longueur 2 ou 3.
 * Le premier élément de la chaine doit être D ou M.
 * Les éléments suivants doivent former un nombre valide pour la grile
 */
void formater(Historique& h, char s[]);

#endif
