#include"pacote.h"
#include"string.h"
#include<stdio.h>
#include<stdlib.h>
//typedef struct pacote tPacote;
struct pacote
{
    void *pacote;
    int soma;
    int tamanho;
    int tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){
    tPacote* rtn;
    rtn=malloc(sizeof(tPacote));
    rtn->tipo=type;
    rtn->tamanho=numElem;
    rtn->soma=0;
    if(type==CHAR){
        rtn->pacote=malloc(sizeof(char)*((rtn->tamanho)+1));
    }else if(type==INT){
        rtn->pacote=malloc(sizeof(int)*(rtn->tamanho));
    }
    return rtn;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){
    free(pac->pacote);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){
    int i=0;
    char c;
    // scanf("%*[\n]");
    printf("\nDigite o conteúdo do vetor/mensagem: ");
    if(pac->tipo==CHAR){
        scanf("%[^\n]\n",(char*)pac->pacote);
    }else if(pac->tipo==INT){
        for (int i = 0; i < pac->tamanho; i++){
            scanf("%d",&((int*)pac->pacote)[i]);
            scanf("%*c");
        }
    }
    CalculaSomaVerificacaoPacote(pac);
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){
    printf("%d ",(pac->soma));
    if(pac->tipo==CHAR){
        printf("%s",((char*)pac->pacote));
    }else{
        for (int i = 0; i < pac->tamanho; i++){
            printf("%d ",((int*)pac->pacote)[i]);
        }
    }
        printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){
    int soma=0;
    for (int i = 0; i < pac->tamanho; i++){
        if(pac->tipo==CHAR){
            soma+=((char*)pac->pacote)[i];
        }else if(pac->tipo==INT){
            soma+=((int*)pac->pacote)[i];
        }
    }
    pac->soma=soma;
}
