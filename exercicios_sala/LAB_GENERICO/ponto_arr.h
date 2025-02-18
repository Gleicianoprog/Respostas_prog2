#include<stdio.h>
#include<stdlib.h>
typedef struct ponto_arr tPontos_arr;
tPontos_arr* inicializarTPontos();
void adicionarPonto(tPonto *p, tPontos_arr *tp);
void carregarPontos(tPontos_arr *p,int qtde);
void imprimirPontos(tPontos_arr *arr);
void liberarPontos(tPontos_arr * arr);