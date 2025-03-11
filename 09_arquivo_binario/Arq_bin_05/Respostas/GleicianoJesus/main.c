#include<stdio.h>
#include"estabelecimento.h"
int main(){
    tEstabelecimento * e;
    e=CriaEstabelecimento();
    LeEstabelecimento(e);
    ImprimeProdutosEmFaltaEstabelecimento(e);
    DestroiEstabelecimento(e);
    return 0;
}