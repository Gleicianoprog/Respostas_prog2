#include"vetor.h"
#include<stdio.h>
void LeDadosParaVetor(int * vet, int tam){
    int i=0;
    for ( i = 0; i < tam; i++){
        scanf("%d",(vet+i));
    }
}
void ImprimeDadosDoVetor(int * n, int tam){
    for (int i = 0; i < tam; i++){
        printf("%d ",*(n+i));   
    }
    printf("\n");
}
void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){
    int menorValor,i=0;
    int *menorPont;
    for (paraTrocar ; ((paraTrocar+i) < (vet+tam)); i++){
        if(!i){
            menorValor=*paraTrocar;
            menorPont=paraTrocar;
        }
        if(*(paraTrocar+i)<menorValor){
            menorValor=*(paraTrocar+i);
            menorPont=(paraTrocar+i);
        }
    }
    *menorPont=*paraTrocar;
    *paraTrocar=menorValor;
}
void OrdeneCrescente(int * vet, int tam){
    for (int i = 0; i < tam; i++){
        TrocaSeAcharMenor(vet,tam,(vet+i));
    }   
}