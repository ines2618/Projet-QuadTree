
#include "Graphique.h"
#include <MLV/MLV_all.h>

#include <stdio.h>
#include <assert.h>
#include <time.h>




void dessine_point(const Point *p){
    assert(p != NULL);

    MLV_draw_filled_circle(p->x, p->y, RAYON, COUL_POINT);
}



void dessine_points(const Particules *part){
    int i;

    assert(part != NULL);

    for(i = 0; i < part->curlen; ++i)
        dessine_point(&(part->tab[i]));
}






void affiche_fond_fenetre(int widht,int height){
    MLV_create_window("QuadTree","QuadTree",widht,height);
    MLV_draw_filled_rectangle(0,0,widht,height,MLV_COLOR_WHITE);
    MLV_actualise_window();
}


void affiche_menu(int widht,int height){
    MLV_Font *font = MLV_load_font("abang.ttf",20);
    int x,largeur,hauteur;
    MLV_Color color;

   
    
    MLV_draw_text_with_font(235,100,"Menu",font,MLV_COLOR_BLACK);
    MLV_draw_text_with_font(235,200,"Options",font,MLV_COLOR_BLACK);
    MLV_draw_text_with_font(235,300,"Quitter",font,MLV_COLOR_BLACK);

    for(int i = 0; i < 40 ; i++){
        x = rand() % widht;
        largeur = rand() % 100 + 10;
        hauteur = rand() % 100 + 10;
        color = MLV_rgba(rand() % 256,rand() % 256 , rand() % 256 , 50);
        MLV_draw_filled_rectangle(x,x,largeur,hauteur,color);
    }


    MLV_actualise_window();
    MLV_free_font(font);
}




int inside(Point clic, Dimension zone){
   return (zone.x <= clic.x && clic.x <= zone.x + zone.widht
           && zone.y <= clic.y && clic.y <= zone.y + zone.height);
}




void choix_kp_Np_wmin(Option *opt , MLV_Font *font){
    char *Kp,*Np,*wmin;
    
    do{
        MLV_wait_input_box_with_font(150,50,200,50,COLOR_2,MLV_COLOR_BLACK,MLV_COLOR_WHITE,"Nombre de Particules ",&Np,font);
        opt->Np = atoi(Np);
    }
    while(opt->Np <= 0);

    do{
        MLV_wait_input_box_with_font(120,150,320,50,COLOR_1,MLV_COLOR_BLACK,MLV_COLOR_WHITE,"Nombre particules max dans un noeud ",&Kp,font);
        opt->kp = atoi(Kp);
    }
    while(opt->kp <= 0);

    do{
        MLV_wait_input_box_with_font(150,250,250,50,COLOR_2,MLV_COLOR_BLACK,MLV_COLOR_WHITE,"Resolution du noeud wmin ",&wmin,font);
        opt->wmin = atoi(wmin);
    }   
    while(opt->wmin <= 0 || (opt->wmin*opt->wmin % 4 != 0 && opt->wmin != 1));

    
}




void choix_taille_fenetre_alea(Option *opt , MLV_Font *font){
    char *alea,*taille_fenetre;
    do{
        
        MLV_wait_input_box_with_font(150,350,235,50,COLOR_1,MLV_COLOR_BLACK,MLV_COLOR_WHITE,"Taille de la fenetre 512/1024/2048 :",&taille_fenetre,font);
        opt->taille_fenetre = atoi(taille_fenetre);
    }
    while(opt->taille_fenetre <= 0 || (opt->taille_fenetre != 512 && opt->taille_fenetre != 1024 && opt->taille_fenetre != 2048));

    do{
        MLV_wait_input_box_with_font(150,450,200,50,COLOR_2,MLV_COLOR_BLACK,MLV_COLOR_WHITE,"Aleatoire : o/n",&alea,font);
        opt->alea = *alea;
    }
    while (opt->alea != 'o' && opt->alea != 'n');
}



void choix_joueur(Option *opt,int widht,int height){
   
    Dimension menu = {215,100,100,20};
    Dimension choix_options = {215,200,100,20};
    Dimension quitter = {220,300,200,20};
    Point clic;
  
    MLV_Font *font = MLV_load_font("arial.ttf",15);
    
    
    do{
        MLV_wait_mouse(&clic.x,&clic.y);
        if(inside(clic,menu)){
            opt->alea = 'n';
            opt->Np = 20;
            opt->kp = 3;
            opt->taille_fenetre = 512;
            opt->wmin = 1;
        }

        if (inside(clic,choix_options)){
        
            MLV_clear_window(MLV_COLOR_WHITE);
            choix_kp_Np_wmin(opt,font);
            choix_taille_fenetre_alea(opt,font);
        }
        if(inside(clic,quitter)){
            opt->exit = 1;
        }
    }
    while(!inside(clic,menu) && !inside(clic,choix_options) && !inside(clic,quitter));
    MLV_actualise_window();
    MLV_free_font(font);

}




void draw_QuadTree(QuadTree *tree,Particules *part){
    MLV_clear_window(MLV_COLOR_WHITE);
    MLV_Color color;
    for(int i = 0 ; i < tree->maxlen ; i++){
        Noeud node = tree->tree[i];

        if(node.nbp != 0 && node.lst != NULL){
            color = MLV_rgba(rand() % 256,rand() % 256 , rand() % 256 , 50);
            MLV_draw_rectangle(node.dim.x,node.dim.y,node.dim.widht,node.dim.height,color);
            MLV_draw_filled_rectangle(node.dim.x,node.dim.y,node.dim.widht,node.dim.height,color);
            MLV_actualise_window();
        }
    }
    dessine_points(part);
}



void quad_clic(QuadTree *quad , TabCell *tab_cell , Particules *part ,Option *opt){
    Point p;

    MLV_clear_window(MLV_COLOR_WHITE);
    
    while(part->curlen != part->Np){
        MLV_wait_mouse(&p.x,&p.y);
        ajout_tab_cell(tab_cell,&p);
        ajout_particules(&p,part);
        dessine_point(&p);      
        traitement_particules(quad,&(tab_cell->tab[tab_cell->curlen-1]),0,opt->kp,opt->wmin);
        draw_QuadTree(quad,part);
        MLV_actualise_window();
    }

}



void quad_aleatoire(QuadTree *quad , TabCell *tab_cell , Particules *alea ,Option *opt){
    
    for(int i = 0 ; i < alea->curlen ; i++){
        ajout_tab_cell(tab_cell,&(alea->tab[i]));
        traitement_particules(quad,&(tab_cell->tab[tab_cell->curlen-1]),0,opt->kp,opt->wmin);
    }
    
   
    
    MLV_clear_window(MLV_COLOR_WHITE);
    draw_QuadTree(quad,alea);
    MLV_actualise_window();
   
    
}


