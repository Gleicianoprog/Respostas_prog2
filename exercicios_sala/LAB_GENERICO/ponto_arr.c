#include"ponto_geometrico.h"
#include"ponto_arr.h"
#include<stdlib.h>
struct ponto_arr{
    tPonto **arr;
    int i;
    int tamMax;
};
tPontos_arr *inicializarTPontos(){
    tPontos_arr *rtn;
    rtn=malloc(sizeof(tPontos_arr));
    rtn->i=0;
    rtn->tamMax=10;
    rtn->arr=malloc(sizeof(tPonto*)*rtn->tamMax);
    return rtn;
}
void adicionarPonto(tPonto *p, tPontos_arr *tp){
    if((tp->i)>(tp->tamMax)){
        (tp->tamMax)=(tp->tamMax)*2;
        tp->arr=realloc(tp->arr,sizeof(tPonto*)*tp->tamMax);
    }  
    tp->arr[tp->i]=p;
    (tp->i)++;
}

void carregarPontos(tPontos_arr *p,int qtde){
    tPonto *pAtual;
    p=inicializarTPontos();
    pAtual=CriarPonto(2.5, 1.8);
    for (int i = 0; i < qtde; i++){
        adicionarPonto(pAtual,p);
    }
}
void imprimirPontos(tPontos_arr *arr){
    for (int i = 0; i < arr->i; i++){
        ImprimirPonto(arr->arr[i]);
    }
}
void liberarPontos(tPontos_arr * arr){
    for (int i = 0; i < arr->i; i++){
        LiberarPonto(arr->arr[i]);
    }
    free(arr);
}