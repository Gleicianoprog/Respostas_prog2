#include"jogada.h"
#include<stdio.h>
#include"tabuleiro.h"
tJogada LeJogada(){
    tJogada rtn;
    printf("Digite uma posicao (x e y):\n");
    if(scanf("%d %d",&rtn.x,&rtn.y)==2){
        rtn.sucesso=1;
    }else{
        rtn.sucesso=0;
    }
    return rtn;
}
int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}
int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}
int FoiJogadaBemSucedida(tJogada jogada){
    return jogada.sucesso;
}

