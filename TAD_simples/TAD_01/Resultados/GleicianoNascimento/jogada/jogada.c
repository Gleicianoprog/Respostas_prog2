#include"jogada.h"
#include<stdio.h>
#include"tabuleiro.h"
tJogada LeJogada(){
    tJogada rtn;
    scanf("%d %d",&rtn.x,&rtn.y);
    return rtn;
}
int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}
int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}
int FoiJogadaBemSucedida(tJogada jogada){
    int jogadaX=ObtemJogadaX(jogada),jogadaY=ObtemJogadaY(jogada);
    if(jogadaX<3&&jogadaX>=0&&jogadaY<3&&jogadaY>=0){
        return 1;
    }
    return 0;
}

