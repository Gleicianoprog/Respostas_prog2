#include<stdio.h>
#include"servidor.h"
#include"registro.h"
#include"jogador.h"
Servidor leRegistrosServidor(){
    Servidor rtn;
    int id=0,i=0;
    while (1){
        scanf("%d\n",&id);
        if(id==-1){
            break;
        }else{
            rtn.partidas[i]=leRegistro(id);
            i++;
            rtn.nPartidas=i;
        }
    }
    return rtn;
}
Jogador buscaDadosJogadorServidor(Servidor s, int idJog){
    int i=0;
    Jogador rtn;
    for ( i = 0; i < s.nPartidas; i++){
        rtn=buscaJogadorRegistro(s.partidas[i], idJog);
        rtn=atualizaJogador(rtn,getIdJogador(rtn),getKillsJogador(rtn), getDeathsJogador(rtn), getAssistsJogador(rtn));
    }
    return rtn;
}
void criaRelatorioServidor(Servidor s){
    int qtd=0,j=0,i=0,id=0;
    Jogador jogador,aux;
    scanf("%d\n",&qtd);
    for (i = 0; i < qtd; i++){
        scanf("%d",&id);
        jogador=inicializaJogador(-1);
        for ( j = 0; j <s.nPartidas; j++){
            aux=buscaJogadorRegistro(s.partidas[j],id);
            if(getIdJogador(aux)!=-1){
                jogador=atualizaJogador(jogador,getIdJogador(aux),getKillsJogador(aux), getDeathsJogador(aux), getAssistsJogador(aux));
            }
        }
        if(getIdJogador(jogador)!=-1){
            printaJogador(jogador);
        }else{
            printf("Jogador %d: -\n",id);
        }
    }
}