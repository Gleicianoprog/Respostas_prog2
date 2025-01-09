#include <stdio.h> 
#include "evento.h"
void cadastrarEvento(Evento* eventos, int* numEventos){
    Evento evento;
    scanf("%*c");
    if(*numEventos<MAX_EVENTOS-1){
        scanf("%[^\n]",evento.nome);
        scanf("%*[\n]");
        scanf("%d %d %d",&evento.dia,&evento.mes,&evento.ano);
        eventos[*numEventos]=evento;
        *numEventos=(*numEventos)+1;
        printf("Evento cadastrado com sucesso!\n");
    }else{
        printf("Limite de eventos atingido!\n");
    }
}
void exibirEventos(Evento* eventos, int* numEventos){
    if(*numEventos==0){
        printf("Nenhum evento cadastrado.\n");
    }else{
        printf("Eventos cadastrados:\n");
    }
    for (int i = 0; i < *numEventos; i++){
        printf("%d - %s - %d/%d/%d\n",i,eventos[i].nome,eventos[i].dia,eventos[i].mes,eventos[i].ano);
    }
}
void trocarDataEvento(Evento* eventos, int* numEventos){
    int indice;
    Evento evento;
    while(1){
        scanf("%d\n",&indice);
        if((indice>=0)&&(indice<*numEventos)){
            break;
        }else{
            printf("Indice invalido!\n");
            if(*numEventos==0){
                break;
            }
        }
    }
    if(*numEventos>0){
        evento=eventos[indice];
        scanf("%d %d %d\n",&evento.dia,&evento.mes,&evento.ano);
        eventos[indice]=evento;
        printf("Data modificada com sucesso!\n");
    }
}
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    Evento aux;
    if((*indiceA>=0)&&(*indiceA<*numEventos)&&(*indiceB>=0)&&(*indiceB<*numEventos)){
        aux=eventos[*indiceA];
        eventos[*indiceA]=eventos[*indiceB];
        eventos[*indiceB]=aux;
        printf("Eventos trocados com sucesso!\n");
    }else{
        printf("Indices invalidos!\n");
    }
}