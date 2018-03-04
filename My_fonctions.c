#include <stdio.h>
#include <stdlib.h>
#include "My_prototypes.h"
#define Taille_MAX 10000
#include <string.h>
#include <ctype.h>

int longueur=0;

/*FONCTION SAISIE*/
/*char saisieinfo()
{
    char caractereactuel=0;
    caractereactuel=getchar();//Lit le premier caractere
    caractereactuel=toupper(caractereactuel);//On met le caracter entree en majuscule
    while(getchar()!='\n');
    return caractereactuel;
}*/

/* INSERTION DU CONTACT DANS LE REPERTOIRE*/
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void insertioncontact(contacts personne)
{
    char espanom[35]=" ",esprenom[35]=" ";
   /* espanom=" ";
    esprenom=" ";*/
    int taillenom,taillepren,N,M,i;
    FILE* Pointeur_d_insertion=NULL;
    //ouverture du fichier
    Pointeur_d_insertion=fopen("CONTACT.txt","a");
    if(Pointeur_d_insertion!=NULL)
    {

        fputs(personne.Nom,Pointeur_d_insertion);
        taillenom=strlen(personne.Nom);
        N=35-taillenom;
            for(i=0;i<=N;i++)
            {
               strcat(espanom," ") ;
            }
        fputs(espanom,Pointeur_d_insertion);
        fputs(personne.Prenom,Pointeur_d_insertion);
        taillepren=strlen(personne.Prenom);
        M=35-taillepren;
            for(i=0;i<=M;i++)
            {
               strcat(esprenom," ") ;
            }
        fputs(esprenom,Pointeur_d_insertion);
        fputs(personne.Telephone,Pointeur_d_insertion);
        //fputs("  ",Pointeur_d_insertion);
        fputc('\n',Pointeur_d_insertion);
        fclose(Pointeur_d_insertion);
    }

}

/* AFFICHAGE DES CONTACTS DU REPERTOIRE*/
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void affichagecontact()
{
    FILE *pointinserer=NULL;
    pointinserer=fopen("CONTACT.txt","r");
   // int /*caractereactuel,*/compteur=0;
    char chaine[100]="";
    if(pointinserer!=NULL)
    {
        while(fgets(chaine,Taille_MAX,pointinserer)!=NULL)
        {
            printf("%s\n\n",chaine);
        }
        fclose(pointinserer);
    }
}
/* RECHERCHE DANS LE REPERTOIRE*/
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void Rechercher_un_contact(char Nom_a_rechercher[100])
{
    FILE* pointeurderecherche=NULL;
    pointeurderecherche=fopen("CONTACT.txt","r");
    char chaine[100]="";
    if(pointeurderecherche!=NULL)
    {
        rewind(pointeurderecherche);
        int compteur=0,i=0;
        while(fgets(chaine,Taille_MAX,pointeurderecherche)!=NULL)
        {
            if(strstr(chaine,Nom_a_rechercher)!= NULL)
            {
                printf("%s\n",chaine);
                /*longueur[i]*/
                compteur++;
            }
        }
        if(compteur==0)
        {
            printf("\n\nAUCUN CONTACT TROUVE\n\n");
        }
        fclose(pointeurderecherche);
    }
}

/* SUPPRESSION D'UN ELEMENT DU REPERTOIRE*/
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void suppressiondecontact(char Nom_a_supprimer[100])
{

    //char contactasupprimer[200]="";
     //Rechercher_un_contact(Nom_a_supprimer);
    char chaine[100]="";
    int compteur,nbre;
    compteur=0;
    nbre=0;
     FILE* pointeurdesuppr=NULL;
     FILE* pointeur=NULL;
    pointeurdesuppr=fopen("CONTACT.txt","r");
    if(pointeurdesuppr!=NULL)
    {
        pointeur=fopen("Fichier auxiliaire.txt","a");
        if(pointeur!=NULL)
        {
            while(fgets(chaine,10000,pointeurdesuppr)!=NULL)
            {
                nbre++;
                if(strstr(chaine,Nom_a_supprimer)==NULL)
                {
                  fputs(chaine,pointeur);
                  compteur++;
                  //fputc('\n',pointeur);
                }
            }

                fclose(pointeur);
        }
     fclose(pointeurdesuppr);
    }
    if(nbre==compteur)
    {
        printf("Ce contact ne se trouve pas dans ton repertoire!!!@@@\n\n");
    }
    else
    {


        printf(" \n\nLe(s) contact(s) \n");
                  Rechercher_un_contact(Nom_a_supprimer);
        printf("\n\t\t a (ont) ete(s) supprime(s) avec succes!");
         remove("CONTACT.txt");
       rename("Fichier auxiliaire.txt","CONTACT.txt");

    }

}

/* MODIFIER UN ELEMENT DU REPERTOIRE*/
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void ModificationFichier(char contact_a_supprimer[100])
{
char chaine[100]="";
     FILE* pointeurdesuppr=NULL;
     FILE* pointeur=NULL;
     /*int compteurdeligne=0;
     int compteurlignecontact=0;*/
    pointeurdesuppr=fopen("CONTACT.txt","r");
    if(pointeurdesuppr!=NULL)
    {
        pointeur=fopen("Fichier auxiliaire.txt","a");
        if(pointeur!=NULL)
        {
            while(fgets(chaine,10000,pointeurdesuppr)!=NULL)
            {
                if(strstr(chaine,contact_a_supprimer)==NULL)
                {
                  fputs(chaine,pointeur);
                }

            }


                fclose(pointeur);
        }
     fclose(pointeurdesuppr);
    }
    remove("CONTACT.txt");
    rename("Fichier auxiliaire.txt","CONTACT.txt");

    int taillenom,taillepren,N,M,i;
    char espanom[35]=" ",esprenom[35]=" ";

    FILE* fichiermodifier=NULL;
    fichiermodifier=fopen("CONTACT.txt","a");
    if(fichiermodifier!=NULL)
    {
             contacts contact_a_modifier;
              printf("Entrer le nouveau nom: ");
              scanf("%s",&contact_a_modifier.Nom);
              printf("\nEntrer le nouveau prenom: ");
              scanf("%s",&contact_a_modifier.Prenom);
              printf("\nEntrer le nouveau numero de telephone: ");
              scanf("%s",&contact_a_modifier.Telephone);

            fputs(contact_a_modifier.Nom,fichiermodifier);
            taillenom=strlen(contact_a_modifier.Nom);
            N=35-taillenom;
            for(i=0;i<=N;i++)
            {
               strcat(espanom," ") ;
            }
        fputs(espanom,fichiermodifier);
        fputs(contact_a_modifier.Prenom,fichiermodifier);
        taillepren=strlen(contact_a_modifier.Prenom);
        M=35-taillepren;
            for(i=0;i<=M;i++)
            {
               strcat(esprenom," ") ;
            }
        fputs(esprenom,fichiermodifier);
        fputs(contact_a_modifier.Telephone,fichiermodifier);


        fclose(fichiermodifier);
    }

}
void espace(int nbredecaractere)
{
   int i;
   for (i=0;i<=nbredecaractere;i++)
   {
    printf(" ");
   }

}
