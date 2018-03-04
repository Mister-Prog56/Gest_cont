#include <stdio.h>
#include <stdlib.h>
#include "My_prototypes.h"
#define Taille_MAX 10000
#include <string.h>
#include <ctype.h>

int main()
{
    int Reveniraumenuprincipal;
    do
    {

    operationfichier();
    printf("   Nom: DIAKITE\t\tPrenom:SOUMAILA\nProjet:GESCONT\n\n");
   printf("\n\n@@@PROGRAMME DE GESTION DE CONTACTS@@@\n\n\n");
    printf("\tMENU\n\n\n");
    printf("1-INSERER UN CONTACT\n2-AFFICHER LA LISTE DE TOUS LES CONTACTS\n3-RECHERCHER UN CONTACT\n4-MODIFIER UN CONTACT\n5-SUPPRIMER UN CONTACT\n\n");
    system("pause");
    int choix;

    printf("\n\n\nFaites votre choix:");
    scanf("%d",&choix);
    printf("\n\n\n");
    //FILE* pointerdefichier=NULL;
    switch (choix)
    {
    case 1:
        {
            contacts personne;
            int reponse=0;
            do
            {
            printf("Entrer Nom:");
            scanf("%s",&personne.Nom);
            printf("\nEntrer prenom:");
            scanf("%s",&personne.Prenom);
            printf("\nEntrer Telephone:");
            scanf("%s",&personne.Telephone);
            insertioncontact(personne);
            system("cls");
            printf("\nVoulez-vous enregistrer un autre contact?\nTaper \t 1-oui \t 0-non\n");
            scanf("%d",&reponse);
            }while(reponse==1);
            system("Pause");
            system("cls");
            printf("\nVoulez-vous revenir au Menu Principal?\n\n");
            printf("0-pour fermer      1-menu principal\n");
            scanf("%d",&Reveniraumenuprincipal);
            if(Reveniraumenuprincipal==1)
            {
                system("cls");
            }
        }
        break;
    case 2:
        {
           system("cls") ;
           system("pause");
           printf("\n\n");
           printf("\n\nAFFICHAGE DE CONTACTS\n\n\n");
           printf("NOM:");
           espace(32);
           printf("PRENOM:");
           espace(29);
           printf("TELEPHONE:");
           printf("\n\n");
           affichagecontact();
           system("Pause");
            system("cls");
            printf("\nVoulez-vous revenir au Menu Principal?\n\n");
            printf("0-pour fermer      1-menu principal\n");
            scanf("%d",&Reveniraumenuprincipal);
            if(Reveniraumenuprincipal==1)
            {
                system("cls");
            }

        }
        break;
    case 3:
        {
            system("cls");
            char caractererecher[100]="";
            printf("Entrer le nom ou le prenom ou le contact a rechercher:");
            scanf("%s",&caractererecher);
            Rechercher_un_contact(caractererecher);
                                    system("Pause");
                                      system("cls");
             printf("\nVoulez-vous revenir au Menu Principal?\n\n");
            printf("0-pour fermer      1-menu principal\n");
            scanf("%d",&Reveniraumenuprincipal);
            if(Reveniraumenuprincipal==1)
            {
                system("cls");
            }
        }
        break;
    case 4:
        {
            char nom_a_modifier[100]="";
                printf("\n\nEntrer le nom ou le prenom ou le contact a modifier:");
                scanf("%s",&nom_a_modifier);
              printf("\n\nLes informations relatives au contact a modifier sont :\n");
              Rechercher_un_contact(nom_a_modifier);
              printf("\n\n");
              ModificationFichier(nom_a_modifier);
              system("cls");
              printf("\nVotre contact a ete modifie avec succes!!!!!\n");
              printf("\nVoulez-vous revenir au Menu Principal?\n\n");
            printf("0-pour fermer      1-menu principal\n");
            scanf("%d",&Reveniraumenuprincipal);
            if(Reveniraumenuprincipal==1)
            {
                system("cls");
            }


        }
        break;
    case 5:
        {
            system("cls");
            char contactasupprimer[100]="";
            printf("\n\nEntrer le contact a supprimer: ");
            scanf("%s",&contactasupprimer);
            int reponse=0;
            printf("Confirmez-vous cette operation?\n\tAppuyer\t1-oui\t0-nom\t: ");
            scanf("%d",&reponse);
            switch(reponse)
            {
            case 0:
                {
                    printf("Votre contact reste enregistrer!!!!!@@@@@@\n");
                                       system("Pause");
                                      system("cls");
                     printf("\nVoulez-vous revenir au Menu Principal?\n\n");
                    printf("0-pour fermer      1-menu principal\n");
                    scanf("%d",&Reveniraumenuprincipal);
                    if(Reveniraumenuprincipal==1)
                        {
                            system("cls");
                        }
                }
                break;
            case 1:
                {

                  suppressiondecontact(contactasupprimer);
                  //system("cls");

                                      system("Pause");
                                      system("cls");
                   printf("\nVoulez-vous revenir au Menu Principal?\n\n");
                    printf("0-pour fermer      1-menu principal\n");
                    scanf("%d",&Reveniraumenuprincipal);
                        if(Reveniraumenuprincipal==1)
                            {
                                system("cls");
                            }
                }
                break;
            default:
                {
                    system("cls");
                    printf("\nAUCUNE PRECISION!!!!!!\n");
                    system("Pause");
                                      system("cls");
                             printf("\nVoulez-vous revenir au Menu Principal?\n\n");
                    printf("0-pour fermer      1-menu principal\n");
                    scanf("%d",&Reveniraumenuprincipal);
                    if(Reveniraumenuprincipal==1)
                        {
                            system("cls");
                        }
                }
            }

        }
        break;
        default:
        {
            system("cls");
             printf("\nVoulez-vous revenir au Menu Principal?\n\n");
            printf("0-pour fermer      1-menu principal\n");
            scanf("%d",&Reveniraumenuprincipal);
            if(Reveniraumenuprincipal==1)
            {
                system("cls");
            }
        }
    }
}while(Reveniraumenuprincipal==1);



    printf("\n\n\n\n");
    return 0;
}
void operationfichier()
{
    FILE* fichier=NULL;
    fichier=fopen("CONTACT.txt","a");
    if(fichier!=NULL)
    {
        fclose(fichier);
    }
    FILE* pointeur=NULL;
    pointeur=fopen("Fichier auxiliaire.txt","a");
    if(pointeur!=NULL)
        {
            fclose(pointeur);
        }

   /* FILE* pointeurdemofication=NULL;
    pointeurdemofication=fopen("Fichier de modification.txt","w");
    if(pointeurdemofication!=NULL)
    {
        fclose(pointeurdemofication);
    }*/
}
