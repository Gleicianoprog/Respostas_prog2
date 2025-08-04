#include<stdio.h>
#include<stdlib.h>
#include"abb.h"
struct abb
{
    Abb* direita;
    Abb* esquerda;
    int frequencia;
    unsigned char letra;
};

Abb* abb_criaNo(int frequencia,char caracter,Abb* d,Abb* e){
    Abb* rtn;
    rtn=malloc(sizeof(Abb));
    rtn->frequencia=frequencia;
    rtn->direita=d;
    rtn->esquerda=e;
    rtn->letra=caracter;
    return rtn;
}
void imprimeNo(Abb* a){
    printf("%c ",a->letra);
}