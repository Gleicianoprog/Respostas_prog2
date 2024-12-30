#include"utils_char.h"
#include<stdlib.h>
#include<stdio.h>
char *CriaVetor(int tamanho){
    char * rtn;
    rtn=malloc(sizeof(*rtn)*tamanho);
    for (int i = 0; i < tamanho; i++){
        rtn[i]='_';   
    }
    return rtn;
}
void LeVetor(char *vetor, int tamanho){
    char c;
    int i=0;
    while (i<tamanho){  
        scanf("%c",&c);
        if(c!='\n'){
            *(vetor+i)=c;
            i++;
        }else{
            break;
        }
    }
    
}
void ImprimeString(char *vetor, int tamanho){
    int i=0;
    for (i = 0; i < tamanho; i++){
        printf("%c",*(vetor+i));
    }
    printf("\n");   
}
void LiberaVetor(char *vetor){
    free(vetor);
}