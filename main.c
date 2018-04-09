#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact //Declaration de la structure Contact, qui comporte les diff�rents informations d'un contact.
{
    char nom[30];
    char prenom[30];
    int num[12];
    char adresse[200];
    int cdp[5];
    char ville[100];
};

int compteur; //D�claration d'une variable globale compteur.

void Menu(struct Contact tcontact[50])  //Proc�dure permettant d'afficher le Menu et donne la possibilit� de selectionne une option du menu.
{

    int choix;

    do{         //Cette premiere boucle permet de fermer le programme si l'utilisateur rentre "5".
        do{     //La deuxieme boucle permet l'affichage et la navigation dans le menu tant que l'utilisateur ne rentre pas "5".
            printf("\n\n\tMenu : \tIl y a %d de contacts enregistres\n", compteur);
            printf("\n\t1. Afficher la liste des contacts");
            printf("\n\t2. Ajouter un contact");
            printf("\n\t3. Modifier le numeros de telephone");
            printf("\n\t4. Supprimer un contact");
            printf("\n\t5. Quitter l'application\n");
            printf("\n\tQuel est votre choix ?  ");
            scanf("%d", &choix);

        }while(choix<=0 || choix>5);

        switch(choix)
        {
            case 1: Afficher(tcontact);
            break;

            case 2: Ajouter(tcontact);
            break;

            case 3: Modifier(tcontact);
            break;

            case 4: Supprimer(tcontact);
            break;
        }

    }while(choix != 5);

}

void Ajouter(struct Contact tcontact[50])       //Cette proc�dure permet l'ajout des contacts. Elle ajoute une par une, d�s que l'utilsateur a rentr� un contact on retourne au menu.
{
    char choix2;

    Recup(tcontact);        //Appel de la fonction Recup, explication un peu plus tard.
    printf("\nNom : "); fflush(stdin);      //fflush(stdin) permet d'�viter un probleme li� a la touche entrer.
    scanf("%s", &tcontact[compteur].nom);

    printf("\nPrenom : "); fflush(stdin);
    scanf("%s", &tcontact[compteur].prenom);

    printf("\nTelephone : "); fflush(stdin);
    scanf("%s", &tcontact[compteur].num);

    printf("\nSouhaitez-vous entrer l'adresse de %s %s ? (O/N)", tcontact[compteur].nom, tcontact[compteur].prenom);
    scanf("%s", &choix2);

    if(choix2 == 'O' || choix2 == 'o')  //On a demand� � l'utilisateur si il souhaitait rentrer l'adresse d'un contact, si oui on lui propose de rentrer les valeurs, si non on entre automatiquement les valeur "NR" pour Non Renseign�.
    {
        printf("\nAdresse : "); fflush(stdin);
        scanf("%s", &tcontact[compteur].adresse);

        printf("\nCode postal : "); fflush(stdin);
        scanf("%s", &tcontact[compteur].cdp);

        printf("\nVille : "); fflush(stdin);
        scanf("%s", &tcontact[compteur].ville);
    }

    else
    {
        strcpy(tcontact[compteur].adresse, "NR");
        strcpy(tcontact[compteur].cdp, "NR");
        strcpy(tcontact[compteur].ville, "NR");
    }

    EnregistrerAjout(tcontact);  //Appel de la proc�dure Enregistrer.
    Recup(tcontact);        //Appel de la proc�dure Recup.

}

void EnregistrerModif(struct Contact tcontact[50])       //La proc�dure Enregistrer permet comme son nom l'indique l'enregistrement des contacts dans un fichier texte.
{
    FILE* fichier = NULL;
    fichier = fopen("Contact.txt", "w+");       //On cr�e le fichier contact avec le mode d'ouverture "w+", qui permet la lecture et l'�criture, mais vide le fichier pour y r�ecrire juste apr�s. Cela nous permet de r�actuliser la liste des contacts.

    int k = 0;
    printf("%d", compteur);
    if(fichier != NULL)
    {
        if(compteur == 0) {
            for(k; k<=compteur; k++)      //Boucle permettant l'�criture de la fiche d'un contacts.
            {
                fprintf(fichier, "\nNom : %s\n", tcontact[k].nom);
                fprintf(fichier, "Prenom : %s\n", tcontact[k].prenom);
                fprintf(fichier, "Telephone : %s\n", tcontact[k].num);
                fprintf(fichier, "Adresse : %s\n", tcontact[k].adresse);
                fprintf(fichier, "Code Postal : %s\n", tcontact[k].cdp);
                fprintf(fichier, "Ville : %s", tcontact[k].ville);
            }
        }
        else if(compteur >0) {
           for(k; k<compteur; k++)      //Boucle permettant l'�criture de la fiche d'un contacts.
            {
                fprintf(fichier, "\nNom : %s\n", tcontact[k].nom);
                fprintf(fichier, "Prenom : %s\n", tcontact[k].prenom);
                fprintf(fichier, "Telephone : %s\n", tcontact[k].num);
                fprintf(fichier, "Adresse : %s\n", tcontact[k].adresse);
                fprintf(fichier, "Code Postal : %s\n", tcontact[k].cdp);
                fprintf(fichier, "Ville : %s", tcontact[k].ville);
            }
        }
    }
    fclose(fichier);        //On ferme le fichier.
}

void EnregistrerAjout(struct Contact tcontact[50])       //La proc�dure Enregistrer permet comme son nom l'indique l'enregistrement des contacts dans un fichier texte.
{
    FILE* fichier = NULL;
    fichier = fopen("Contact.txt", "w+");       //On cr�e le fichier contact avec le mode d'ouverture "w+", qui permet la lecture et l'�criture, mais vide le fichier pour y r�ecrire juste apr�s. Cela nous permet de r�actuliser la liste des contacts.

    int k = 0;
    if(fichier != NULL)
    {
        if(compteur == 0) {
            for(k; k<=compteur; k++)      //Boucle permettant l'�criture de la fiche d'un contacts.
            {
                fprintf(fichier, "\nNom : %s\n", tcontact[k].nom);
                fprintf(fichier, "Prenom : %s\n", tcontact[k].prenom);
                fprintf(fichier, "Telephone : %s\n", tcontact[k].num);
                fprintf(fichier, "Adresse : %s\n", tcontact[k].adresse);
                fprintf(fichier, "Code Postal : %s\n", tcontact[k].cdp);
                fprintf(fichier, "Ville : %s", tcontact[k].ville);
            }
        }
        else if(compteur >0) {
                compteur++;
           for(k; k<compteur; k++)      //Boucle permettant l'�criture de la fiche d'un contacts.
            {
                fprintf(fichier, "\nNom : %s\n", tcontact[k].nom);
                fprintf(fichier, "Prenom : %s\n", tcontact[k].prenom);
                fprintf(fichier, "Telephone : %s\n", tcontact[k].num);
                fprintf(fichier, "Adresse : %s\n", tcontact[k].adresse);
                fprintf(fichier, "Code Postal : %s\n", tcontact[k].cdp);
                fprintf(fichier, "Ville : %s", tcontact[k].ville);
            }
        }
    }

    fclose(fichier);        //On ferme le fichier.
}

void Afficher(struct Contact tcontact[50])      //La proc�dure Afficher, permet d'afficher la liste des contacts depuis l'invit� de commande.
{
    int j;
    for(j=0; j<compteur; j++)     //Boucle qui permet l'affichage de la totalit� des contacts tant que "j", n'est pas egale � compteur
    {
        printf("\n\nNom : %s", tcontact[j].nom);
        printf("\nPrenom : %s", tcontact[j].prenom);
        printf("\nTelephone : %s", tcontact[j].num);
        printf("\nAdresse : %s", tcontact[j].adresse);
        printf("\nCode Postal : %s", tcontact[j].cdp);
        printf("\nVille : %s", tcontact[j].ville);
    }
}

void Modifier(struct Contact tcontact[50])  //Cette proc�dure permet la modification du num�ros de t�l�phone d'un contact, apr�s avoir entrer son Nom
{
    char foundname[30];
    int trouve, k;

    trouve = NULL;
    k = 0;

    Recup(tcontact);    //Appel de la proc�dure Recup.

    printf("Quelle contact souhaitez-vous modifier ?");
    printf("\nEntrer un nom : ");
    scanf("%s", &foundname);        //On affecte un nom a foundname.

    for(k; k<=compteur; k++){     //Boucle qui parcourt la liste des contacts.
        if(strcmp(tcontact[k].nom, foundname) ==0)      //La fonction strcmp permet de compar� deux cha�nes de caract�res, lorsque les cha�nes de caract�res sont �gaux, la fonction renvoie 0.
        {
            printf("Le contact a ete trouver !");
            printf("Entrer le numeros de  telephone : ");
            scanf("%s", tcontact[k].num);
            trouve =1;      //trouve, va nous servir a appeler la proc�dure Enregistrer, pour r�-actuliser la liste des contacts.
            break;
        }
    }

    if(trouve)
    {
        EnregistrerModif(tcontact);
    }

    else if(!trouve)    //Dans le cas ou strcmp != 0, donc trouve est !=1, alors on affiche un message a l'utilisateur, comme quoi le contact n'a pas etait enregistrer.
    {
        printf("\nLe contact n'a pas etait enregistrer.\n");
    }
}

void Supprimer(struct Contact tcontact[50]) //La proc�dure Supprimer permet la suppression d'un contact, apr�s avoir renseign� son nom.
{
    char foundname[30];     //On r�-utilise le meme systeme que pour la procedure Modifier, pour rechercher le nom entrer dans la liste des contacts.
    int trouve, k;

    trouve = 0;
    k = 0;

    printf("Quelle contact souhaitez-vous supprimer ?");
    printf("\nEntrer un nom : ");
    scanf("%s", &foundname);

    do{     //Ici, pour supprimer le contact, on �crase la valeur concern� par le contact qui se trouve juste apr�s lui, gr�ce � la fonction strcpy.
        if(strcmp(tcontact[k].nom, foundname) ==0)
        {
            strcpy(tcontact[k].nom, tcontact[k+1].nom);
            strcpy(tcontact[k].prenom, tcontact[k+1].prenom);
            strcpy(tcontact[k].num, tcontact[k+1].num);
            strcpy(tcontact[k].adresse, tcontact[k+1].adresse);
            strcpy(tcontact[k].cdp, tcontact[k+1].cdp);
            strcpy(tcontact[k].ville, tcontact[k+1].ville);
            trouve =1;
        }

        k++;

    }while(k<compteur);

    tcontact[compteur].nom == " ";
    tcontact[compteur].prenom == " ";
    tcontact[compteur].num == " ";
    tcontact[compteur].adresse == " ";
    tcontact[compteur].cdp == " ";
    tcontact[compteur].ville == " ";
    compteur--;
    EnregistrerModif(tcontact);

    if(!trouve)
    {
        printf("\nLe contact n'a pas etait enregistrer.\n");
    }
}

void Recup(struct Contact tcontact[50])     //La proc�dure Recup, permet de recuperer les contacts qui ont etait enregistr� dans le fichier texte, gr�ce a la fonction fseek.
{
    FILE* fichier = NULL;
    fichier = fopen("Contact.txt", "r");        //On ouvre le fichier, gr�ce au mode ouverture "r". Elle permet d'uniquement de lire le fichier.

    if(fichier != NULL)
    {
        compteur=0;
        fseek(fichier, 0, SEEK_SET);        //On positionne le curseur � l'origine, gr�che � SEEK_SET, on ne bouge pas car on a indiqu� un pas de 0.

        while(fgetc(fichier) == '\n' && fgetc(fichier) != EOF)
        {
            fseek(fichier, 5, SEEK_CUR);    //Ici, on bouge de 5 pas de l'origine, SEEK_CUR permet d'indiquer la position du curseur.
            fscanf(fichier, "%s", &tcontact[compteur].nom);

            fseek(fichier, 10, SEEK_CUR);
            fscanf(fichier, "%s", &tcontact[compteur].prenom);

            fseek(fichier, 13, SEEK_CUR);
            fscanf(fichier, "%s", &tcontact[compteur].num);

            fseek(fichier, 11, SEEK_CUR);
            fscanf(fichier, "%s", &tcontact[compteur].adresse);

            fseek(fichier, 15, SEEK_CUR);
            fscanf(fichier, "%s", &tcontact[compteur].cdp);

            fseek(fichier, 9, SEEK_CUR);
            fscanf(fichier, "%s", &tcontact[compteur].ville);
            compteur++;     //On increment compteur pour compter le nombre de contact.
        }
    }

        fclose(fichier);        //On ferme le fichier.
}

int main ()
{
    struct Contact tcontact[50];

        Recup(tcontact);    //Appel de la proc�dure Recup, qui permet de r�-enregistrer les contacts depuis le fichier texte, et compter le nombre de contacts.
        Menu(tcontact);

    return(0);
}
