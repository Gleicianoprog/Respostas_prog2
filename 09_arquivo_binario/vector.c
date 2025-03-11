#include"vector.h"
#include<stdlib.h>
#include<stdio.h>
#include"produto.h"
struct Vector
{
    int qtd;
    DataType* dados;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector* rtn;
    rtn=malloc(sizeof(Vector));
    rtn->dados=malloc(0);
    rtn->qtd=0;
    return rtn;
}

/**
 * @brief Adiciona um elemento no final do vetooid*
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    v->qtd++;
    v->dados=realloc(v->dados,sizeof(DataType)*v->qtd);
    // v->dados[v->qtd]=;DataType
    v->dados[(v->qtd)-1]=val;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->dados[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){
    return v->qtd;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    for (int i = 0; i < v->qtd; i++)
    {
        destroy(v->dados[i]);
    }
    free(v->dados);
    free(v);
}