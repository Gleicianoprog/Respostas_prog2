#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"tabuleiro.h"
tTabuleiro* CriaTabuleiro() {
    tTabuleiro *rtn = (tTabuleiro *)malloc(sizeof(tTabuleiro));
    assert(rtn);

    rtn->posicoes = (char **)malloc(TAM_TABULEIRO * sizeof(char *));
    assert(rtn->posicoes);

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        rtn->posicoes[i] = (char *)malloc(TAM_TABULEIRO * sizeof(char));
        assert(rtn->posicoes[i]); 
    }
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            rtn->posicoes[i][j] = '-';
        }
    }
    // rtn->posicoes[0][0]='0';
    // rtn->posicoes[1][0]='0';
    // rtn->posicoes[2][0]='0';
    rtn->peca1='X';
    rtn->peca2='0';
    rtn->pecaVazio='-';
    return rtn;
}
void DestroiTabuleiro(tTabuleiro* tabuleiro) {
    if (tabuleiro == NULL) return;

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        free(tabuleiro->posicoes[i]);
    }
    free(tabuleiro->posicoes);
    free(tabuleiro);
}
void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){
    char cPeca;
    if(peca==PECA_1){
        cPeca=tabuleiro->peca1;
    }else if(peca==PECA_2){
        cPeca=tabuleiro->peca2;
    }
    tabuleiro->posicoes[y][x]=cPeca;
}
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){
    for ( int i = 0; i < TAM_TABULEIRO; i++){
        for ( int j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro->posicoes[i][j]==tabuleiro->pecaVazio){
                return 1;
            }
        }
    }
    return 0;
}
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){
    char cPeca;
    if(peca== PECA_1){
        cPeca=tabuleiro->peca1;
    }else{
        cPeca=tabuleiro->peca2;
    }
    if(tabuleiro->posicoes[y][x]==cPeca){
        return 1;
    }
    return 0;
}
int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    if(tabuleiro->posicoes[y][x]==tabuleiro->pecaVazio){
        return 1;
    }
    return 0;
}
int EhPosicaoValidaTabuleiro(int x, int y){
    if(x>=0 && x < TAM_TABULEIRO && y>=0 && y< TAM_TABULEIRO){
        return 1;
    }
    return 0;
}
void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    for ( int i = 0; i < TAM_TABULEIRO; i++){
        printf("\t");
        for (int  j = 0; j < TAM_TABULEIRO; j++){
            printf("%c",tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }

}