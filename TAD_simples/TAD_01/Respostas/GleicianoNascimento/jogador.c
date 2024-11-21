#include"jogador.h"
#include"tabuleiro.h"
#include<stdio.h>
#include"jogada.h"
tJogador CriaJogador(int idJogador){
    tJogador rtn;
    rtn.id=idJogador;
    return rtn;
}
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogadaAtual;
    jogadaAtual=LeJogada();
    if(FoiJogadaBemSucedida(jogadaAtual)){
        if(EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogadaAtual),ObtemJogadaY(jogadaAtual))){
            printf("Jogada [%d,%d]!\n",ObtemJogadaX(jogadaAtual),ObtemJogadaY(jogadaAtual));
            tabuleiro=MarcaPosicaoTabuleiro(tabuleiro, jogador.id,ObtemJogadaX(jogadaAtual),ObtemJogadaY(jogadaAtual));
        }else{
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n",ObtemJogadaX(jogadaAtual),ObtemJogadaY(jogadaAtual));
        }
    }else{
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n",ObtemJogadaX(jogadaAtual),ObtemJogadaY(jogadaAtual));
    }
    return tabuleiro;
}
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    int i=0;
    if(jogador.id==1){
        for ( i = 0; i <TAM_TABULEIRO; i++){
            if(tabuleiro.posicoes[i][0]=='X'&&tabuleiro.posicoes[i][1]=='X'&&tabuleiro.posicoes[i][2]=='X'){
                return 1;
            }
        }
        for ( i = 0; i <TAM_TABULEIRO; i++){
            if(tabuleiro.posicoes[0][i]=='X'&&tabuleiro.posicoes[1][i]=='X'&&tabuleiro.posicoes[2][i]=='X'){
                return 1;
            }
        }
        if(tabuleiro.posicoes[0][0]=='X'&&tabuleiro.posicoes[1][1]=='X'&&tabuleiro.posicoes[2][2]=='X'){
            return 1;
        }
        if(tabuleiro.posicoes[0][2]=='X'&&tabuleiro.posicoes[1][1]=='X'&&tabuleiro.posicoes[2][0]=='X'){
            return 1;
        }
    }else{
        for ( i = 0; i <TAM_TABULEIRO; i++){
            if(tabuleiro.posicoes[i][0]=='0'&&tabuleiro.posicoes[i][1]=='0'&&tabuleiro.posicoes[i][2]=='0'){
                return 1;
            }
        }
        for ( i = 0; i <TAM_TABULEIRO; i++){
            if(tabuleiro.posicoes[0][i]=='0'&&tabuleiro.posicoes[1][i]=='0'&&tabuleiro.posicoes[2][i]=='0'){
                return 1;
            }
        }
        if(tabuleiro.posicoes[0][0]=='0'&&tabuleiro.posicoes[1][1]=='0'&&tabuleiro.posicoes[2][2]=='0'){
            return 1;
        }
        if(tabuleiro.posicoes[0][2]=='0'&&tabuleiro.posicoes[1][1]=='0'&&tabuleiro.posicoes[2][0]=='0'){
            return 1;
        }
    }
    return 0;
}