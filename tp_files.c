 #include<stdio.h>
#include<stdlib.h>

typedef struct noeud{
    int d;
   struct noeud *next;
}noeud;


void enfiler(noeud **p, int d){
    noeud *nv;
    nv=(noeud *)malloc(sizeof(noeud));
    if(nv==NULL){
        printf("Erreur \n");
        return;
    }
    else{
        nv->d=d;
        nv->next=*(p);
        *(p)=nv;
    }

}

void defiler(noeud **p){
    noeud *temp;
    if(*p==NULL){
        printf("Erreur \n"); 
        return;
    }
    else{
        temp=*p;
        *p=(*p)->next;
        free(temp);
    }
}

void afficher(noeud**p){
    noeud *temp=*p;
    if(temp==NULL){
        printf("Erreur \n");
        return;
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->d);
            temp=temp->next;
            printf("\n");
        }
    }
}

void vider(noeud **p){
    while(*p!=NULL){
        defiler(&p);
    }
}

int main(){
    noeud *p=NULL;
    printf("enfilement:\n");
    enfiler(&p,10);
    enfiler(&p,20);
    enfiler(&p,30);
    afficher(&p);
    printf("defilement:\n");
    defiler(&p);
    afficher(&p);
    printf("enfilement nouveau:\n");
    enfiler(&p,40);
    afficher(&p);
    vider(&p);
    return 0;
}

 