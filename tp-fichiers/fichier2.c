#include<stdio.h>
#include<stdlib.h>

int main()
{
char aide[100];     
int age;
FILE*fichier =fopen("test.txt","r");
if(fichier ==NULL){
printf("Erreur de creation\n"); 
return 1;
}
while(fgets(aide,100,fichier)!=NULL){
printf("%s",aide);
}   
fclose(fichier);
printf("Fichier lit avec succes\n");       
}

