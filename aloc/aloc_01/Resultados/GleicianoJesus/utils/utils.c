#include<stdlib.h>
#include<stdio.h>
int *CriaVetor(int tamanho){
    int *rtn;
    rtn=malloc(sizeof(*rtn)*tamanho);
    return rtn;
}
void LeVetor(int *vetor, int tamanho){
    for ( int i = 0; i < tamanho; i++){
        scanf("%d",&(vetor[i]));
    }
}
float CalculaMedia(int *vetor, int tamanho){
    float media;
    int soma=0;
    for (int  i = 0; i < tamanho; i++){
        soma+=vetor[i];
    }
    media=(soma*1.0)/tamanho;
    return media;
}
void LiberaVetor(int *vetor){
    free(vetor);
}