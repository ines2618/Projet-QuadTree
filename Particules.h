
#define _PARTICULES_
#ifndef _POINT_
#include "Point.h"
#endif


typedef struct _particules
{
    Point *tab;
    int Np;
    int curlen;

}Particules;



/// @brief fonction qui va alloué un tableau de particules
/// @return renvoie un tableau de particules alloué
Particules * init_tableau_particules(int nb_particules);



/// @brief fonction qui genere un tableau de particules aleatoire
/// @param nb_p 
/// @return un tableau de particules aleatoire alloué
Particules *init_tab_part_aleatoire(int nb_p, int taille_fenetre);



/// @brief ajoute un point dans le tableau de particules
/// @param p 
/// @param part 
/// @return 1 si l'ajout s'est bien passé , 0 en cas d'echec (style ; Nombre de particules)
int ajout_particules(Point *p , Particules *part);



/// @brief fonction qui libèrera le tableau de particules alloué dynamiquement
/// @param part 
void free_particules(Particules *part);



/// @brief fonction qui affiche le tableau de particules
/// @param part 
void affiche_tab(Particules *part);






