#include"aluno.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct aluno
{
    char* nome;
    char* data;
    char* curso;
    char* ingresso;
    int conclusao;
    float cr;
};

Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno** rtn;
    rtn=malloc(sizeof(Aluno*)*numeroAlunos);
    LeAlunos(rtn,numeroAlunos);
    return rtn;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno* rtn;
    rtn=malloc(sizeof(Aluno*));
    strcpy(rtn->nome,nome);
    strcpy(rtn->data,dtNasc);
    strcpy(rtn->curso,cursoUfes);
    strcpy(rtn->ingresso,periodoIngresso);
    rtn->conclusao=percConclusao;
    rtn->cr=CRA;
    return rtn;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    char c,nome[100],curso[100],data[100],ingresso[100];
    int tam=0,conclusao=0,j=0;
    float cr;
    for (int i = 0; i < numeroAlunos; i++){
        c='\0';
        j=0;
        tam=0;
        while (c!='\n'){
            scanf("%c",&c);
            nome[j]=c;
            tam++;
        }
        j=0;
        c='\0';
        vetorAlunos[i]->nome=malloc(sizeof(char)*tam);
        tam=0;
        while (c!='\n'){
            scanf("%c",&c);
            data[j]=c;
            tam++;
        }
        j=0;
        c='\0';
        vetorAlunos[i]->data=malloc(sizeof(char)*tam);
        tam=0;
        while (c!='\n'){
            scanf("%c",&c);
            curso[j]=c;
            tam++;
        }
        j=0;
        c='\0';
        vetorAlunos[i]->curso=malloc(sizeof(char)*tam);
        tam=0;
        while (c!='\n'){
            scanf("%c",&c);
            ingresso[j]=c;
            tam++;
        }
        vetorAlunos[i]->ingresso=malloc(sizeof(char)*tam);
        scanf("%d\n",&conclusao);
        scanf("%f\n",&cr);
        vetorAlunos[i]=CriaAluno(nome,data,curso,ingresso,conclusao,cr);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    for (int i = 0; i < numeroAlunos; i++)
    {
        free(alunos[i]->curso);
        free(alunos[i]->data);
        free(alunos[i]->ingresso);
        free(alunos[i]->nome);
        free(alunos[i]);
    }
    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    FILE* fp;
    int numB=0;
    fp=fopen(fileName,"a+b");
    for (int i = 0; i < numeroAlunos; i++)
    {
        numB+=fwrite(alunos[i],sizeof(Aluno*),1,fp);
        fputc('\0',fp);
    }
    printf("Numero de bytes salvos:%d\n",numB);
    fclose(fp);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    FILE* fp;
    fp=fopen(fileName,"rb");
    
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos);