#include<stdio.h>
#include"aluno.h"
#include<stdlib.h>
int main(){
    Aluno** a;
    int qtd;
    printf("Digite o numero de alunos: ");
    scanf("%d",&qtd);
    a=CriaVetorAlunos(qtd);
    LeAlunos(a,qtd);
    SalvaAlunosBinario(a,"./alunos.bin",qtd);
    LiberaAlunos(a,qtd);
    a=CriaVetorAlunos(qtd);
    CarregaAlunosBinario(a,"./alunos.bin");
    ImprimeAlunos(a, qtd);
    LiberaAlunos(a,qtd);
    return 0;
}