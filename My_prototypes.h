typedef struct contacts contacts;
struct contacts
{
    char Nom[35];
    char Prenom[35];
    char Telephone[35];
};


//MES PROTOTYPES
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void operationfichier();
void insertioncontact(contacts personne);
void affichagecontact();
void Rechercher_un_contact(char Nom_a_rechercher[100]);
void suppressiondecontact(char Nom_a_supprimer[100]);
void ModificationFichier(char contact_a_supprimer[100]);
void espace(int nbredecaractere);
/*char saisieinfo();*/
