#include<stdio.h>
#include <stdlib.h>
#include"ponto_geometrico.h"
#include"ponto_arr.h"
int main(int argc,char **argv){
    int qtd;
    qtd=atoi(argv[1]);
    tPontos_arr *p;
    // p=inicializarTPontos();
    carregarPontos(p,qtd);
    imprimirPontos(p);
    liberarPontos(p);
    return 0;
}