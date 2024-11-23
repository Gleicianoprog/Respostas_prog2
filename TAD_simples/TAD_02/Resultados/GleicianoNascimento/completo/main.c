#include<stdio.h>
#include"candidato.h"
#include"eleitor.h"
#include"eleicao.h"
int main(){
    tEleicao eleicao;
    eleicao=InicializaEleicao();
    eleicao=RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
    return 0;
}