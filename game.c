#include <stdlib.h>

#include "util.h"
#include "board.h"
#include "game.h"



static bool isIn(uchar *tab[2], int taille, int x, int y){
  int i = 0;
  bool estDejaDansTab;
  i = 0;
  bool sortie = false;
  while (!sortie){
      if (i==taille){
        sortie = true;
        estDejaDansTab = false;
      }
      else if(x == tab[i][0] && y == tab[i][1]){
        sortie = true;
        estDejaDansTab = true;
      }
      i++;
  }
  return estDejaDansTab;
}

/**
  DOXYGEN TODO

*/
int TrouverLaComposante4Connexe(Board *b, uchar *tab[2]){

  int taille = 1;
  tab = xmalloc(sizeof(uchar)*2*taille);
  //tab[0] = [0,0];
  tab[0][0] = 0;
  tab[0][1] = 1;
  int cpt = 0;
  while(cpt!=taille){
    //On regarde les voisins de tab[cpt]
    if (tab[cpt][0]+1 < b->size){
      // si la coord est valide
      if (b->grid[XY(tab[cpt][0], tab[cpt][1])] == b->grid[XY(tab[cpt][0]+1, tab[cpt][1])]){
        // si la couleur est la même
        if (!isIn(tab, taille, tab[cpt][0]+1, tab[cpt][1])){
          // si la case n'est pas déjà ajouté
          // on ajoute [tab[cpt][0]+1,tab[cpt][1]] à tab
          taille +=1;
          tab = xrealloc(tab,sizeof(uchar)*2*taille);
          //tab[taille-1]= [tab[cpt][0]+1,tab[cpt][1]];
          tab[taille-1][0] = tab[cpt][0]+1;
          tab[taille-1][1] = tab[cpt][1];
        }
      }
    }
    if (tab[cpt][1]+1 < b->size){
      if (b->grid[XY(tab[cpt][0], tab[cpt][1])] == b->grid[XY(tab[cpt][0], tab[cpt][1]+1)]){
        if (!isIn(tab, taille, tab[cpt][0], tab[cpt][1]+1)){
          taille +=1;
          tab = xrealloc(tab,sizeof(uchar)*2*taille);
          //tab[taille-1]= [tab[cpt][0],tab[cpt][1]+1];
          tab[taille-1][0] = tab[cpt][0];
          tab[taille-1][1] = tab[cpt][1]+1;
        }
      }
    }
    if (tab[cpt][0]-1 >= 0){
      if (b->grid[XY(tab[cpt][0], tab[cpt][1])] == b->grid[XY(tab[cpt][0]-1, tab[cpt][1])]){
        if (!isIn(tab, taille, tab[cpt][0]-1, tab[cpt][1])){
          taille +=1;
          tab = xrealloc(tab,sizeof(uchar)*2*taille);
          //tab[taille-1]= [tab[cpt][0]-1,tab[cpt][1]];
          tab[taille-1][0] = tab[cpt][0]-1;
          tab[taille-1][1] = tab[cpt][1];
        }
      }
    }
    if (tab[cpt][1]-1 >= 0){
      if (b->grid[XY(tab[cpt][0], tab[cpt][1])] == b->grid[XY(tab[cpt][0], tab[cpt][1]-1)]){
        if (!isIn(tab, taille, tab[cpt][0], tab[cpt][1]-1)){
          taille +=1;
          tab = xrealloc(tab,sizeof(uchar)*2*taille);
          //tab[taille-1]= [tab[cpt][0],tab[cpt][1]-1];
          tab[taille-1][0] = tab[cpt][0];
          tab[taille-1][1] = tab[cpt][1]-1;
        }
      }
    }
  }
  cpt+=1;
  return taille;
}
