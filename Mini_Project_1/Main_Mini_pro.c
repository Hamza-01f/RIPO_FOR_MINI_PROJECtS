#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int Nbr_De_Liv = 0;
//-------------------------------------- function d'ajouter -----------------------------
void Ajoute_Une_livre( char title[][20] ,
    char auteur[][20] ,
    int price[] , int quantity[])
    {
     if(Nbr_De_Liv <= MAX){


      printf("Entrez le titre de livre : ");
      scanf(" %[^\n]",title[Nbr_De_Liv]);
    
      printf("Entrez l'auteur de livre : ");
      scanf(" %[^\n]",auteur[Nbr_De_Liv]);

      printf("Entrez le prix de livre : ");
      scanf("%d",&price[Nbr_De_Liv]);

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
        char auteur[][20], int price[],
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
            printf("Prix : %d DH\n",price[i]);
            printf("Quantité  : %d\n",quantity[i]);
            printf("-------------------\n");
      }
   }
}

//-----------------------------------function d mettre ajour le stock -------------------
void Update_stock(char titre[][20],int Quant[])
{
   if(Nbr_De_Liv > 0){
        
        int exact_indix;
        int call ;

       do{
           char Tit_Ajour[20];
           int val_Ajour;

           printf("Entrez Le Titre De Livre Pour Mettre a Jour sa Quantité : ");
           scanf(" %[^\n]",Tit_Ajour);

           call = Verify_existance(titre,Tit_Ajour,&exact_indix);

           if(call == 1){
               printf("Entrez La Nouvelle Valeur De Sa Quantité : ");
               scanf("%d",&val_Ajour);

               Quant[exact_indix] = val_Ajour;//changer le precedent quantité par nouvelle valeur

              printf("La Quantité de Livre donné Mettre a jour avec succe:\n");

              return;
           }else{
                        printf("\nLe Titre Donné est pas existe dans le stock : \n");
                        printf("\nEssayez encore Par Une Correct Titre : \n");
             }
        }while( call != 1);
    }else{
        printf("\nLe Stock est Vide Rien de Mettre a Jour :\n");
    }
}

void Suppri_livre();
void Display_nmr_total(); 
void Recherche_Livre();
int  Verify_existance();

// la function int main commance sa execution
int main(){                       //_______
    char Tit_liv[MAX][20];        //       | 
    char Auteu_liv[MAX][20];      //       |------>declarer les tableau principal
    int Prix[MAX];              //       |
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
   printf("|_3). Mettre à jour la quantité d'un livre. :                     |\n");
   printf("|_4). Supprimer un livre du stock. :                              |\n");
   printf("|_5). Afficher le nombre total de livres en stock.:               |\n");
   printf("|_6). Rechercher un livre . :                                     |\n");
   printf("|_7). Quitter :                                                   |\n");
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
        Recherche_Livre(Tit_liv,Auteu_liv,Prix,Quant);//la function pour rechercher
        break;
    case 7:
         printf("Passe une bonne journée!:\n");//pour quitter
         break;
    default:
        printf("Votre choix est invalide. Essayer encore :\n");
    }
    }while (choix != 7);//stop le menu
 

 return 0;
}

//---------------------------------function de supprimer ---------------------------------
void Suppri_livre(char titre[][20],
  char auteur[][20],int price[],int quantity[]){

   if(Nbr_De_Liv > 0){
        int call;
        int exact_indix = 0;

       do{
           char Tit_suppr[20];

           printf("Entrez Le Titre De Livre Pour La Suppreme : ");
           scanf(" %[^\n]",Tit_suppr);//l'entrée de le livre 
        
           call = Verify_existance(titre,Tit_suppr,&exact_indix);

                      if( call == 1){
                        Nbr_De_Liv--;
                         for(int i = exact_indix ; i <= Nbr_De_Liv ; i++){
                             for(int j = 0 ; titre[i][j] != '\0' ; j++){
                                    titre[i][j] = titre[i + 1][j];
                                }
                              for(int j = 0 ; auteur[i][j] != '\0' ; j++){
                                    auteur[i][j] = auteur[i + 1][j];
                                }
                            }
                            for(int j = exact_indix ; j <= Nbr_De_Liv ; j++){
                                    price[j] = price[j+1];
                                }
                            for(int j = exact_indix ; j <= Nbr_De_Liv ; j++){
                                    quantity[j] = quantity[j+1];
                                }
                         printf("\nLe Livre Supprime Avec succe : \n");
                         return;
                       }else{
                         printf("\nLe Titre Donné est pas existe Dans le Stock : \n");
                         printf("\nEssayez encore Par Une Correct Titre: \n");
                       }
        }while(call != 1);
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

//-----------------------------------function de rechercher -------------------------------------------------------------
void Recherche_Livre(char Titre[][20],char auteur[][20],int price[],int quantity[]){
        if(Nbr_De_Liv > 0){
         
         int call ;
         int exact_indix = 0 ;
        do{
           char Tit_rechercher[20];

           printf("Entrez Le Titre De Livre Que Vous Voulez Cherchez : ");
           scanf(" %[^\n]",Tit_rechercher);

              call = Verify_existance(Titre,Tit_rechercher,&exact_indix);
                      if(call == 1){
                         printf("\nLe Livre Trouver Avec Succe : \n");
                         printf("\nVoici les information de ce livre : \n");
                         printf("Titre : %s\n",Titre[exact_indix]);
                         printf("Auteur : %s\n",auteur[exact_indix]);
                         printf("Prix : %d DH\n",price[exact_indix]);
                         printf("Quantité  : %d\n",quantity[exact_indix]);
                         printf("-------------------\n");
                         return;
                        }else{
                        printf("\nLe Titre Donné est pas existe Dans le Stock : \n");
                        printf("\nEssayez encore Par Une Correct Titre: \n");
                        }
         }while(call != 1);
     }else
          printf("\nLe Stock est Vide Rien De Rechercher :\n");

  }

//------------------------------ verifier si le titre exist ou non -------------------------------------
int Verify_existance(char Titre[][20] ,char extra_table[],int *exact_ind){
         int count = 0;
         int check = 0;

         int leng = strlen(extra_table);
        for(int i = 0 ; i < Nbr_De_Liv ; i++){//pass sur les titres
                for(int j = 0 ; Titre[i][j] != '\0' ; j++){//pass sur chaque titre
                    if(Titre[i][j] == extra_table[j]){//comparison entre les deux titres
                            count++;
                      if( count == leng){
                        *exact_ind = i;
                         return 1;
                        }
                     
                    }else{
                        check++;//si le titre entreé par l'étulisateur et le titre stocké dans le tableau pas le méme
                        break;
                     }
                  }
               }
        if(check != 0)
        return 2;
}
