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
    if(!TemPosicaoLivreTabuleiro(jogo.tabuleiro)){
        return 1;
    }
    return 0;
    
}
void ComecaJogo(tJogo jogo){
    int jogador=1;
    while(!AcabouJogo(jogo)&&!VenceuJogador(jogo.jogador1,jogo.tabuleiro)&&!VenceuJogador(jogo.jogador2, jogo.tabuleiro)){
        if(jogador==1){
            jogo.tabuleiro=JogaJogador(jogo.jogador1, jogo.tabuleiro);
            ImprimeTabuleiro(jogo.tabuleiro);
            if(VenceuJogador(jogo.jogador1,jogo.tabuleiro)){
                printf("JOGADOR 1 Venceu!\n");
                printf("Jogar novamente? (s,n)\n");
            }
            jogador=2;
        }else{
            jogo.tabuleiro=JogaJogador(jogo.jogador2, jogo.tabuleiro);
            ImprimeTabuleiro(jogo.tabuleiro);
            if(VenceuJogador(jogo.jogador2,jogo.tabuleiro)){
                printf("JOGADOR 2 Venceu!\n");
                printf("Jogar novamente? (s,n)\n");
            }
            jogador=1;
        }
    }
    if(AcabouJogo(jogo)&&!VenceuJogador(jogo.jogador1,jogo.tabuleiro)&&!VenceuJogador(jogo.jogador2, jogo.tabuleiro)){
        printf("Sem vencedor!\n");
        printf("Jogar novamente? (s,n)\n");
    }
}
int ContinuaJogo(){
    char choice='s';
    while(1){
        scanf("%c",&choice);
        if(choice=='s'||choice=='n'){
            break;
        }
    }
    if(choice=='s'){
        return 1;
    }else if(choice=='n'){
        return 0;
    }
}