#include "utils.h"
#include <stdio.h>
void LeNumeros(int *array, int tamanho){
    for (int i = 0; i < tamanho; i++){
        scanf("%d",(array+i));   
    }
}
void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    int Maior,Menor;
    float Media=0;
    for ( int i = 0; i < tamanho; i++){
        Media+=*(array+i);
        if(i==0){
            Maior=*array;
            Menor=*array;
            continue;
        }
        if(*(array+i)>Maior){
            Maior=*(array+i);
        }
        if(*(array+i)<Menor){
            Menor=*(array+i);
        }
    }
    Media=(Media*1.0)/(tamanho);
    *maior=Maior;
    *menor=Menor;
    *media=Media;
}