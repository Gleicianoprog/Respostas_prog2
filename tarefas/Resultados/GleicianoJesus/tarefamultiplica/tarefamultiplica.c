#include "tarefamultiplica.h"
#include<stdio.h>
#include<stdlib.h>
struct mult
{
    float n1;
    float n2;
    // int tipo;
};

/**
 * @brief Cria uma tarefa do tipo multiplicação de dois números
 * 
 * @param n1 - Primeiro número que será multiplicado quando a tarefa for executada
 * @param n2 - Segundo número que será multiplicado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tMult* CriaTarefaMultiplicar(float n1, float n2){
    tMult* rtn;
    rtn=malloc(sizeof(tMult));
    rtn->n1=n1;
    rtn->n2=n2;
    return rtn;
}

/**
 * @brief Função que executa uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaMultiplicar(void *mult){
    tMult* multiplicacao;
    multiplicacao=(tMult*)(mult);
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f",multiplicacao->n1,multiplicacao->n2,(multiplicacao->n1)*(multiplicacao->n2));
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaMultiplicar(void *mult){
    free(mult);
}