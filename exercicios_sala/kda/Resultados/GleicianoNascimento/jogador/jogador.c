#include"jogador.h"
#include<stdio.h>
Jogador inicializaJogador(int id){
    Jogador rtn;
    rtn.id=id;
    rtn.kills=0;
    rtn.deaths=0;
    rtn.assists=0;
    rtn.valorKDA=-1;
    return rtn;
}
Jogador leJogador(int id){
    Jogador rtn;
    rtn.id=id;
    scanf("%d %d %d\n",&rtn.kills,&rtn.deaths,&rtn.assists);
    rtn.valorKDA=calculaKDA(rtn);
    return rtn;
}
float calculaKDA(Jogador j){
    float KDA=0;
    if(j.deaths){
        KDA=(j.kills+j.assists)*1.0/j.deaths;
    }else{
        KDA=j.kills+j.assists;
    }
    return KDA;
}
Jogador atualizaJogador(Jogador j, int id, int k, int d, int a){
    j.id=id;
    j.kills+=k;
    j.deaths+=d;
    j.assists+=a;
    j.valorKDA=calculaKDA(j);
    return j;
}
int getKillsJogador(Jogador j){
    return j.kills;
}
int getDeathsJogador(Jogador j){
    return j.deaths;
}
int getAssistsJogador(Jogador j){
    return j.assists;
}
int getIdJogador(Jogador j){
    return j.id;
}
void printaJogador(Jogador j){
    printf("Jogador %d: %d/%d/%d (%.2f)\n",j.id,j.kills,j.deaths,j.assists,j.valorKDA);
}