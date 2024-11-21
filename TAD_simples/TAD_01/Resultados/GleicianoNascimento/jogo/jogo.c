#include"jogo.h"
#include"tabuleiro.h"
#include<stdio.h>
tJogo CriaJogo(){
    tJogo rtn;
    rtn.tabuleiro= CriaTabuleiro();
    rtn.jogador1=CriaJogador(1);
    rtn.jogador2=CriaJogador(2);
    return rtn;
}
int AcabouJogo(tJogo jogo){
    int i=0,j=0;
    if(!TemPosicaoLivreTabuleiro(jogo.tabuleiro)){
        return 1;
    }
    return 0;
    
}
void ComecaJogo(tJogo jogo){
    int jogador=1;
    while(!AcabouJogo(jogo)&&!VenceuJogador(jogo.jogador1,jogo.tabuleiro)&&!VenceuJogador(jogo.jogador2, jogo.tabuleiro)){
        printf("Jogador %d\nDigite uma posicao (x e y):\n",jogador);
        if(jogador==1){
            jogo.tabuleiro=JogaJogador(jogo.jogador1, jogo.tabuleiro);
            ImprimeTabuleiro(jogo.tabuleiro);
            if(VenceuJogador(jogo.jogador1,jogo.tabuleiro)){
                printf("JOGADOR 1 Venceu!\n");
            }
            jogador=2;
        }else{
            jogo.tabuleiro=JogaJogador(jogo.jogador2, jogo.tabuleiro);
            ImprimeTabuleiro(jogo.tabuleiro);
            if(VenceuJogador(jogo.jogador2,jogo.tabuleiro)){
                printf("JOGADOR 2 Venceu!\n");
            }
            jogador=1;
        }
    }
}