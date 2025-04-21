#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int d;
   struct node *prec;
}node;

void empiler(node **p, int d){
    node *nv;
    nv=(node *)malloc(sizeof(node));
    if(nv==NULL){
        printf("Erreur \n");
        return;
    }
    else{
        nv->d=d;
        nv->prec=*(p);
        *(p)=nv;
    }

}

void depiler(node **p){
    node *temp;
    if(*p==NULL){
        printf("Erreur \n");
        return;
    }
    else{
        temp=*p;
        *p=(*p)->prec;
        free(temp);
    }
}
void afficher(node**p){
    node *temp=*p;
    if(temp==NULL){
        printf("Erreur \n");
        return;
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->d);
            temp=temp->prec;
            printf("\n");
        }
    }
}
void main(){
    node *p=NULL;
    printf("empilement:\n");
    empiler(&p,10);
    empiler(&p,20);
    empiler(&p,30);
    afficher(&p);
    printf("depilement:\n");
    depiler(&p);
    afficher(&p);
}

