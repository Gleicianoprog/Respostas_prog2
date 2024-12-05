#ifndef _CLINICA_
#define _CLINICA_
#include"paciente.h"
typedef struct {
    int qtdPacientes;
    tPaciente pacientes[100];
    int qtdCirurgias;
    int mediaIdade;
    int qtdLesoes;
}tClinica;
void imprimeMediaIdade(tClinica c);
tClinica adicionaPacienteClinica(tClinica c,tPaciente p);
tClinica inicializaClinica();
tClinica somaLesoes(tClinica c);
void imprimeClinica();
#endif