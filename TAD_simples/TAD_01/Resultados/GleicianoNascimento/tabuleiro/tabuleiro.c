#include"tabuleiro.h"
#include<stdio.h>
tTabuleiro CriaTabuleiro(){
    int i=0,j=0;
    tTabuleiro rtn;
    rtn.peca1='X';
    rtn.peca2='0';
    rtn.pecaVazio='-';
    for(i;i<TAM_TABULEIRO;i++){
        for ( j=0; j< TAM_TABULEIRO; j++){
            rtn.posicoes[i][j]=rtn.pecaVazio;
        }
    };
    return rtn;
}
tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    if(peca==PECA_1){
        tabuleiro.posicoes[y][x]=tabuleiro.peca1;
    }else{
        tabuleiro.posicoes[y][x]=tabuleiro.peca2;
    }
    return tabuleiro;
}
int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if(tabuleiro.posicoes[y][x]==tabuleiro.pecaVazio){
        return 1;
    }
    return 0;
}
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int i=0,j=0;
    for ( i = 0; i <TAM_TABULEIRO ; i++){
        for ( j = 0; j <TAM_TABULEIRO ; j++){
            if(EstaLivrePosicaoTabuleiro(tabuleiro, i,j)){
                return 1;
            }
        }
    }
    return 0;
}
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(peca==PECA_1 && tabuleiro.posicoes[y][x]== 'X'){
        return 1;
    }
    if(peca==PECA_2 && tabuleiro.posicoes[y][x]== '0'){
        return 1;
    }
    return 0;
}
int EhPosicaoValidaTabuleiro(int x, int y){
    if(x<3&&x>=0&&y<3&&y>=0){
        return 1;
    }
    return 0;
}
void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int i=0,j=0;
    for ( i = 0; i < TAM_TABULEIRO; i++){
        printf("\t");
        for ( j = 0; j < TAM_TABULEIRO; j++){
            printf("%c",tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
    
}