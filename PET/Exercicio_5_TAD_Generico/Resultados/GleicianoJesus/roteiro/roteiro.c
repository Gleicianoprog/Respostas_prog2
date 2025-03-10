#include "midia.h"
#include"roteiro.h"
#include"musica.h"
#include"pintura.h"
#include<stdio.h>
#include"livro.h"
#include<stdlib.h>
// typedef struct Roteiro Roteiro;
struct Roteiro
{
    Midia **midias;
    int qtd;
};

// Aloca dinamicamente um novo objeto Roteiro e retorna o ponteiro para ele.
// Retorna: Ponteiro para o Roteiro recém-criado.
Roteiro *roteiro_construct(){
    Roteiro* rtn;
    //Midia* midiaAtual;
    rtn=malloc(sizeof(Roteiro));
    rtn->qtd=0;
    rtn->midias=malloc(0);
    return rtn;
}

// Aumenta o espaço de armazenamento de mídias no Roteiro, insere a nova mídia
// utilizando o construtor de mídia (midia_construct), e incrementa o contador de mídias.
// Parâmetros:
//  r       - Ponteiro para o Roteiro onde a mídia será inserida.
//  dado    - Ponteiro genérico contendo os dados da nova mídia a ser inserida.
//  print_fn - Função de impressão personalizada para a mídia.
//  free_fn  - Função de liberação personalizada para os recursos da mídia.
void roteiro_inserir_midia(Roteiro* r, void *dado, PrintFunction print_fn, FreeFunction free_fn){
    r->midias=realloc(r->midias,sizeof(Midia*)*(r->qtd+1));
    r->midias[r->qtd]=midia_construct(dado,print_fn,free_fn);
    r->qtd++;
}

// Imprime todas as mídias presentes no Roteiro. Se não houver mídias,
// imprime a mensagem "SEM MIDIAS PARA IMPRIMIR".
// Parâmetros:
//  r - Ponteiro para o Roteiro a ser impresso.
void roteiro_imprimir_midias(Roteiro *r){
    if(!(r->qtd)){
        printf("SEM MIDIAS PARA IMPRIMIR\n");
    }else{
        printf("IMPRIMINDO MIDIAS\n");
        for (int i = 0; i < r->qtd; i++){
            printf("MIDIA %d: ",(i+1));
            midia_print(r->midias[i]);
            printf("\n");
        }
    }
    
}

// Libera a memória alocada para o Roteiro e suas mídias, desalocando
// adequadamente cada um dos elementos armazenados.
// Parâmetros:
//  r - Ponteiro para o Roteiro a ser destruído.
void roteiro_destroy(Roteiro *r){
    for (int i = 0; i < r->qtd; i++){
        midia_destroy(r->midias[i]);
    }
    free(r->midias);
    free(r);
    
}