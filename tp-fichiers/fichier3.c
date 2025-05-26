#include<stdio.h>
#include<stdlib.h>
int main()
{ FILE *test = fopen("test.txt","r");
 FILE*test1 = fopen("test1.txt","w");
    char c;
    if(test==NULL || test1==NULL){
        printf("Erreur de creation\n");
        return 1;
    }       
    while((c=fgetc(test))!=EOF){
        fputc(c,test1);
    }
    fclose(test); 
    fclose(test1);
    printf("Fichier copie avec succes\n");  
    return 0;
}