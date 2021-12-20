/**
 * @file Historique.cpp
 * @author Kita Etienne
 * @version 1 17/12/2021
 * @brief Projet Demineur SDA, structure Historique
 * 
 */

#include "Historique.h"
#include <cassert>

/** 
 * @brief formater une chaine de charactère en historique
 * @param[out] h : l'historique
 * @param[in] s : Chaine de charactères
 * @pre La chaine doitêtre de longueur 2 ou 3.
 * Le premier élément de la chaine doit être D ou M.
 * Les éléments suivants doivent former un nombre valide pour la grile
 */
void formater(Historique& h, char s[]){
    assert(s[2] == '\0' || s[3] == '\0');
    assert(s[0] == 'D' || s[0] == 'M');
    h.cCommande = s[0];
    if(s[2] == '\0'){
        //atoi est une fonction de c qui transforme une chaine de charactères en entier
        //atoi prend en paramètre l'adresse et s+1 est l'adresse du 2e élément
        //(unsigned int) est là car uiPostion en est un
        h.uiPosition = (unsigned int) atoi(s+1);
    }
    else{
        h.uiPosition = 0;
        h.uiPosition += (unsigned int) atoi(s+1)*10;
        h.uiPosition += (unsigned int) atoi(s+2);
    }
}