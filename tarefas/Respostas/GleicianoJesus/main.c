#include"agendatarefas.h"
#include"tarefaimprime.h"
#include"tarefamultiplica.h"
#include"tarefasoma.h"
int main(){
    tAgendaTarefas *tarefas;
    void * tarefa;
    int qtd,prioridade;
    char tipo,msg[600];
    float n1,n2;
    printf("Digite o numero de tarefas:\n");
    scanf("%d\n",&qtd);
    tarefas=CriaAgendaDeTarefas(qtd);
    for (int i = 0; i < qtd; i++){
        scanf("%d %c ",&prioridade,&tipo);
        if(tipo=='I'){
            scanf("%[^\n]\n",msg);
            tarefa=CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(tarefas,prioridade,tarefa,ExecutaTarefaImprimir,DestroiTarefaImprimir);
        }else if(tipo=='M'){
            scanf("%f %f\n",&n1,&n2);
            tarefa=CriaTarefaMultiplicar(n1,n2);
            CadastraTarefaNaAgenda(tarefas,prioridade,tarefa,ExecutaTarefaMultiplicar,DestroiTarefaMultiplicar);
        }else if(tipo=='S'){
            scanf("%f %f\n",&n1,&n2);
            tarefa=CriaTarefaSoma(n1,n2);
            CadastraTarefaNaAgenda(tarefas,prioridade,tarefa,ExecutaTarefaSoma,DestroiTarefaSoma);
        }else{
            printf("Digite um tipo de tarefa suportado (I/S/M))\n");
            scanf("%*[^\n]\n");
            i--;
        }
    }
    ExecutarTarefasDaAgenda(tarefas);
    DestroiAgendaDeTarefas(tarefas);
    return 0;
}