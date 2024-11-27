#include<stdio.h>
#include"aluno.h"
int main(){
    int qtd,i=0,j=0,k=0;
    scanf("%d\n",&qtd);
    tAluno alunosAP[qtd],alunoAtual;
    while(qtd){
        alunoAtual=LeAluno();
        if(VerificaAprovacao(alunoAtual)){
            alunosAP[i]=alunoAtual;
            i++;
        }
        qtd--;
    }
    for(j;j<i;j++){
        for ( k=j+1 ; k < i; k++){
            if(ComparaMatricula(alunosAP[j],alunosAP[k])==1){
                alunoAtual=alunosAP[j];
                alunosAP[j]=alunosAP[k];
                alunosAP[k]=alunoAtual;
            }
        }
    }
    for ( j = 0; j < i; j++){
        ImprimeAluno(alunosAP[j]);
    }
    
    return 0;
}