
#include "Pliste.h"
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"




Cellule * alloue_tabcell(int Np){
    if(Np <= 0){
        return NULL;
    }
    Cellule *tab = (Cellule *)malloc(sizeof(Cellule)*Np);

    if(!tab){
        fprintf(stderr,"Problème d'allocation dynamique \n");
        return NULL;
    }

    for(int i = 0 ; i < Np ; i++){
        tab[i].p = (Point *)malloc(sizeof(Point));
        if(!tab[i].p){
            fprintf(stderr,"Problème d'allocation dynamique \n");
            for(int j = 0 ; j < i ; j++){
                free(tab[j].p);
            }
            free(tab);
            return NULL;
        }
        tab[i].p->x = 0;
        tab[i].p->y = 0;
    }
    return tab;
}


TabCell init_tab_cell(int Np){
    TabCell tab_cell = {.curlen = 0 , .tab = alloue_tabcell(Np) , .taille = Np};
    return tab_cell;
}


int in_tab(TabCell *tab_cell , Point *p){
    if(!tab_cell || !p){
        return -2;
    }

    for(int i = 0 ; i < tab_cell->curlen ; i++){
        if(tab_cell->tab[i].p->x == p->x && tab_cell->tab[i].p->y == p->y){
            return i; //renvoie l'indice ou le point se trouve
        }
    }
    return -1;
}




int ajout_tab_cell(TabCell *tab_cell,Point *p){
    if(!tab_cell || !p || tab_cell->curlen == tab_cell->taille || in_tab(tab_cell,p) > 0){
        return 0;
    }
    tab_cell->tab[tab_cell->curlen].p->x = p->x;
    tab_cell->tab[tab_cell->curlen].p->y = p->y;
    tab_cell->tab[tab_cell->curlen].next = NULL;
    tab_cell->curlen++;
    return 1;
}





void ajout_en_tete(Cellule **cell,Cellule *tmp){
    if(!(*cell)){
        (*cell) = tmp;
        return;
    }
    tmp->next = (*cell);
    (*cell) = tmp;
    
}


Cellule * pop_point(Cellule **cell){
    Cellule *tmp = (*cell);
    if ((*cell)->next == NULL) {
        (*cell) = NULL;
        return tmp;
    }
    (*cell) = tmp->next;
    tmp->next = NULL;
    return tmp;
}




void libere_tab_cell(TabCell *tab_cell){
    for(int i = 0 ; i < tab_cell->taille ; i++){
        Cellule *tmp = &(tab_cell->tab[i]);
        libere_pliste(&tmp);
    }
    tab_cell = NULL;
   
}




void affiche_tab_cell(TabCell *cell){
    
    for (int i = 0 ; i < cell->curlen ; i++) {
        if(!cell->tab[i].next){
            printf("[(%d %d) , %p]  ",cell->tab[i].p->x , cell->tab[i].p->y ,cell->tab[i].next);
        }else{
            printf("[(%d %d) , chainé à (%d , %d)]  ",cell->tab[i].p->x , cell->tab[i].p->y ,cell->tab[i].next->p->x ,cell->tab[i].next->p->y);
        }

    }
    printf("\n");

}


void affiche_liste(Cellule *lst){
    Cellule *tmp = lst;
    for( ; tmp ; tmp = tmp->next){
        printf("[%d,%d]  ",tmp->p->x,tmp->p->y);
    }
    printf("\n");
}



void libere_pliste(Cellule **cell){
    Cellule * tmp;
    while ((*cell) != NULL) {
        tmp = (*cell);
        (*cell) = (*cell)->next;
        free(tmp->p);
    }
    (*cell) = NULL;
}



