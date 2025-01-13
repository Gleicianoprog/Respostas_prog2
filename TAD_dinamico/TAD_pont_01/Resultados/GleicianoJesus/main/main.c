#include<stdio.h>
#include"jogada.h"
#include"jogador.h"
#include"jogo.h"
#include"tabuleiro.h"
int main(){
    tJogo *jogo;
    jogo=CriaJogo();
    ComecaJogo(jogo);
    DestroiJogo(jogo);
    while (ContinuaJogo()){
        jogo=CriaJogo();
        ComecaJogo(jogo);
        DestroiJogo(jogo);
    }
    return 0;
}