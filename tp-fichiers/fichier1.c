#include<stdio.h>
#include<stdlib.h>

int main()
{
char nom[100];
int age;
FILE*fichier =fopen("test.txt","w");
if(fichier ==NULL){
printf("Erreur de creation\n");
return 1;
}
printf("votre nom:");
scanf("%s",nom);        
printf("votre age:");
scanf("%d",&age);
fprintf(fichier,"Nom:%s\n",nom);
fprintf(fichier,"Age:%d\n",age);        
fclose(fichier);
printf("Fichier cree avec succes\n");       

}