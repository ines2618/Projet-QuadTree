#ifndef _QUADTREE_
#include "QuadTree.h"
#endif

#ifndef _PLIST_
#include "Pliste.h"
#endif

#ifndef _PARTICULES_
#include "Particules.h"
#endif


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>




int taille_quadtree(int widht){
    return (4*(widht*widht) - 1)/3;
}



QuadTree * init_quadtree(int taille){
    QuadTree *quad = (QuadTree *)malloc(sizeof(QuadTree));
    if(!quad || taille <= 0){
        return NULL;
    }
    quad->tree = (Noeud *)malloc(sizeof(Noeud) * taille);
    if(!quad->tree){
        return NULL;
    }
    quad->maxlen = taille;
    quad->curlen = 0;
    return quad;
}



void init_racine(QuadTree *quad,int widht , int height ){
    if(!quad || widht <= 0 || height <= 0){
        return ;
    }

    quad->tree[0].dim.x = quad->tree[0].dim.y = 0;
    quad->tree[0].dim.widht = widht;
    quad->tree[0].dim.height = height;
    quad->tree[0].lst = NULL;
    quad->tree[0].nbp = 0;
    quad->curlen = 1;
    init_fils(&(quad->tree[0]));
}






void init_fils(Noeud *noeud){
    for(int i = 0 ; i < 4; i++){
        noeud->fils[i] = 0;
    }
}



static int chercher_fils(int indice_pere){
    int indice_fils;
    indice_fils = (4 * indice_pere) + 1;
    return indice_fils;
}





int est_dans_noeud(Noeud *noeud , Point *p){
    if(!noeud || !p){ return 0;}
   return (p->x >= noeud->dim.x && p->x <= (noeud->dim.x + noeud->dim.widht ) )&&  (p->y >= noeud->dim.y && p->y <= (noeud->dim.y + noeud->dim.height));
}



int est_terminal(Noeud *noeud , int wmin){
    if(!noeud){ return 0;}
    return noeud->dim.widht <= wmin && noeud->dim.height <= wmin;
}



int ajout_noeud(QuadTree *quad , Noeud fils , int pos){
    if( !quad || pos >= quad->maxlen - 1 ){
        return 0;
    }
    quad->tree[pos] = fils;
    quad->curlen += pos +1;
   
    return 1;
}


Noeud genere_fils_nord_est(int x , int y , int widht , int height){
    Noeud NE;

    NE.dim.x = x;
    NE.dim.y = y;
    NE.dim.widht = widht;
    NE.dim.height = height;
    NE.lst = NULL;
    NE.nbp = 0;
    init_fils(&NE);
   
    return NE;
}


Noeud genere_fils_nord_ouest(int x , int y , int widht , int height){
    Noeud NO;

    NO.dim.x = x ;
    NO.dim.y = y;
    NO.dim.widht = widht;
    NO.dim.height = height;
    NO.lst = NULL;
    NO.nbp = 0;
    init_fils(&NO);

    return NO;
}



Noeud genere_fils_sud_est(int x , int y , int widht , int height){
    Noeud SE;

    SE.dim.x = x ;
    SE.dim.y = y ;
    SE.dim.widht = widht;
    SE.dim.height = height;
    SE.lst = NULL;
    SE.nbp = 0;
    init_fils(&SE);
   
    return SE;
}



Noeud genere_fils_sud_ouest(int x , int y , int widht , int height){

    Noeud SO;
    
    SO.dim.x = x ;
    SO.dim.y = y;
    SO.dim.widht = widht;
    SO.dim.height = height;
    SO.lst = NULL;
    SO.nbp = 0;
    init_fils(&SO);
   
    return SO;
}




int genere_fils(QuadTree *quad , int pos){
    if( !quad || pos >= quad->maxlen){
       
        return 0;
    }

    Dimension pere = quad->tree[pos].dim; 
    int indice_fils = chercher_fils(pos);
    Noeud NE,NO,SO,SE;


    NO = genere_fils_nord_ouest(pere.x,pere.y,pere.widht/2,pere.height/2);
    NE = genere_fils_nord_est(pere.x + pere.widht/2, pere.y, pere.widht/2, pere.height/2);
    SE = genere_fils_sud_est(pere.x + pere.widht/2, pere.y + pere.height/2, pere.widht/2, pere.height/2);
    SO = genere_fils_sud_ouest(pere.x, pere.y + pere.height/2, pere.widht/2, pere.height/2);
   
    //ajout des fils dans le quadtree 
    if(!ajout_noeud(quad,NO,indice_fils)){return 0;}
    if(!ajout_noeud(quad,NE,indice_fils + 1)){return 0;}
    if(!ajout_noeud(quad,SE,indice_fils + 2)){return 0;}
    if(!ajout_noeud(quad,SO,indice_fils + 3)){return 0;}

    return 1;
}



void subdivise_noeud(QuadTree *quad , int pos){
    int indice_fils = chercher_fils(pos);
    if(genere_fils(quad,pos)){
        quad->tree[pos].fils[0] = indice_fils;
        quad->tree[pos].fils[1] = indice_fils + 1;
        quad->tree[pos].fils[2] = indice_fils + 2;
        quad->tree[pos].fils[3] = indice_fils + 3;
    }
}



void affiche_quad(QuadTree *tree){
    printf("Racine : [ x : %d , y : %d , widht : %d , height : %d] \n", tree->tree[0].dim.x ,tree->tree[0].dim.y , tree->tree[0].dim.widht , tree->tree[0].dim.height);
    for(int i = 1 ; i < tree->curlen ; i++){
        if(tree->tree[i].nbp != 0){
            printf("Noeud %d : nbp : %d \n",i,tree->tree[i].nbp);
        
        }
        else if(tree->tree[i].nbp != 0 && tree->tree[i].lst != NULL){
            printf("Fils %d : nbp : %d, Point : [%d , %d] \n",i,tree->tree[i].nbp,tree->tree[i].lst->p->x,tree->tree[i].lst->p->y);
        }
    }
    printf("\n");
}


void affiche_nbp_quadtree(QuadTree *tree){
    for(int i = 0 ; i < 5 ; i++){
        printf("Nbp : %d \n",tree->tree[i].nbp);
    }
    printf("\n");
}





int fils_noeud(QuadTree *quad, Noeud *noeud, Point *p) {
    for(int i = 0 ; i < 4 ; i++){
        int fils = noeud->fils[i];
        if (fils != 0 && est_dans_noeud(&quad->tree[fils], p)){
            return fils;
        }
    }

    return -1; //si il ne le trouve pas typiquement , tas de taille trop petite
}







void affiche_fils(QuadTree *quad,Noeud *node){
    fprintf(stderr,"les fils sont \n");
    for(int i = 0 ; i < 4  ; i++){
        int fils = node->fils[i];
        Noeud *node = &(quad->tree[fils]);
        fprintf(stderr,"Node : pos : %d [NBP : %d , widht : %d , height : %d , x : %d , y : %d ]\n \n",fils,node->nbp,node->dim.widht,node->dim.height,node->dim.x,node->dim.y);
    }
}



void traitement_particules(QuadTree *quad, Cellule *cell, int pos,int kp,int wmin)
{
    int fils = 0;
    assert(quad != NULL);
    assert(cell != NULL);
   
    Noeud * node = &(quad->tree[pos]);

    if( node->nbp < kp || est_terminal(node,wmin)){ //on ajoute simplement à la liste des particules si c'est une feuille, ou un noeud terminal
        ajout_en_tete(&(node->lst),cell);
        node->nbp++;
        return ;
        
    }
    else if(node->nbp > kp && node->fils[0] != 0 && node->lst == NULL){ //c'est un noeud interne , on regarde directement dans ses fils
        fils = fils_noeud(quad,node,cell->p);
        traitement_particules(quad,cell,fils,kp,wmin);
        node->nbp++;
    }
    else{  //cela signifie que ce n'est pas un noeud interne et que l'on doit subdiviser le noeud et appeler recursivement sur chacun des fils
        subdivise_noeud(quad,pos);
        fils = fils_noeud(quad,node,cell->p);
        traitement_particules(quad,cell,fils,kp,wmin);
        node->nbp++;
        
        while(node->lst != NULL){
            Cellule * tmp = pop_point(&node->lst);
            fils = fils_noeud(quad,node,tmp->p);
            traitement_particules(quad,tmp,fils,kp,wmin);
        }
        
    
    
    }
    
}


void libere_quadtree(QuadTree *tree){
    for(int i = 0 ; i < tree->maxlen ; i++){
        libere_pliste(&(tree->tree[i].lst));
    }
    free(tree->tree);
    tree = NULL;
}


