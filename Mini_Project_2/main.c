#include <stdio.h>
#include <string.h>
#define MAX 100
int NumberContacts = 0;
int NumberIndix = 0;

typedef struct{
    char AddressEmail[30];
}Email;

typedef struct{
    Email mail;
     char Nom[20];
     char NumeroDeTelephone[10];
}contact;

contact Informations[MAX];

int verifierLexistance();
void ModifierLeNombre();
void ModifierAddressEmail();
void afficherTousNom();

void AjouteUneContact() {
    char VerifierLeNom[20];
    int call;

    do {
        if (NumberContacts == 0) {
            printf("Entrez le nom du contact : ");
            scanf("%20s", Informations[NumberContacts].Nom);

            printf("Entrez le numéro de téléphone : ");
            scanf("%10s", Informations[NumberContacts].NumeroDeTelephone);

            printf("Entrez l'adresse email : ");
            scanf("%30s", Informations[NumberContacts].mail.AddressEmail);

            NumberContacts++;
            printf("Le contact a été ajouté avec succès.\n");
            return;
        } else {
            printf("Entrez le nom du contact pour vérifier son existence : ");
            scanf("%20s", VerifierLeNom);
            call = verifierLexistance(VerifierLeNom);

            if (call == -1) {
                printf("Ce nom de contact existe déjà.\n");
                printf("Essayez d'entrer un nouveau nom : \n");
                afficherTousNom();
            } else {
                // Contact doesn't exist, add it
                printf("Entrez le nom du contact : ");
                scanf("%20s", Informations[NumberContacts].Nom);

                printf("Entrez le numéro de téléphone : ");
                scanf("%10s", Informations[NumberContacts].NumeroDeTelephone);

                printf("Entrez l'adresse email : ");
                scanf("%30s", Informations[NumberContacts].mail.AddressEmail);

                NumberContacts++;
                printf("Le contact a été ajouté avec succès.\n");
            }
        }
    } while (call == -1);
}

 void ModifierUnContact(){ 

  if(NumberContacts != 0){
      char verifierNom[20];
      int choix;
      int call;
     do{
       printf("Entrez le Nom de contact pour modifier ces information : ");
       scanf("%[^\n]",verifierNom);
       call = verifierLexistance(verifierNom);
       if(call)
         {
          printf("Le Contact Trouve avec Succe : \n");
          printf("\n");
          printf("-----------[Menu De La Modifiction]----------- \n");
          printf("1_Modifier Le Numero De Telephon : \n");
          printf("2_Modifier L'address Email : \n");
          printf("3_ Quitter : \n");
          printf("\n");
          printf("Entrez Votre Choix : ");
          scanf("%d",&choix);
           switch(choix){
             case 1 :
                  ModifierLeNombre();
                 break;
             case 2:
                  ModifierAddressEmail();
                 break;
             case 3:
                 printf("reteurn a la menu peincipal : \n");
             default:
               printf("Invalid Valeur , Essayer Encore : \n");
            
           }
          }else{
            printf("Le Nom Entree Ne Pas Exister Dans Les Contacts : \n");
            printf("Essayer D'entrez Un Nom Qu'est Correct : \n");
            printf("Voici tous les Noms : \n");
            afficherTousNom();
          }
     }while(choix != 3 || call != 1); 
 }else{
         printf("Le Contact Est Vide Essayer D'ajouter Quelque Contact : \n");
    }
 }
 void  SupprimerContact(){
      char VerifierLeNom[20];
      int call ;
     do{
         printf("Entrez Le Nom De Contact Pour La Supprime : \n");
         scanf("%[^\n]",VerifierLeNom);

            call = verifierLexistance(VerifierLeNom);
            if(call){
               for(int i = NumberIndix ; i < NumberContacts ; i++ ){
                   strcpy(Informations[i+1].Nom,Informations[i].Nom);
                   strcpy(Informations[i+1].Nom,Informations[i].NumeroDeTelephone);
                   strcpy(Informations[i+1].Nom,Informations[i].mail.AddressEmail);
               }
             printf("Le Contact Supprime Avec Succe : \n");
             NumberContacts--;
            }else{
                printf("Le Nom De Contact Pas Trouve : \n");
                printf("Essayer,Par Une Correct Nom : \n");
                printf("Voici tous les Noms : \n");
                afficherTousNom();
            }
     }while (call != 1);
     
   

 }

void AfficherTousLesContact(){
  printf("les nombres des contactes sont %d :\n",NumberContacts);
   for(int i = 0 ; i < NumberContacts ; i++){
     printf("le contact %d : \n",i+1);
     printf("Nom De Contact : %s |\n",Informations[i].Nom);
     printf("Numero De Telephone : %s |\n",Informations[i].NumeroDeTelephone);
     printf("Email Address : %s |\n",Informations[i].mail.AddressEmail);
     printf("------------------------------\n");
   }
 }

void RechercheContacte(){
    char VerifierLeNom[20];
    int call;
    do{  
      printf("Entrez le contact que vous voulez cherchez : ");
      scanf("%[^\n]",VerifierLeNom);
      call = verifierLexistance(VerifierLeNom);
      if(call){
        printf("le contact trouve dans la list avec succe : \n");
        printf("Voici ces information : \n");
        printf("Nom De Contact : %s |\n",Informations[NumberIndix].Nom);
        printf("Numero De Telephone : %s |\n",Informations[NumberIndix].NumeroDeTelephone);
        printf("Email Address : %s |\n",Informations[NumberIndix].mail.AddressEmail);
        printf("----------------------\n");
      }else{
        printf("Le Nom Ne Pas Exister Dans La Liste Des Contacte : \n");
        printf("essayez d'entrer une contact qu'est exist : \n");
        printf("Voici tous les Noms : \n");
        afficherTousNom();
      }
    }while(call != 1);

}

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

void ModifierLeNombre(){
          char NouveauNombre[10];
          printf("Entrez La Nouvell Numero De Telephone : ");
          scanf("%[^\n]",NouveauNombre);
          strcpy(NouveauNombre,Informations[NumberIndix].NumeroDeTelephone);
          printf("Le Nombre Modifier Avec succe : \n");
}

void ModifierAddressEmail(){
         char NouveauEmil[30];
         printf("Entrez La Nouvelle Email Address : ");
         scanf("%[^\n]",NouveauEmil);
         strcpy(NouveauEmil,Informations[NumberIndix].mail.AddressEmail);
         printf("L'email Address Modifier Avec succe : \n");
}

int verifierLexistance(char VerifierLeNom[]){
    for(int i = 0 ; i < NumberContacts ; i++){
    if(strcasecmp(VerifierLeNom,Informations[i].Nom)==0){
        //NumberIndix = i ;
        return  i;
      }
    }
    return -1;
}

void afficherTousNom(){
    for(int i = 0 ; i < NumberContacts ; i++){
        printf("Nom %d = %s |\n",i+1,Informations[i].Nom);
    }
}