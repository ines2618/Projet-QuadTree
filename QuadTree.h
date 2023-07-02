#define _QUADTREE_

#ifndef _PLIST_
#include "Pliste.h"
#endif

#ifndef _PARTICULES_
#include "Particules.h"
#endif


#define MAX(a, b) ((a > b) ? (a) : (b))



typedef struct _dim
{
    int x; //coordonnées coin gauche 
    int y;  
    int widht,height; //dimension du carré
}Dimension;



typedef struct _noeud
{
    Dimension dim;
    Pliste lst;
    int nbp;
    int fils[4]; // contient l'indice des fils
}Noeud;




typedef struct _quadtree
{
    Noeud *tree;
    int curlen;
    int maxlen;
}QuadTree;




/// @brief fonction qui determine la taille du quadtree jusqu'à sa plus fine resolution (1x1 pixels)
/// @param widht 
/// @return 
int taille_quadtree(int taille_fenetre);


/// @brief fonction qui allouera le quadtree
/// @return un pointeur un quadtree initialisé
QuadTree * init_quadtree(int taille);


/// @brief fonction qui intialise la racine du quadtree(indice 0),la racine sera toujours intialisé au debut
/// @param quad 
/// @param widht 
/// @param height 
void init_racine(QuadTree *quad,int widht , int height );



/// @brief fonction qui initialise les indices des fils du noeud 
///(si ils sont à 0 cela signifie que le noeud n'a pas de fils)
/// @param noeud 
void init_fils(Noeud *noeud);




/// @brief fonction qui regarde si le point est contenu strictement dans le noeud ou pas
/// cette fonction nous permettra de savoir à quel noeud il faut ajouter le point
/// @param tree 
/// @param p 
/// @return 1 si le point est contenu dans le noeud , 0 sinon
int est_dans_noeud(Noeud *noeud , Point *p);



/// @brief fonction qui regarde si un noeud est terminal , c'est à dire atteint la resolution max (argument du programme)
/// @param noeud 
/// @param wmin 
/// @return 1 si il est terminal , 0 sinon
int est_terminal(Noeud *noeud , int wmin);



/// @brief fonction qui ajoute un noeud dans le quadtree à la position pos
/// @param tree 
/// @param fils 
/// @param pos 
/// @return 1 si l'ajout s'est bien deroulé , 0 dans le cas ou le noeud en question à un nbp > kp , il faudra le purger
int ajout_noeud(QuadTree *tree , Noeud fils , int pos);



/// @brief fonction auxiliaire qui genere le fils nord-est à partir des dimensions du père
/// @param x 
/// @param y 
/// @param widht 
/// @param height 
/// @return le noeud representant le fils nord-est 
Noeud genere_fils_nord_est(int x , int y , int widht , int height);

/// @brief fonction auxiliaire qui genere le fils nord-ouest à partir des dimensions du père
/// @param x 
/// @param y 
/// @param widht 
/// @param height 
/// @return le noeud representant le fils nord-ouest
Noeud genere_fils_nord_ouest(int x , int y , int widht , int height);

/// @brief fonction auxiliaire qui genere le fils sud-est à partir des dimensions du père
/// @param x 
/// @param y 
/// @param widht 
/// @param height 
/// @return le noeud representant le fils sud-est
Noeud genere_fils_sud_est(int x , int y , int widht , int height);

/// @brief fonction auxiliaire qui genere le fils sud-ouest à partir des dimensions du père
/// @param x 
/// @param y 
/// @param widht 
/// @param height 
/// @return le noeud representant le fils sud-ouest
Noeud genere_fils_sud_ouest(int x , int y , int widht , int height);


/// @brief fonction qui gènère les fils du noeud pos et les ajoute à la structure du quadtree
/// @param quad 
/// @param pos 
/// @return 1 si ca s'est bien passé , 0 sinon
int genere_fils(QuadTree *quad , int pos);


/// @brief fonction qui va subdivise le nooeud
///cette fonction va crée les 4 nouveaux fils
/// @param noeud 
void subdivise_noeud(QuadTree *quad , int pos);



/// @brief fonction qui va determiner dans quel fils du noeud le point p appartient
/// cette fonction sera utilie lors de la subdivision du noeud , elle nous permettra de savoir
/// dans quel fils le point va etre placé 
/// @param quad 
/// @param noeud 
/// @param p 
/// @return l'indice du fils si il existe -1 en cas d'echec 
///(exemple : taille_fenetre qui n'est pas une puissance de 4 , cela provoque une mauvaise subdivison du quadTree)
int fils_noeud(QuadTree *quad, Noeud *noeud, Point *p);



/// @brief fonction recursive qui va effectuer l'algo de purge du quadtree 
/// la fonction inserera dans le noeud à la position pos, le point p , si ce dernier n'est pas saturé
/// sinon elle regarde si le noeud est interne si oui alors elle insere le point au niveau de son fils
/// sinon cela signfie que l'on a à faire à une feuille saturé , le noeud doit etre alors subdivisé ,les points contenu dans ce noeud 
/// seront alors redistribué dans les fils de ce noeud.
/// on inserera toujours à partir de la racine
/// @param tree le quadtree
/// @param cell la cellule qui contiendra le point à ajouter
/// @param pos position du noeud à laquelle on insere le point (toujours la racine)
/// @param kp nombre de particules maximal dans un noeud (arguments du programme)
/// @param wmin resolution minimal de la feuille
void traitement_particules(QuadTree *tree ,Cellule *cell,int pos,int kp,int wmin);



/// @brief fonction qui affiche le quadtree 
/// @param tree 
void affiche_quad(QuadTree *tree);


/// @brief fonction qui affiche le nombre de particules contenu dans chaque noeud du quadtree
/// @param tree 
void affiche_nbp_quadtree(QuadTree *tree);


/// @brief fonction qui effectue la liberation du quadtree
/// @param tree 
void libere_quadtree(QuadTree *tree);