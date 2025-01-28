#include"aluno.h"
#include<stdlib.h>
#include<stdio.h>
struct Aluno{
    char *nome;
    int matricula;
    int n1,n2,n3;
    int media;
};
tAluno* CriaAluno(){
    tAluno *rtn;
    rtn=malloc(sizeof(struct Aluno));
    rtn->nome=NULL;
    rtn->matricula=-1;
    rtn->n1=-1;
    rtn->n2=-1;
    rtn->n3=-1;
    rtn->media=-1;
    return rtn;
}
void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    free(aluno);
}
void LeAluno(tAluno *aluno){
    char c;
    int tam=0,matricula=0,n1=0,n2=0,n3=0;
    aluno->nome=malloc(sizeof(char));
    while (1){
        scanf("%c",&c);
        if(c=='\n'){
            break;
        }
        aluno->nome[tam]=c;
        tam++;
        aluno->nome=realloc(aluno->nome,sizeof(char));
    }
    aluno->nome[tam]='\0';
    scanf("%d\n",&matricula);
    scanf("%d %d %d\n",&n1,&n2,&n3);
    aluno->n1=n1;
    aluno->n2=n2;
    aluno->n3=n3;
    aluno->matricula=matricula;
    CalculaMediaAluno(aluno);
}
void ImprimeAluno(tAluno* aluno){
    printf("%s\n",aluno->nome);
    // printf("%d %d %d\n",aluno->n1,aluno->n2,aluno->n3);
    // printf("%d\n",aluno->matricula);
}
int VerificaAprovacao(tAluno* aluno){
    if((aluno->media)>=7){
        return 1;
    }
    return 0;
}
int CalculaMediaAluno(tAluno* aluno){
    float media;
    media=((aluno->n1)+(aluno->n2)+(aluno->n3));
    media/=3;
    aluno->media=media;
    return media;
}
int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if((aluno1->matricula)>(aluno2->matricula)){
        return 1;
    }
    return -1;
}