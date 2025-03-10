// // Definição de tipos para funções de impressão e desalocação de dados
// typedef void (*PrintFunction)(void* data);  // Função para imprimir os dados de uma mídia
// typedef void (*FreeFunction)(void* data);   // Função para liberar os dados de uma mídia
#include<stdio.h>
#include<stdlib.h>
#include"midia.h"
//typedef struct Midia Midia;
struct Midia{
    PrintFunction funcaoImprime;
    FreeFunction funcaoLibera;
    void* dado;
};

// Aloca dinamicamente uma nova estrutura Midia, recebe os dados da mídia,
// a função de impressão (print_fn) e a função de desalocação (free_fn),
// e os insere na estrutura de forma adequada. Retorna o ponteiro para a Midia.
// Parâmetros:
//  dado    - Ponteiro genérico para os dados da mídia.
//  print_fn - Função responsável pela impressão dos dados da mídia.
//  free_fn  - Função responsável pela liberação de memória dos dados da mídia.
// Retorna: Ponteiro para a Midia recém-criada com os dados e funções associadas.
Midia *midia_construct(void *dado, PrintFunction print_fn, FreeFunction free_fn){
    Midia* rtn;
    rtn=malloc(sizeof(Midia));
    rtn->funcaoImprime=print_fn;
    rtn->funcaoLibera=free_fn;
    rtn->dado=dado;
    return rtn;
}

// Chama a função de impressão associada à mídia, exibindo seus dados.
// Parâmetros:
//  m - Ponteiro para a Midia a ser impressa.
void midia_print(Midia* m){
    m->funcaoImprime(m->dado);
}

// Chama a função de desalocação associada à mídia, liberando os dados alocados.
// Parâmetros:
//  m - Ponteiro para a Midia a ser destruída.
void midia_destroy(Midia* m){
    m->funcaoLibera(m->dado);
    free(m);
}