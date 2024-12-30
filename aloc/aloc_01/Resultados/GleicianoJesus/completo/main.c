#include<stdio.h>
#include"utils.h"
int main(){
    int* vet;
    int tamanho=0;
    float media;
    scanf("%d\n",&tamanho);
    vet=CriaVetor(tamanho);
    LeVetor(vet, tamanho);
    media=CalculaMedia(vet, tamanho);
    LiberaVetor(vet);
    printf("%.2lf\n",media);
    return 0;
}