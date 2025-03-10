#include"tadgen.h"
#include<stdio.h>
#include<stdlib.h>
struct generic{
    void* nums;
    int tam;
    int tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric* rtn;
    rtn=malloc(sizeof(tGeneric));
    if(type==INT){
        rtn->nums=(int*)malloc(sizeof(int)*numElem);
    }else{
        rtn->nums=(float*)malloc(sizeof(float)*numElem);
    }
    rtn->tipo=type;
    rtn->tam=numElem;
    return rtn;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    free(gen->nums);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    printf("\n");
    printf("Digite o vetor:\n");
    if(gen->tipo==INT){
        //generico=(int*)gen->nums;
        for (int i = 0; i < gen->tam; i++){
            scanf("%d",&((int*)gen->nums)[i]);
        }
    }else{
        for (int i = 0; i < gen->tam; i++){
            scanf("%f",&((float*)gen->nums)[i]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    int* generico;
    if(gen->tipo==INT){
        //generico=(int*)gen->nums;
        for (int i = 0; i < gen->tam; i++){
            printf("%d ",((int*)gen->nums)[i]);
        }
    }else{
        for (int i = 0; i < gen->tam; i++){
            printf("%.2f ",((float*)gen->nums)[i]);
        }
    }
}
