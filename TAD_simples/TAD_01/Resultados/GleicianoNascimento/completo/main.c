#include<stdio.h>
#include"tabuleiro.h"
#include"jogada.h"
#include"jogador.h"
#include"jogo.h"
int main(){
    tJogo jogo;
    char choice='s';
    while (choice=='s'){
        jogo=CriaJogo();
        ComecaJogo(jogo);
        printf("Jogar novamente? (s,n)\n");
        scanf("%*c");
        scanf("%c",&choice);
    }
    return 0;
}
