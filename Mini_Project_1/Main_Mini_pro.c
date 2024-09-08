#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int Nbr_De_Liv = 0;
//-------------------------------------- function d'ajouter -----------------------------
void Ajoute_Une_livre( char title[][20] ,
    char auteur[][20] ,
    float price[] , int quantity[])
    {
     if(Nbr_De_Liv <= MAX){

      printf("Entrez le titre de livre : ");
      scanf(" %[^\n]",title[Nbr_De_Liv]);

      printf("Entrez l'auteur de livre : ");
      scanf(" %[^\n]",auteur[Nbr_De_Liv]);

      printf("Entrez le prix de livre : ");
      scanf("%f",&price[Nbr_De_Liv]);

      printf("Entrez la quantité de livre : ");
      scanf("%d",&quantity[Nbr_De_Liv]);

      Nbr_De_Liv += 1;

      printf("Le Livre a Ajoute avec Succe : \n");
    }else{
        printf("Stock complet , Impossible d'ajouter plus de livres :\n");
        printf("Essayer de vide le stock :\n");
    }
}

//-------------------------------------function d'afficher-------------------------------
void Affiche_livres_dispo(char title[][20], 
        char auteur[][20], float price[],
        int quantity[])
        {
         if(Nbr_De_Liv == 0){
            printf("\nLe stock est vide , Essayez de la remplir : \n");
         }else{

            printf("\nVotre stock contient %d livre :\n",Nbr_De_Liv);
            printf("\nvoici tous les livres disponibles : \n");

         for(int i = 0 ; i < Nbr_De_Liv ; i++ ){
            printf("Livre %d :\n",i+1);
            printf("Titre : %s\n",title[i]);
            printf("Auteur : %s\n",auteur[i]);
            printf("Prix : %.2f DH\n",price[i]);
            printf("Quantité  : %d\n",quantity[i]);
            printf("-------------------\n");
      }
   }
}

//-----------------------------------function d mettre ajour le stock -------------------
void Update_stock(char titre[][20] , int Quant[])
{
   if(Nbr_De_Liv > 0){
        int check = 0;

       do{
           char Tit_Ajour[20];
           int val_Ajour;
           int count = 0;

           printf("Entrez Le Titre De Livre Pour Mettre a Jour sa Quantité : ");
           scanf(" %[^\n]",Tit_Ajour);

           printf("Entrez La Nouvelle Valeur De Sa Quantité : ");
           scanf("%d",&val_Ajour);

           int leng = strlen(Tit_Ajour);

           for(int i = 0 ; i < Nbr_De_Liv ; i++){//pass sur les titres
                for(int j = 0 ; titre[i][j] != '\0' ; j++){//pass sur chaque titre
                    if(titre[i][j] == Tit_Ajour[j])//comparison entre les deux titre
                        count++;
                    else{
                        check++;//si le titre entreé par l'étulisateur et le titre stocké dans le tableau pas le mémé
                        break;
                   }
                   if( count == leng){
                        Quant[i] = val_Ajour;//changer le precedent quantité par nouvelle valeur
                        printf("La Quantité de Livre donné Mettre a jour avec succe:\n");
                   }
                 }
              }
             if(check == Nbr_De_Liv){
                        printf("\nLe Titre Donné est pas existe dans le stock : \n");
                        printf("\nEssayez encore Par Une Correct Titre : \n");
             }
        }while(check == Nbr_De_Liv);
    }else{
        printf("\nLe Stock est Vide Rien de Mettre a Jour :\n");
    }
}

void Suppri_livre();
void Display_nmr_total(); 

// la function int main commance sa execution
int main(){                       //_______
    char Tit_liv[MAX][20];        //       | 
    char Auteu_liv[MAX][20];      //       |------>declarer les tableau principal
    float Prix[MAX];              //       |
    int Quant[MAX];               //_______| 
                                   

  int choix;
  do{
    //menu principal
   printf(" _________________________________________________________________\n");
   printf("| -----------------------------------------------------------     |\n");
   printf("| |         BIENVENUE A VOTRE STOCK DE LIVRES                |    |\n");
   printf("| -----------------------------------------------------------     |\n");
   printf("|                                                                 |\n");
   printf("| |--------------[Voici le menu principal]-----------------|      |\n");
   printf("|_1). Ajouter un livre au stock.:                                 |\n");
   printf("|_2). Afficher tous les livres disponibles. :                     |\n");
   printf("|_3). Mettre à jour la quantité d'un livre. :                    |\n");
   printf("|_4). Supprimer un livre du stock. :                              |\n");
   printf("|_5). Afficher le nombre total de livres en stock.:               |\n");
   printf("|_6). Quitter :                                                   |\n");
   printf("|_________________________________________________________________|\n");
   printf("\n");
   printf("Utilisez les nombres pour choisir votre choix :\n");
   printf("\n");
   printf("Choisissez une option : ");
   scanf("%d",&choix);
   switch(choix)
   {
    case 1:
        Ajoute_Une_livre(Tit_liv,Auteu_liv,Prix,Quant);//la function d'ajouter
        break;
    case 2:
        Affiche_livres_dispo(Tit_liv,Auteu_liv,Prix,Quant);//la function d'afficher
        break;
    case 3:
        Update_stock(Tit_liv,Quant);//la function pour mettre a jour 
        break;
    
    case 4:
        Suppri_livre(Tit_liv,Auteu_liv,Prix,Quant);//la function pour supprimer l'élement
        break;
    case 5:
        Display_nmr_total(Quant);//la function pour afficher le nombre total de tous les livres
        break;
    case 6:
         printf("Passe une bonne journée!:\n");
         break;
    default:
        printf("Votre choix est invalide. Essayer encore :\n");
    }
    }while (choix != 6);
 

 return 0;
}

//---------------------------------function de supprimer ---------------------------------
void Suppri_livre(char titre[][20],
  char auteur[][20],float price[],int quantity[]){

   if(Nbr_De_Liv > 0){
        int check = 0;

       do{
           char Tit_suppr[20];
           int count = 0;

           printf("Entrez Le Titre De Livre Pour La Suppreme : ");
           scanf(" %[^\n]",Tit_suppr);

           int leng = strlen(Tit_suppr);

           for(int i = 0 ; i < Nbr_De_Liv ; i++){//pass sur les titres
                for(int j = 0 ; titre[i][j] != '\0' ; j++){//pass sur chaque titre
                    if(titre[i][j] == Tit_suppr[j])//comparison entre les deux titres
                        count++;
                    else{
                        check++;//si le titre entreé par l'étulisateur et le titre stocké dans le tableau pas le mémé
                        break;
                    }if( count == leng){
                        Nbr_De_Liv--;
                         for(int i = check ; i <= Nbr_De_Liv ; i++){
                             for(int j = 0 ; titre[i][j] != '\0' ; j++){
                                    titre[i][j] = titre[i + 1][j];
                                }
                              for(int j = 0 ; auteur[i][j] != '\0' ; j++){
                                    auteur[i][j] = auteur[i + 1][j];
                                }
                            }
                            for(int j = check ; j <= Nbr_De_Liv ; j++){
                                    price[j] = price[j+1];
                                }
                            for(int j = check ; j <= Nbr_De_Liv ; j++){
                                    quantity[j] = quantity[j+1];
                                }
                         printf("\nLe Livre Supprime Avec succe : \n");
                         return;
                     }

                  }
               }

             if(check == Nbr_De_Liv){
                        printf("\nLe Titre Donné est pas existe Dans le Stock : \n");
                        printf("\nEssayez encore Par Une Correct Titre: \n");
             }
        }while(check == Nbr_De_Liv);
    }else{
        printf("\nLe Stock est Vide Rien De Supprimer :\n");
    }
}

//--------------------------------function d'afficher la quantité des livres ------------------
void Display_nmr_total(int quantity[]){
         int somme = 0;
         for(int i = 0 ; i < Nbr_De_Liv ; i++){
               somme = somme + quantity[i];
         }     

         printf("\nLe Nombre Total De Livres En Stock est : %d \n",somme);
} 