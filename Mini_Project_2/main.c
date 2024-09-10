#include <stdio.h>
#include <string.h>
#define MAX 100
int NumberContacts = 0;
int NumberIndix = 0;

typedef struct{

    char AddressEmail[30];

}Email;

typedef struct{

    Email mail;//----------Nested email address structure ------------------------------------------
     char Nom[20];
     char NumeroDeTelephone[10];

}contact;

contact Informations[MAX];

int verifierLexistance();
void ModifierLeNombre();
void ModifierAddressEmail();
void afficherTousNom();
int DisplayMenu();
void AfficherLesinformationDeContact();
void AfficherSeulNom();
void DeleteNoms();
void AjouteLesInformation();
void TrouverPasLelement();

//-----------------------------------les principal functions--------------------------------------


void AjouteUneContact() {//----------------------la functions d'ajoute-----------------------------
    char VerifierLeNom[20];
    int call;

    do {
        if (NumberContacts == 0) {
               AjouteLesInformation();
               return;
        } else {
            printf("Entrez le nom du contact pour vérifier sa existence : ");
            scanf("%20s", VerifierLeNom);
            call = verifierLexistance(VerifierLeNom);

            if (call != -1) {
                printf("\n");
                printf("Ce Contact Est Déjà Entré.\n");
                printf("Pour éviter Les Conflits: \n");
                printf("Essayez D'entrer Un Nouveau Nom : \n");
                afficherTousNom();
            } else {
                
                printf("\n");
                printf("Ce Valeur est  Nouvelle : \n");

                printf("\n");
                AjouteLesInformation();
                return;//return to main function
            }
        }
    } while (call != -1);//si la valeur entrer déja existe la boocle va commancer l'opération a zéro
}

 void ModifierUnContact(){ 

  if(NumberContacts != 0){

      char verifierNom[20];
      int choix;
      int call;
      int choixHold;

     do{
           printf("Entrez Le Nom Du Contact Pour Modifier Ses Informations : ");
           scanf("%20s",verifierNom);
           call = verifierLexistance(verifierNom);
           if(call != -1)
            {
              choixHold = DisplayMenu(choix);
             switch(choixHold){
             case 1 :
                  ModifierLeNombre();
                  return;
             case 2:
                  ModifierAddressEmail();
                  return;
             case 3:
                 printf("Retour Au Menu Principal : \n");
                 break;
             default:
               printf("Invalid Valeur , Essayer Encore : \n");
               break;
            
            }
           }else{
              TrouverPasLelement();
          }
     }while(choixHold != 3 ); 
 }else{
         printf("Le Contact Est Vide Essayer Promiérement D'ajouter Des Contactes : \n");
    }
 }
 void  SupprimerContact(){
      char VerifierLeNom[20];
      int call ;
     do{
         printf("Entrez Le Nom De Contact Pour La Supprime : ");
         scanf("%20s",VerifierLeNom);

         call = verifierLexistance(VerifierLeNom);
         if( call != -1){
             DeleteNoms();
             printf("\n");
             printf("Le Contact a été Supprimé Avec Succès : \n");
             NumberContacts--;
            }else{
               TrouverPasLelement();
            }
     }while (call == -1 );
     
   

 }

void AfficherTousLesContact(){
  if(NumberContacts != 0 ){
 
     AfficherLesinformationDeContact();
    
   }else{
         printf("Votre Contact est vide : \n");
         printf("\n");
         printf("Essayer De La Remplir: \n");
         printf("Rien à Afficher : \n");
         
   }

}

void RechercheContacte(){
    char VerifierLeNom[20];
    int call;
    do{  
      printf("Entrez Le Contact Que Vous Souhaitez Rechercher : ");
      scanf("%20s",VerifierLeNom);
      call = verifierLexistance(VerifierLeNom);
      if(call != -1 ){
             AfficherSeulNom();
             return;
       }else{
             TrouverPasLelement();
       }
    }while(call != 1);

}

//---------------------------------------la functions int main -------------------------------------

int main() {
    int choix;
    do {
        printf(" _________________________________________________________________\n");
        printf("| -----------------------------------------------------------     |\n");
        printf("| |         BIENVENUE A VOTRE CONTACTES                      |    |\n");
        printf("| -----------------------------------------------------------     |\n");
        printf("|                                                                 |\n");
        printf("| |--------------[Voici le menu principal]-----------------|      |\n");
        printf("|_1). Ajouter Un Contact . :                                      |\n");
        printf("|_2). Modifier Un Contact . :                                     |\n");
        printf("|_3). Supprimer Un Contact. :                                     |\n");
        printf("|_4). Afficher Tous Les Contactes . :                             |\n");
        printf("|_5). Rechercher Un Contact. :                                    |\n");
        printf("|_6). Quitter :                                                   |\n");
        printf("|_________________________________________________________________|\n");
        printf("\nChoisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                AjouteUneContact();
                break;
            case 2:
                ModifierUnContact();
                break;
            case 3:
                SupprimerContact();
                break;
            case 4:
                AfficherTousLesContact();
                break;
            case 5:
                RechercheContacte();
                break;
            case 6:
                printf("Passe une bonne journée!\n");
                break;
            default:
                printf("Votre choix est invalide. Essayez encore :\n");
        }
    } while (choix != 6);

    return 0;
}


//---------------------------------------les functions d'assistance-----------------------------

void ModifierLeNombre(){//-----------------------modification de nombre-----------------------
          char NouveauNombre[10];
          printf("Entrez La Nouvell Numero De Telephone : ");
          scanf("%10s",NouveauNombre);
          strcpy(Informations[NumberIndix].NumeroDeTelephone,NouveauNombre);
          printf("Le Nombre Modifier Avec succe : \n");
          return;
}

void ModifierAddressEmail(){//--------------------modification de email-----------------------
         char NouveauEmil[30];
         printf("Entrez La Nouvelle Email Address : ");
         scanf("%30s",NouveauEmil);
         strcpy(Informations[NumberIndix].mail.AddressEmail,NouveauEmil);
         printf("L'email Address Modifier Avec succe : \n");
         return;
}

int verifierLexistance(char VerifierLeNom[]){//-------------------verification de l'existance----------
    for(int i = 0 ; i < NumberContacts ; i++){
    if(strcasecmp(Informations[i].Nom,VerifierLeNom)==0){
        NumberIndix = i ;
        return  i;
      }
    }
    return -1;
}

void afficherTousNom(){//---------------------------------afficher tous les nomes ------------------

     printf("Voici Tous Les Noms : \n");
    for(int i = 0 ; i < NumberContacts ; i++){
        printf("Nom %d : %s |\n",i+1,Informations[i].Nom);
    }
}

int DisplayMenu(int choix){//---------------------return la valeur de choix --------------------

          printf("Contact Trouvé Avec Succès : \n");
          printf("\n");
          printf("-----------[Menu De La Modifiction]----------- \n");
          printf("1_modifier Le Numéro De Téléphone : \n");
          printf("2_Modifier L'address Email : \n");
          printf("3_ Quitter : \n");
          printf("\n");
          printf("Entrez Votre Choix : ");
          scanf("%d",&choix);
          return choix;
}

void AfficherLesinformationDeContact(){//--------afficher les information aprés if condition est validé--------
      printf("Les Nombres Des Contactes Sont %d :\n",NumberContacts);
      printf("\n");
       for(int i = 0 ; i < NumberContacts ; i++){
          printf("le contact Numéro %d : \n",i+1);
          printf("Nom De Contact : %s |\n",Informations[i].Nom);
          printf("Numero De Telephone : %s |\n",Informations[i].NumeroDeTelephone);
          printf("Email Address : %s |\n",Informations[i].mail.AddressEmail);
          printf("------------------------------\n");
        }
}

void AfficherSeulNom(){//--------------ce fonction afficher une seul contact------------------
        printf("Le Contact a été Trouvé Avec Succès Dans La Liste : \n");
        printf("Voici ces information : \n");
        printf("Nom De Contact : %s |\n",Informations[NumberIndix].Nom);
        printf("Numero De Telephone : %s |\n",Informations[NumberIndix].NumeroDeTelephone);
        printf("Email Address : %s |\n",Informations[NumberIndix].mail.AddressEmail);
        printf("----------------------\n");
}

void DeleteNoms(){//----------------------supprimer l'élement ----------------------------
    for(int i = NumberIndix + 1 ; i < NumberContacts ; i++){
      strcpy(Informations[i+1].Nom,Informations[i].Nom);
      strcpy(Informations[i+1].NumeroDeTelephone,Informations[i].NumeroDeTelephone);
     strcpy(Informations[i+1].mail.AddressEmail,Informations[i].mail.AddressEmail);
    }
    return;
}

void AjouteLesInformation(){//----------------------ajouter les information ---------------------
            printf("Entrez le nom du contact : ");
            scanf("%20s", Informations[NumberContacts].Nom);

            printf("Entrez le numéro de téléphone : ");
            scanf("%10s", Informations[NumberContacts].NumeroDeTelephone);

            printf("Entrez l'adresse email : ");
            scanf("%30s", Informations[NumberContacts].mail.AddressEmail);

            NumberContacts++;
            printf("Le contact a été ajouté avec succès.\n");
            return;
}

void TrouverPasLelement(){//------------------------appell ce funtion si l'élement est pas trouvé-------
        printf("\n");
        printf("le nom saisi n'existe pas dans les contacts : \n");
        printf("Essayer D'entrez Un Nom Qu'est Correct : \n");
        afficherTousNom();
        return;
}