#include"agendatarefas.h"
#include"tarefaimprime.h"
#include"tarefamultiplica.h"
#include"tarefasoma.h"
#include<stdlib.h>
#include<stdio.h>
typedef void (*fptr_exec)(void*);
typedef void (*fptr_destroi)(void*);
struct agendatarefas
{
    void **tarefas;
    int* prioridades;
    int numElem;
    int numMax;
    fptr_exec *funcoesExec;
    fptr_destroi *funcoesdestroi;
};
/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */

tAgendaTarefas* CriaAgendaDeTarefas(int numElem){
    tAgendaTarefas* rtn;
    rtn=malloc(sizeof(tAgendaTarefas));
    rtn->numElem=0;
    rtn->tarefas=malloc(sizeof(void*)*numElem);
    rtn->prioridades=malloc(numElem*sizeof(int));
    rtn->funcoesExec=malloc(sizeof(fptr_exec)*numElem);
    rtn->funcoesdestroi=malloc(sizeof(fptr_destroi)*numElem);
    // rtn->tipos=
    rtn->numMax=numElem;
    return rtn;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar){
    for (int i = 0; i < tar->numElem; i++){
        tar->funcoesdestroi[i](tar->tarefas[i]);
    }
    free(tar->prioridades);
    free(tar->funcoesdestroi);
    free(tar->funcoesExec);
    free(tar->tarefas);
    free(tar);
    
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){
    if(tar->numElem<tar->numMax){
        tar->tarefas[tar->numElem]=tarefa;
        tar->funcoesExec[tar->numElem]=executa;
        tar->funcoesdestroi[tar->numElem]=destroi;
        tar->prioridades[tar->numElem]=prioridade;
        (tar->numElem)++;
    }
} 

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void OrdenaTarefas(tAgendaTarefas *tar) {
    for (int j=0; j<tar->numElem; j++) {
        for (int i=0; i<tar->numElem-1; i++) {
            if (tar->prioridades[i] < tar->prioridades[i+1]) {
                //Trocar as coisas...
                int prioridadeAux;
                prioridadeAux = tar->prioridades[i];
                tar->prioridades[i] = tar->prioridades[i+1];
                tar->prioridades[i+1] = prioridadeAux;
                void *tarefaAux;
                tarefaAux = tar->tarefas[i];
                tar->tarefas[i] = tar->tarefas[i+1];
                tar->tarefas[i+1] = tarefaAux;
                void (*cb_dest_aux)(void*);
                cb_dest_aux = tar->funcoesdestroi[i];
                tar->funcoesdestroi[i] = tar->funcoesdestroi[i+1];
                tar->funcoesdestroi[i+1] = cb_dest_aux;
                void (*cb_exec_aux)(void*);
                cb_exec_aux = tar->funcoesExec[i];
                tar->funcoesExec[i] = tar->funcoesExec[i+1];
                tar->funcoesExec[i+1] = cb_exec_aux;
            }
        }
    }
}
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){
    OrdenaTarefas(tar);
    for(int i=0;i<tar->numElem;i++){
        tar->funcoesExec[i](tar->tarefas[i]);
    }
}
