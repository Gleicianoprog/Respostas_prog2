#include"tabela.h"
#include"time.h"
#include<stdlib.h>
#include<stdio.h>
#include"brasileirao.h"
struct _BRA
{
    int numTimes;
    int numRodadas;
    float premio;
    tTabela* tabela;
};
void imprimeMenu(){
    printf("Menu:\nC - Continuar\nR - Retirar 2 times e seguir\nF - Finalizar\n");
}
/**
 * @brief Construtor do campeonato. Le da entrada padrao numero de times, numero de rodadas e pontuacao.
 */
BRA *CriaCamp(){
    BRA* rtn;
    int numTimes;
    rtn=malloc(sizeof(BRA));
    printf("Insira o num de times, rodadas e premio total:\n");
    scanf("%d %d %f\n",&numTimes,&rtn->numRodadas,&rtn->premio);
    rtn->tabela=CriaTabela(numTimes);
    rtn->numTimes=numTimes;
    return rtn;
}

/**
 * @brief Le da entrada padrao as partidas da rodada, computa os resultados e atualiza a tabela.
*/
void RealizaRodada(BRA *br){
    tTime * time1,*time2;
    char nome1[100],nome2[100];
    int gol1,gol2;       
    scanf("%s %d x %d %s\n",nome1,&gol1,&gol2,nome2);
    time1=ObtemTimeTabela(br->tabela,nome1);
    time2=ObtemTimeTabela(br->tabela,nome2);
    AtualizaGolsMarcados(time1,gol1);
    AtualizaGolsSofridos(time1,gol2);
    AtualizaGolsSofridos(time2,gol1);
    AtualizaGolsMarcados(time2,gol2);
    if(gol1>gol2){
        AtualizaVitorias(time1);
        AtualizaDerrotas(time2);
    }else if(gol2>gol1){
        AtualizaVitorias(time2);
        AtualizaDerrotas(time1);
    }else{
        AtualizaEmpates(time1);
        AtualizaEmpates(time2);
    }
}

/**
 * @brief Imprime o menu e trata cada opcao.
*/
void RealizaCamp(BRA *br){
    char op;
    int rodadas=br->numTimes;
    for (int i = 0; i < br->numRodadas; i++){
        imprimeMenu();
        printf("\n");
        scanf("%c\n",&op);
        if(!(br->numTimes)){
            break;
        }
        if(op=='C'){
            for (int i = 0; i < rodadas/2; i++)
            {
                RealizaRodada(br);
            }
            
        }else if(op=='R'){
            RemoveTimesCamp(br);
        }else if(op=='F'){
            break;
        }
        OrdenaTabela(br->tabela);
        if(br->numTimes){
            ImprimeTabela(br->tabela);
        }
    }
    //FinalizaCamp(br);
    
}

/**
 * @brief Le 2 nomes da entrada padrao e remove os times correspondentes da competicao.
*/
void RemoveTimesCamp(BRA *br){
    char nome1[100],nome2[100];
    scanf("%s %s\n",nome1,nome2);
    printf("Times a serem retirados:\nOs times %s e %s se retiraram do campeonato\n",nome1,nome2);
    // 
// 
    RemoveTimeTabela(br->tabela,nome1);
    RemoveTimeTabela(br->tabela,nome2);
    br->numTimes-=2;
    OrdenaTabela(br->tabela);
    if(br->numTimes){
        RealizaRodada(br);
    }
    //br->numRodadas-=1;
}

/**
 * @brief Libera a memoria do campeonato.
*/
void DesalocaCamp(BRA *br){
    DesalocaTabela(br->tabela);
    free(br);
}

/**
 * @brief Imprime a tabela final, premiacao e desaloca o campeonato.
*/
void FinalizaCamp(BRA *br){
    if(br->numTimes){
        OrdenaTabela(br->tabela);
        printf("Esta foi a tabela final:\n");
        ImprimeTabela(br->tabela);
    }
    ImprimePremiacao(br->tabela,br->premio);
    printf("Fim do campeonato\n");
    DesalocaCamp(br);
}