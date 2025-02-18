#include"missil.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct missil
{
    char nome[MAX_TAM];
    float x;
    float y;
    float poder;
};
tMissil LeMissil(){
    tMissil rtn;
    char nome[MAX_TAM];
    rtn=malloc(sizeof(struct missil));
    scanf("%s %f %f %f\n",nome,&rtn->x,&rtn->y,&rtn->poder);
    rtn->nome[0]='M';
    rtn->nome[1]='-';
    rtn->nome[2]='\0';
    strcat(rtn->nome,nome);
    return rtn;
}
void ImprimeMissil(tMissil missil){
    printf("%s: %.2f\n",missil->nome,missil->poder);
}
void LiberaMissil(tMissil missil){
    free(missil);
}
float GetMissilY(tMissil missil){
    return missil->y;
}
float GetMissilX(tMissil missil){
    return missil->x;
}
float GetMissilPoder(tMissil missil){
    return missil->poder;
}
void ReduzPoder(tMissil missil, float valor){
    (missil->poder)-=valor;
    if(missil->poder<0){
        missil->poder=0;
    }
}