#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
//#include "menu.c"

int main() {

  FILE* f = NULL;
  f=fopen("BDD_v2.csv", "r+");
  if(f==NULL){
      printf("Erreur d'ouverture de fichier !");
  }else{
      printf("Ouverture OK !\n");
  }
  int n=0, i=0, id=0, annee=0;;
  char nom[50];
  n = nb_ligne(f);
  //Film *f_base[n];
  Film *f_bdd=NULL;
  f_bdd = (Film*)malloc(sizeof(Film)*n); // On Alloue la taille necessaire à l'init de la base

  int choix;
  do {
    menu(); // affichage simple du menu
    scanf("%d", &choix);
    switch(choix){
        case 1:
            i=init_bdd(f, &n, f_bdd);
        break;

        case 2:
            if (i!=0){
                printf("Entrez le nom du film à chercher : \n");
                scanf("%s", nom);
                chercher_film(f_bdd, nom, &i);
            }else{
                printf("Erreur : la base n'est pas initialiser !\n");
            }
        break;

        case 3:
            if (i!=0){
                printf("Entrez le nom du film à chercher : \n");
                scanf("%s", nom);
                id=chercher_id_film(f_bdd, nom, &i);
                printf("%d", id);
            }else{
                printf("Erreur : la base n'est pas initialiser !\n");
            }
        break;

        case 4:
            //printf("");
            if (i!=0){
                lister_film(f_bdd, 0, &i); //0 = Trie par genre
            }else{
                printf("Erreur : la base n'est pas initialiser !\n");
            }
        break;

        case 5:
            if (i!=0){
                lister_film(f_bdd, 1 , &i); //1 = trie par annee
            }else{
                printf("Erreur : la base n'est pas initialiser !\n");
            }
        break;

        case 6:
            if (i!=0){
                lister_film(f_bdd, 2 , &i); //1 = par pays
            }else{
                printf("Erreur : la base n'est pas initialiser !\n");
            }
        break;
        case 7:
            bonus();
        break;

        default:
        break;
    }
  }while(choix!=0);
  free(f_bdd); //C'est bon je te relache ! Va en paix mamen !
  printf("L'équipe Movie Analytics vous souhaite de bonne fêtes !\n\n");
}