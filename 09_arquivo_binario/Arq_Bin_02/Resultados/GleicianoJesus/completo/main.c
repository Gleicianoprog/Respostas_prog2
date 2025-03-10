#include"base_alunos.h"
#include<stdio.h>
#include"aluno.h"
int main(){
    char nome[1000];
    float media;
    tBaseAlunos* base;
    scanf("%[^\n]\n",nome);
    base=CriarBaseAlunos();
    LerBaseAlunos(base,nome);
    media=GetCoeficienteRendimentoMedioBaseAlunos(base);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f",media);
    DestruirBaseAlunos(base);
    return 0;
}