#define _PLIST_


#ifndef _POINT_
#include "Point.h"
#endif


typedef struct _cell
{
    Point * p; //point tjrs le meme donc pourquoi pas un const Point *p ?? à méditer
    struct _cell *next; //peut etre que ce serait pertinent d'ajouter un pointeur sur la tete de liste
}Cellule,*Pliste;


typedef struct _tabcell
{
    Cellule *tab;
    int taille;
    int curlen;
}TabCell;



/// @brief fonction qui va alloué le tableau de cellules d'un coup 
/// la taille du tableau dependra du nb de particules
/// @param Np  nombre particules
/// @return un tableau de cellule alloué
Cellule * alloue_tabcell(int Np);



/// @brief fonction qui va initialise un tableau de cellule
/// @param Np  nombre particules
/// @return un tableau de cellule initialisé
TabCell init_tab_cell(int Np);



/// @brief fonction qui regarde si un point est dans le tableau de cellule
/// @param tab_cell 
/// @param p 
/// @return 
int in_tab(TabCell *tab_cell , Point *p);



/// @brief fonction qui ajoute un point dans le tableau de cellule
/// @param tab_cell 
/// @param p 
int ajout_tab_cell(TabCell *tab_cell,Point *p);



/// @brief fonction ajoute en tete d'une pliste (type Cellule **)
/// @param cell 
/// @param tmp 
void ajout_en_tete(Cellule **cell,Cellule *tmp);


/// @brief fonction qui pop le premier point de la liste
/// @param cell 
/// @return la cellule qui a ete supprimé
Cellule* pop_point(Cellule **cell);



/// @brief fonction qui affiche le tableau de cellule
/// @param cell 
void affiche_tab_cell(TabCell *cell);


/// @brief fonction qui affiche une liste
/// @param pliste 
void affiche_liste(Cellule *pliste);

/// @brief fonction qui libere une liste de cellule
/// @param pliste 
void libere_pliste(Cellule **cell);

/// @brief fonction qui libere le tableau de cellule
/// @param cell 
void libere_tab_cell(TabCell *cell);


