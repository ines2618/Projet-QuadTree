#ifndef _GRAPH_
#include "Graphique.h"
#endif

#ifndef _PARTICULES_
#include "Particules.h"
#endif

#ifndef _QUADTREE_
#include "QuadTree.h"
#endif


#include <MLV/MLV_all.h>

#include <stdio.h>
#include <assert.h>
#include <time.h>




int main(){
    srand(time(NULL));
    Particules *part = NULL;
    TabCell tab_cell;
    QuadTree *quad = NULL;
    Option opt;
    int taille;

    unsigned int widht = 512;
    unsigned int height = 512;
   

    affiche_fond_fenetre(512,512);
    while(1){
        
        affiche_menu(widht,widht);
        choix_joueur(&opt,widht,widht);


        taille = taille_quadtree(opt.taille_fenetre);
        quad = init_quadtree(taille);
        init_racine(quad,opt.taille_fenetre,opt.taille_fenetre);
        tab_cell = init_tab_cell(opt.Np);

        if(opt.exit == 1){
            break;
        }

        MLV_get_window_size(&widht,&height);
        if(opt.taille_fenetre != widht){
            MLV_free_window();
            affiche_fond_fenetre(opt.taille_fenetre,opt.taille_fenetre);
        }


        if(opt.alea == 'o'){
            part = init_tab_part_aleatoire(opt.Np,opt.taille_fenetre);
            quad_aleatoire(quad,&tab_cell,part,&opt);
            MLV_wait_seconds(20);
        }
        else{
            part = init_tableau_particules(opt.Np);
            quad_clic(quad,&tab_cell,part,&opt);
            MLV_wait_seconds(20);
        }

        if(opt.taille_fenetre >= 1024){
            break;
        }


        MLV_clear_window(MLV_COLOR_WHITE);
        MLV_actualise_window();
    }

    MLV_free_window();
    libere_quadtree(quad);
    free_particules(part);

  
    return 0;
}