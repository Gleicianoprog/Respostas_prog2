#include "data.h"
#include<stdio.h>
void imprimeData(tData d){
    printf("%d/%d/%d\n",d.dia,d.mes,d.ano);
}
tData ledata(){
    tData d;
    scanf("%02d/%02d/%04d\n",&d.dia,&d.mes,&d.ano);
    scanf("%*c");
    return d;
}
int calculaIdade(tData d){
    int idade=0;
    if(d.dia>=12&&d.mes>=9){
        idade++;
    }
    idade+=2023-d.ano+1;
    return idade;
}