#include<stdio.h>
#include<stdlib.h>

typedef struct etudiant{
    int pos;
    char nom[20];
    float moyenne;
    struct etudiant *suiv;
    struct etudiant *pre;
}etudiant;

etudiant *cree_etudiant(int pos, char *nom, float moyenne)
{
    etudiant *nv= (etudiant *)malloc(sizeof(etudiant));
    nv->pos = pos;
    strcpy(nv->nom, nom);
    nv->moyenne = moyenne;
    nv->suiv = NULL;
    nv->pre = NULL;
    return nv;
}

int longueur(etudiant *debut)
{
    int i = 0;
    etudiant *temp = debut;
    while(temp != NULL)
    {
        i++;
        temp = temp->suiv;
    }
    return i;
}

etudiant *ajouter_position(etudiant *debut, etudiant* nv, int pos)
{
    if(pos == 0)
    {
        nv->suiv = debut;
        if(debut != NULL)
        {
            debut->pre = nv;
        }
        debut = nv;
    }
    else
    {
        etudiant *temp = debut;
        for(int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->suiv;
        }
        if(temp != NULL)
        {
            nv->suiv = temp->suiv;
            nv->pre = temp;
            if(temp->suiv != NULL)
            {
                temp->suiv->pre = nv;
            }
            temp->suiv = nv;
        }
    }
    return debut;
}

etudiant *supprimer_position(etudiant *debut, int pos)
{
    if(debut == NULL || pos < 0)
    {
        return debut;
    }
    etudiant *temp = debut;
    if(pos == 0)
    {
        debut = debut->suiv;
        if(debut != NULL)
        {
            debut->pre = NULL;
        }
        free(temp);
        return debut;
    }
    for(int i = 0; i < pos && temp != NULL; i++)
    {
        temp = temp->suiv;
    }
    if(temp != NULL)
    {
        if(temp->pre != NULL)
        {
            temp->pre->suiv = temp->suiv;
        }
        if(temp->suiv != NULL)
        {
            temp->suiv->pre = temp->pre;
        }
        free(temp);
    }
    return debut;
}


void afficher_liste(etudiant *debut)
{
    etudiant *temp = debut;
    while(temp != NULL)
    {
        printf("pos: %d, Nom: %s, Moyenne: %.2f\n", temp->pos, temp->nom, temp->moyenne);
        temp = temp->suiv;
    }
}


etudiant *derniere_cellule(etudiant *debut)
{
    etudiant *temp = debut;
    while(temp != NULL && temp->suiv != NULL)
    {
        temp = temp->suiv;
    }
    return temp;
}


void afficher_liste_inverse(etudiant *dernier)
{
    etudiant *temp = dernier;
    while(temp != NULL)
    {
        printf("pos: %d, Nom: %s, Moyenne: %.2f\n", temp->pos, temp->nom, temp->moyenne);
        temp = temp->pre;
    }
}

int chercher_etudiant(etudiant *debut, int pos)
{
    etudiant *temp = debut;
    while(temp != NULL)
    {
        if(temp->pos == pos)
        {
            return 1;
        }
        temp = temp->suiv;
    }
    return 0;
}

etudiant *tri(etudiant *debut){

}


etudiant *modofier_moyenne(etudiant *debut, int pos, float nouvelle_moyenne)
{
    etudiant *temp = debut;
    while(temp != NULL)
    {
        if(temp->pos == pos)
        {
            temp->moyenne = nouvelle_moyenne;
            return debut;
        }
        temp = temp->suiv;
    }
    return debut;
}

int main()
{
    etudiant *debut = NULL;
    etudiant *nv1 = cree_etudiant(1, "Alice", 15.5);
    etudiant *nv2 = cree_etudiant(2, "Bob", 12.0);
    etudiant *nv3 = cree_etudiant(3, "Charlie", 18.0);
    
    debut = ajouter_position(debut, nv1, 0);
    debut = ajouter_position(debut, nv2, 1);
    debut = ajouter_position(debut, nv3, 2);
    
    printf("Liste des étudiants:\n");
    afficher_liste(debut);
    
    printf("\nListe des étudiants inversée:\n");
    etudiant *dernier = derniere_cellule(debut);
    afficher_liste_inverse(dernier);
    
    int pos_a_chercher = 2;
    if(chercher_etudiant(debut, pos_a_chercher))
    {
        printf("\nL'étudiant avec la position %d existe.\n", pos_a_chercher);
    }
    else
    {
        printf("\nL'étudiant avec la position %d n'existe pas.\n", pos_a_chercher);
    }
    
    debut = modofier_moyenne(debut, 2, 14.5);
    
    printf("\nListe des étudiants après modification:\n");
    afficher_liste(debut);
    
    return 0;
}


