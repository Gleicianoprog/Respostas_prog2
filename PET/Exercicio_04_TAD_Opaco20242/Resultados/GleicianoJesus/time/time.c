#include"time.h"
#include<stdio.h>
#include<stdlib.h>
/** 
 * @brief Construtor do tipo time. Deve ler um nome pela entrada padrao.
*/
struct _Time
{
    char nome[100];
    int vitorias;
    int derrotas;
    int golsSofridos;
    int golsMarcados;
    int empates;
};

tTime* LeTime(){
    tTime* rtn;
    rtn=malloc(sizeof(struct _Time));
    //rtn->nome=malloc(sizeof(+));
    scanf("%[^\n]\n",rtn->nome);
    rtn->vitorias=0;
    rtn->derrotas=0;
    rtn->golsSofridos=0;
    rtn->empates=0;
    rtn->golsMarcados=0;
    return rtn;
}

/**
 * @brief Retona o numero de vitorias do time.
*/
int ObtemVitorias(tTime *t){
    return t->vitorias;
}

/**
 * @brief Retona o numero de partidas.
*/
int ObtemPartidas(tTime *t){
    return (t->derrotas)+(t->empates)+(t->vitorias);
}

/**
 * @brief Retona o numero de derrotas do time.
*/
int ObtemDerrotas(tTime *t){
    return t->derrotas;
}

/**
 * @brief Retona a string do nome do time.
*/
char* ObtemNomeTime(tTime *t){
    return t->nome;
}

/**
 * @brief Retona o saldo de gols da equipe.
*/
int ObtemSaldo(tTime *t){
    return (t->golsMarcados)-(t->golsSofridos);
}

/**
 * @brief Aumenta o numero de vitorias em 1.
*/
void AtualizaVitorias(tTime *t){
    t->vitorias+=1;
}

/**
 * @brief Aumenta o numero de empates em 1.
*/
void AtualizaEmpates(tTime *t){
    t->empates+=1;
}

/**
 * @brief Aumenta o numero de derrotas em 1.
*/
void AtualizaDerrotas(tTime *t){
    t->derrotas+=1;
}

/**
 * @brief Aumenta a quantidade de gols marcados.
*/
void AtualizaGolsMarcados(tTime *t, int gols){
    t->golsMarcados+=gols;
}

/**
 * @brief Aumenta a quantidade de gols sofridos.
*/
void AtualizaGolsSofridos(tTime *t, int gols){
    t->golsSofridos+=gols;
}

/**
 * @brief Retorna a pontuacao do time.
*/
int ObtemPontos(tTime* t){
    return ((t->vitorias)*3)+(t->empates);
}

/**
 * @brief Usa os criterios de classificacao para indicar qual time possui melhor colocacao. Retorna -1 para t1, 1 para t2.
*/
int DesempataTimes(tTime *t1, tTime *t2){
    if(ObtemPontos(t1)>ObtemPontos(t2)){
        return -1;
    }
    if(ObtemPontos(t2)>ObtemPontos(t1)){
        return 1;
    }
    if(ObtemVitorias(t1)>ObtemVitorias(t2)){
        return -1;
    }
    if(ObtemVitorias(t2)>ObtemVitorias(t1)){
        return 1;
    }
    if(ObtemSaldo(t1)>ObtemSaldo(t2)){
        return -1;
    }
    if(ObtemSaldo(t2)>ObtemSaldo(t1)){
        return 1;
    }
}

/**
 * @brief Imprime os dados do time na ordem: Nome | Pontos | Vitorias | Derrotas | Empates | Saldo.
 * Dica: Use a seguinte formatacao no printf: "%-12s | %02d | %02d | %02d | %02d | %+03d\n".
*/
void ImprimeTime(tTime *t){
    // char nome[100];
    // int pontos,vitorias,derrotas,empates,saldo;
    int empates=ObtemPartidas(t)-ObtemVitorias(t)-ObtemDerrotas(t);
    // printf("%dAA\n",ObtemDerrotas(t));
    printf("%-12s | %02d | %02d | %02d | %02d | %+03d\n",ObtemNomeTime(t),ObtemPontos(t),ObtemVitorias(t),ObtemDerrotas(t),empates,ObtemSaldo(t));
}

/**
 * @brief Libera a memoria alocada para time.
*/
void DesalocaTime(tTime *t){
    free(t);
}