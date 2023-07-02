#ifndef __GRAPH__
#define __GRAPH__
#endif

#ifndef _PARTICULES_
#include "Particules.h"
#endif

#ifndef _POINT_
#include "Point.h"
#endif


#ifndef _QUADTREE_
#include "QuadTree.h"
#endif


#include <MLV/MLV_all.h>

#define RAYON 2
#define COUL_POINT MLV_COLOR_BLUE



/* Structure de données qui contiendra toute les parametres du programme */
typedef struct _option
{
    int wmin;
    int taille_fenetre;
    int kp;
    int Np;
    char alea;
    int exit;

}Option;



#define COLOR_1 MLV_rgba(255,0,0,50)
#define COLOR_2 MLV_rgba(0,0,255,50)



/// @brief fonction qui dessine un point
/// @param p 
static void dessine_point(const Point *p);

/// @brief fonction qui dessine l'ensemble des points dans le tableau de particules
/// @param part 
void dessine_points(const Particules *part);





/// @brief fonction qui affiche le QuadTree (subdivision des noeuds ...)
/// @param tree 
/// @param part 
void draw_QuadTree(QuadTree *tree,Particules *part);




/// @brief fonction qui gère les choix du joueur notamment le choix des options 
/// @param opt 
/// @param widht 
/// @param height 
void choix_joueur(Option *opt,int widht,int height);



/// @brief fonction qui gère le choix de la taille de la fenetre et le mode aleatoire ou non
/// @param opt 
/// @param font 
void choix_taille_fenetre_alea(Option *opt , MLV_Font *font);


/// @brief fonction qui gère le choix de Kp : nombre de particules max contenu dans un noeud 
/// Wmin : taille minimal d'un noeud , Np : nombre de particules
/// @param opt 
/// @param font 
void choix_kp_Np_wmin(Option *opt , MLV_Font *font);


/// @brief fonction qui regarde si le joueur a cliqué dans une certaine zone
/// @param x_mouse coordonée en x du clic
/// @param y_mouse coordonée en y du clic
/// coordonné de la zone 
/// @param x 
/// @param y 
/// @param width 
/// @param height 
/// @return 1 si le clic est contenu dans la zone , O sinon
int inside(Point clic, Dimension zone);


/// @brief fonction qui affiche le menu principal
/// @param widht 
/// @param height 
void affiche_menu(int widht,int height);


/// @brief fonction qui affiche une fenetre de fond blanc
/// @param widht 
/// @param height 
void affiche_fond_fenetre(int widht,int height);


/// @brief fonction qui effectue la genereation de point aleatoire et appelle l'algorithme de QuadTree sur ces points
/// @param quad 
/// @param tab_cell 
/// @param alea 
/// @param opt 
void quad_aleatoire(QuadTree *quad , TabCell *tab_cell , Particules *alea ,Option *opt);



/// @brief fonction qui appelle l'algorithme de QuadTree pour le clic joueur
/// @param quad 
/// @param tab_cell 
/// @param part 
/// @param opt 
void quad_clic(QuadTree *quad , TabCell *tab_cell , Particules *part ,Option *opt);