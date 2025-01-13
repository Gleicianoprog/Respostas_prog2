#include "jogador.h"
#include "tabuleiro.h"
#include <stdlib.h>
#include<assert.h>
#include "jogada.h"
#include<stdio.h>
tJogador* CriaJogador(int idJogador){
    tJogador *rtn;
    ///scanf("%*c");
    rtn=malloc(sizeof(tJogador));
    assert(rtn);
    rtn->id=idJogador;
    return rtn;
}
void DestroiJogador(tJogador* jogador){
    assert(jogador);
    free(jogador);
}
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    tJogada jogadaAtual;
    while(1){
        printf("Jogador %d\n",jogador->id);
        LeJogada(&jogadaAtual);
        if(FoiJogadaBemSucedida(&jogadaAtual)){
            if(!EhPosicaoValidaTabuleiro(jogadaAtual.x,jogadaAtual.y)){
                printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n",ObtemJogadaX(&jogadaAtual),ObtemJogadaY(&jogadaAtual));
                continue;
            }
            if(EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(&jogadaAtual),ObtemJogadaY(&jogadaAtual))){
                printf("Jogada [%d,%d]!\n",ObtemJogadaX(&jogadaAtual),ObtemJogadaY(&jogadaAtual));
                MarcaPosicaoTabuleiro(tabuleiro, jogador->id,ObtemJogadaX(&jogadaAtual),ObtemJogadaY(&jogadaAtual));
                break;
            }else{
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n",ObtemJogadaX(&jogadaAtual),ObtemJogadaY(&jogadaAtual));
                continue;
            }
        }else{
            printf("Formato invalido!\n");
            continue;
        }
    }
    // tJogada jogadaAtual;
    // char cPeca;
    // LeJogada(&jogadaAtual);
    // if(jogador->id == ID_JOGADOR_1){
    //     cPeca=tabuleiro->peca1;
    // }else if(jogador->id == ID_JOGADOR_2){
    //     cPeca=tabuleiro->peca2;
    // }
    // if(FoiJogadaBemSucedida(&jogadaAtual)&&EstaLivrePosicaoTabuleiro(tabuleiro,ObtemJogadaX(&jogadaAtual),ObtemJogadaY(&jogadaAtual))){
    //     MarcaPosicaoTabuleiro(tabuleiro,cPeca,ObtemJogadaX(&jogadaAtual),ObtemJogadaY(&jogadaAtual));
    // }
}
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    char peca;
    int count=0;
    if(jogador->id == ID_JOGADOR_1){
        peca=tabuleiro->peca1;
    }else if(jogador->id ==ID_JOGADOR_2){
        peca=tabuleiro->peca2;
    }
    for (int i = 0; i < TAM_TABULEIRO; i++){
        if(tabuleiro->posicoes[i][0]==peca && tabuleiro->posicoes[i][1]==peca && tabuleiro->posicoes[i][2]==peca){
            return 1;
        }
        if(tabuleiro->posicoes[0][i]==peca && tabuleiro->posicoes[1][i]==peca && tabuleiro->posicoes[2][i]==peca){
            return 1;
        }
    }
    if(tabuleiro->posicoes[0][0]==peca && tabuleiro->posicoes[1][1]==peca && tabuleiro->posicoes[2][2]==peca){
        return 1;
    }
    if(tabuleiro->posicoes[0][2]==peca && tabuleiro->posicoes[1][1]==peca && tabuleiro->posicoes[2][0]==peca){
        return 1;
    }
    return 0;
}