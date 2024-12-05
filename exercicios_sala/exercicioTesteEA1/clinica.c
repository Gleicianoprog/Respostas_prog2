#include"clinica.h"
#include<stdio.h>
void imprimeMediaIdade(tClinica c){
    int i=0,soma=0;
    for(i;i<c.qtdPacientes;i++){
        soma+=idadePaciente(c.pacientes[i]);
    };
    soma=soma/c.qtdPacientes;
    printf("%d\n",soma);
}
tClinica adicionaPacienteClinica(tClinica c,tPaciente p){
    c.pacientes[c.qtdPacientes]=p;
    c.qtdPacientes++;
    return c;
}
tClinica inicializaClinica(){
    tClinica rtn;
    rtn.qtdPacientes=0;
    rtn.qtdCirurgias=0;
    rtn.qtdLesoes=0;
    return rtn;
}
void imprimeClinica(tClinica c){
    int i=0;
    printf("TOTAL PACIENTES: %d\n",c.qtdPacientes);
    printf("MEDIA IDADE (ANOS): ");
    imprimeMediaIdade(c);
    printf("TOTAL LESOES: %d\n",c.qtdLesoes);
    printf("TOTAL CIRURGIAS: %d\n",c.qtdCirurgias);
    printf("LISTA PACIENTES: \n");
    for(i;i<c.qtdPacientes;i++){
        imprimePaciente(c.pacientes[i]);
        imprimeIdLesoes(c.pacientes[i]);
    }
}
tClinica somaLesoes(tClinica c){
    int i=0,qtdLesoes=0;
    for(i;i<c.qtdPacientes;i++){
        qtdLesoes+=qtdLesao(c.pacientes[i]);
    }
    c.qtdLesoes=qtdLesoes;
    return c;
}