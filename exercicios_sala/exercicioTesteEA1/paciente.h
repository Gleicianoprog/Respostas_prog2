#ifndef PACIENTE_T
#define PACIENTE_T
#include"data.h"
#include"lesao.h"
typedef struct{
    char nome[101];
    tData data;
    char cartao[19];
    tLesao lesoes[10];
    int qtdLesao;
    char genero;
    int idade;
}tPaciente;
tPaciente lePaciente();
void imprimePaciente(tPaciente p);
tPaciente adicionaLesaoPaciente(tLesao l,tPaciente p);
tPaciente vinculaLesao(tLesao l,tPaciente p);
int ehMesmoCartao(char cartao[19],tPaciente p);
int idadePaciente(tPaciente c);
int qtdLesao(tPaciente p);
void imprimeIdLesoes(tPaciente p);
#endif