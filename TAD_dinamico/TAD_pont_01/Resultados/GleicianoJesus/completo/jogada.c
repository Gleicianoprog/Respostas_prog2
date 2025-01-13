#include"jogada.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"tabuleiro.h"
tJogada* CriaJogada(){
    tJogada *rtn;
    rtn=malloc(sizeof(tJogada));
    assert(rtn);
    return rtn;
}
void DestroiJogada(tJogada* jogada){
    assert(jogada);
    free(jogada);
}
void LeJogada(tJogada* jogada){
    printf("Digite uma posicao (x e y):\n");
    if(scanf("%d %d\n",&jogada->x,&jogada->y)==2){
        jogada->sucesso=1;
    }else{
        jogada->sucesso=0;
    }

}
int ObtemJogadaX(tJogada* jogada){
    return jogada->x;
}
int ObtemJogadaY(tJogada* jogada){
    return jogada->y;
}
int FoiJogadaBemSucedida(tJogada* jogada){
    return jogada->sucesso;
}