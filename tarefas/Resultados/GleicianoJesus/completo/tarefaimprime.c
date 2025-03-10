#include<string.h>
#include"tarefaimprime.h"
#include<stdlib.h>
#include<stdio.h>
struct impr
{
    char* msg;
    //int prioridade;
    //int tipo;
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg){
    tImpr* rtn;
    char *mensagem;
    rtn=malloc(sizeof(tImpr));
    rtn->msg=malloc(sizeof(char)*(strlen(msg)+1));
    strcpy(rtn->msg,msg);
    return rtn;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp){
    tImpr* imprime;
    imprime=(tImpr*)imp;
    printf("\n%s",imprime->msg);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp){
    tImpr* imprime;
    imprime=(tImpr*)imp;
    free(imprime->msg);
    free(imp);
}