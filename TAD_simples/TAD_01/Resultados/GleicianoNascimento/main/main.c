#include<stdio.h>
#include"tabuleiro.h"
#include"jogada.h"
#include"jogador.h"
#include"jogo.h"
int main(){
    int continua=0;
    tJogo jogo;
    jogo=CriaJogo();
    ComecaJogo(jogo);
    while (1){
        continua=ContinuaJogo();
        if(!continua){
            break;
        }
        jogo=CriaJogo();
        ComecaJogo(jogo);
    }
    return 0;
}
