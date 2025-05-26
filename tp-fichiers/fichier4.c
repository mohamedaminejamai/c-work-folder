#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int nbcaractere=0,nbmot=0,nbligne=0,i=0;
    char c; 

    FILE *fichier = fopen("test.txt","r");
    if (fichier == NULL) {
        printf("Erreur de creation\n");
        return 1;
    }
    while (c = fgetc(fichier) != EOF) {
        if (c == '\n') {
            nbligne++;
        }
        if (isspace(c)) {
            nbmot++;
        }
        nbcaractere++;
    }
    fclose(fichier);    
    printf("Nombre de caracteres: %d\n", nbcaractere);
    printf("Nombre de mots: %d\n", nbmot);  
    printf("Nombre de lignes: %d\n", nbligne);
    return 0;   
}
    
