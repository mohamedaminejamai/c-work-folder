#include<stdio.h>
#include<stdlib.h>

typedef struct noeud
{
    int val;
    struct noeud *suiv;
    struct noeud *pre;
}noeud;

noeud *cree(int val)
{
    noeud *nv= (noeud *)malloc(sizeof(noeud));
    nv->val = val;
    nv->suiv = NULL;
    nv->pre = NULL;
    return nv;
}

void afficher(noeud *debut)
{
    noeud *temp = debut;
    while(temp != NULL)
    {
        printf("valeur= %d |adresse= %p |suivant= %p |precedant= %p \n", temp->val, temp, temp->suiv, temp->pre);
        temp = temp->suiv;
    }
}

noeud *ajouterd(noeud *debut, int val)
{
    noeud *nv = cree(val);
    nv->suiv = debut;
    if(debut != NULL)
    {
        debut->pre = nv;
    }
    debut = nv;
    return debut;
}

noeud *ajouterf(noeud *debut, int val)
{
    noeud *nv = cree(val);
    noeud *temp = debut;
    if(temp == NULL)
    {
        return nv;
    }
    else
    {
        while(temp->suiv != NULL)
                {
           temp = temp->suiv;
               }
    }
    
    temp->suiv = nv;
    nv->pre = temp;
    return debut;
}

int taille(noeud *debut)
{
    int i = 0;
    noeud *temp = debut;
    while(temp != NULL)
    {
        i++;
        temp = temp->suiv;
    }
    return i;
}

noeud *insertion(noeud *debut, int val, int pos)
{
    noeud *nv = cree(val);
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
        noeud *temp = debut;
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

noeud *rechercher(noeud *debut, int val)
{
    noeud *temp = debut;
    while(temp != NULL)
    {
        if(temp->val == val)
        {
            return temp;
        }
        temp = temp->suiv;
    }
    return NULL;
}


noeud *suppressiond(noeud *debut)
{
    if(debut == NULL)
    {
        return NULL;
    }
    noeud *temp = debut;
    debut = debut->suiv;
    if(debut != NULL)
    {
        debut->pre = NULL;
    }
    free(temp);
    return debut;
}

noeud *suppressionf(noeud *debut)
{
    if(debut == NULL)
    {
        return NULL;
    }
    noeud *temp = debut;
    while(temp->suiv != NULL)
    {
        temp = temp->suiv;
    }
    if(temp->pre != NULL)
    {
        temp->pre->suiv = NULL;
    }
    else
    {
        debut = NULL;
    }
    free(temp);
    return debut;
}


noeud *suppressionp(noeud *debut, int pos)
{
    if(debut == NULL || pos < 0)
    {
        return debut;
    }
    noeud *temp = debut;
    if(pos == 0)
    {
        return suppressiond(debut);
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


noeud *modifierd(noeud *debut, int val)
{
    if(debut == NULL)
    {
        return NULL;
    }
    noeud *temp = debut;
    while(temp != NULL)
    {
        temp->val = val;
        temp = temp->suiv;
    }
    return debut;
}


noeud *modifierf(noeud *debut, int val)
{
    if(debut == NULL)
    {
        return NULL;
    }
    noeud *temp = debut;
    while(temp->suiv != NULL)
    {
        temp = temp->suiv;
    }
    temp->val = val;
    return debut;
}

void main()
{
    noeud *debut = NULL;
    noeud *p=cree(10);
    noeud *d=cree(20);
    noeud *f=cree(40);
    noeud *t=cree(30);
    debut = p;
    p->suiv = d;
    d->pre = p;
    d->suiv = t;
    t->pre = d;
    t->suiv = f;
    f->pre = t;

    debut = ajouterd(debut, 50);

    printf("taille = %d\n", taille(debut));

    afficher(debut);
}