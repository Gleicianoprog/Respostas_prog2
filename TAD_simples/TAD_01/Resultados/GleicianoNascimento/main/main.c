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
    printf("Jogar novamente? (s,n)\n");
    scanf("%*c");
    while (1){
        continua=ContinuaJogo();
        if(continua==1){
            jogo=CriaJogo();
            ComecaJogo(jogo);
            printf("Jogar novamente? (s,n)\n");
            scanf("%*c");
        }else if(continua==-1){
            continue;
        }else{
            break;
        }
    }
    return 0;
}
