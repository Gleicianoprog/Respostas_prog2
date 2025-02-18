#include"array.h"
#include<stdio.h>
int main(){
    Array * a;
    int elementoB=0,idx=0;
    a=CriarArray();
    LerArray(a);
    OrdenarArray(a);
    scanf("%d",&elementoB);
    idx=BuscaBinariaArray(a,elementoB);
    if(idx!=-1){

        printf("Elemento %d encontrado no índice %d.\n",elementoB,idx);
    }else{
        printf("Elemento %d não encontrado no array (-1).",elementoB);
    }
    DestruirArray(a);
    return 0;
}