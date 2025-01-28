#include<stdio.h>
#include"aluno.h"
int main(){
    int tam,i=0,j=0;
    scanf("%d\n",&tam);
    tAluno *alunos[tam],*aux;
    while (i<tam){
        alunos[i]=CriaAluno(alunos[i]);
        LeAluno(alunos[i]);
        i++;
    }
    for ( i = 0; i < tam; i++){
        for ( j = i+1; j < tam; j++){
            if(ComparaMatricula(alunos[i],alunos[j])==1){
                aux=alunos[j];
                alunos[j]=alunos[i];
                alunos[i]=aux;
            }
        }
        
    }
    for ( i = 0; i < tam; i++){
        if(VerificaAprovacao(alunos[i])==1){
            ImprimeAluno(alunos[i]);
        }
    }
    for ( i = 0; i < tam; i++){
        ApagaAluno(alunos[i]);
    }
    return 0;
}