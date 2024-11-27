#include"aluno.h"
#include<stdio.h>
tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3){
    tAluno rtn;
    sprintf(rtn.nome,"%s",nome);
    rtn.matricula=matricula;
    rtn.n1=n1;
    rtn.n2=n2;
    rtn.n3=n3;
    return rtn;
}
tAluno LeAluno(){
    char nome[50];
    int matricula=0,n1=0,n2=0,n3=0;
    tAluno rtn;
    scanf("%s",nome);
    scanf("%d",&matricula);
    scanf("%d %d %d",&n1,&n2,&n3);
    scanf("%*c");
    rtn=CriaAluno(nome,matricula,n1,n2,n3);
    return rtn;
}
int ComparaMatricula(tAluno aluno1, tAluno aluno2){
    if(aluno1.matricula>aluno2.matricula){
        return 1;
    }else if(aluno1.matricula<aluno2.matricula){
        return -1;
    }else{
        return 0;
    }
}
int CalculaMediaAluno(tAluno aluno){
    return (aluno.n1+aluno.n2+aluno.n3)/3;
}
int VerificaAprovacao(tAluno aluno){
    if(CalculaMediaAluno(aluno)>=7){
        return 1;
    }else{
        return 0;
    }
}
void ImprimeAluno(tAluno aluno){
    printf("%s\n",aluno.nome);
}
