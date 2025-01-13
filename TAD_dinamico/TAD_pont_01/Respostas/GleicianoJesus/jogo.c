#include"jogo.h"
#include"jogador.h"
#include"tabuleiro.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
tJogo* CriaJogo(){
    tJogador *jogador1,*jogador2;
    tJogo *rtn;
    tTabuleiro *tabuleiro;
    jogador1=CriaJogador(ID_JOGADOR_1);
    jogador2=CriaJogador(ID_JOGADOR_2);
    tabuleiro=CriaTabuleiro();
    rtn=malloc(sizeof(tJogo));
    assert(rtn);
    rtn->jogador1=jogador1;
    rtn->jogador2=jogador2;
    rtn->tabuleiro=tabuleiro;
    return rtn;
}
void DestroiJogo(tJogo* jogo){
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    DestroiTabuleiro(jogo->tabuleiro);
    free(jogo);
}
void ComecaJogo(tJogo* jogo){
    tJogador *jogadorAtual=jogo->jogador1;
    int jogador=1,temVencedor=0;
    while (!AcabouJogo(jogo)&&!VenceuJogador(jogo->jogador1,jogo->tabuleiro)&&!VenceuJogador(jogo->jogador2,jogo->tabuleiro)){
        JogaJogador(jogadorAtual,jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
        if(jogador==1){
            jogadorAtual=jogo->jogador2;
            jogador++;
        }else{
            jogadorAtual=jogo->jogador1;
            jogador--;
        }
    }
    if(VenceuJogador(jogo->jogador1,jogo->tabuleiro)){
        printf("JOGADOR 1 Venceu!\n");
        temVencedor=1;
    }
    if(VenceuJogador(jogo->jogador2,jogo->tabuleiro)){
        printf("JOGADOR 2 Venceu!\n");
        temVencedor=1;
    }
    if(AcabouJogo(jogo)&&!temVencedor){
        printf("Sem vencedor!\n");
    }
    printf("Jogar novamente? (s,n)\n");
}
int AcabouJogo(tJogo* jogo){
    if(!TemPosicaoLivreTabuleiro(jogo->tabuleiro)){
        return 1;
    }
    return 0;
}
int ContinuaJogo(){
    char jogar='s';
    while(1){
        scanf("%c",&jogar);
        if(jogar=='s'||jogar=='n'){
            break;
        }
    }
    if(jogar=='s'){
        return 1;
    }
    return 0;
}