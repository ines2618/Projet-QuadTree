
#include "Particules.h"



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>



Particules * init_tableau_particules(int nb_particules){
    Particules *part = (Particules *)malloc(sizeof(Particules));
    if(!part || nb_particules == 0){
        return NULL;
    }
    part->tab = (Point *)malloc(sizeof(Point)*nb_particules);
    if(!part->tab){
        free(part);
        return NULL;
    }
    part->curlen = 0;
    part->Np = nb_particules;

    return part;

}


int ajout_particules(Point *p , Particules *part){
    if(part->Np == part->curlen || p == NULL){
        return 0;
    }
    part->tab[part->curlen] = *p;
    part->curlen++;
    return 1;
}



Particules *init_tab_part_aleatoire(int nb_p,int taille_fenetre){
    Particules *part = init_tableau_particules(nb_p);
    Point p_alea;
    for(int i = 0 ; i < nb_p ; i++){
        p_alea.x = rand() % taille_fenetre;
        p_alea.y = rand() % taille_fenetre;
        ajout_particules(&p_alea,part);
    }
    return part;
}




void free_particules(Particules *part){
    if(part){
        free(part->tab);
        free(part);
    }
    part = NULL;
}


void affiche_tab(Particules *part){
    for(int i = 0 ; i < part->Np ; i++){
        printf("[ %d , %d ] ",part->tab[i].x , part->tab[i].y);
    }
    printf("\n");
}


