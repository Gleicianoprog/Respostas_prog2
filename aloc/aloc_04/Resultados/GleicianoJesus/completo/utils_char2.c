#include"utils_char2.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
char *CriaVetorTamPadrao(){
    char * rtn;
    int i=0;
    rtn=malloc(sizeof(char)*TAM_PADRAO);
    assert(rtn);
    for (i; i < TAM_PADRAO-1; i++){
        rtn[i]='_';
    }
    rtn[i]='\0';
    return rtn;
}
char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo){
    //printf("%d\n",tamanhoantigo+TAM_PADRAO);
    int i=tamanhoantigo-1;
    vetor=realloc(vetor,sizeof(char) * (tamanhoantigo+TAM_PADRAO));
    for ( i ; i < (tamanhoantigo+TAM_PADRAO-1) ; i++){
        vetor[i]='_';
        //printf("%c",vetor[i]);
    }
    vetor[i]='\0';
    return vetor;
}
// char* LeVetor(char *vetor, int *tamanho){
// }
void ImprimeString(char *vetor){
    int i=0;
    printf("%s_\n",vetor);
}
char* LeVetor(char *vetor, int *tamanho){
    int i=0;
    char c;
    while (1){
        scanf("%c",&c);
        if(c=='\n'){
            break;
        }
        if(i>= (*tamanho)-1){
            vetor=AumentaTamanhoVetor(vetor,*tamanho);
            *tamanho=*tamanho+TAM_PADRAO;
        }
        vetor[i]=c;
        i++;
    }
    //vetor[i]='\0';
    return vetor;
}
void LiberaVetor(char *vetor){
    free(vetor);
}