#include"aluno.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct aluno
{
    char nome[100];
    char data[100];
    char curso[100];
    char ingresso[100];
    int conclusao;
    float cr;
};

Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno** rtn;
    rtn=malloc(sizeof(Aluno*)*numeroAlunos);
    // LeAlunos(rtn,numeroAlunos);
    return rtn;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno* rtn;
    rtn=malloc(sizeof(struct aluno));
    strcpy(rtn->nome,nome);
    strcpy(rtn->data,dtNasc);
    strcpy(rtn->curso,cursoUfes);
    strcpy(rtn->ingresso,periodoIngresso);
    rtn->conclusao=percConclusao;
    rtn->cr=CRA;
    return rtn;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    char nome[100]="",curso[100]="",data[100]="",ingresso[100]="";
    scanf("%*c");
    int i=0,conclusao=0;
    float cr;
    for (i = 0; i < numeroAlunos; i++){
        // scanf("%*[\n]");
        scanf("%[^\n]\n",nome);
        // printf("AA\n");
        scanf("%[^\n]\n",data);
        scanf("%[^\n]\n",curso);
        scanf("%[^\n]\n",ingresso);
        scanf("%d\n",&conclusao);
        scanf("%f\n",&cr);
        // printf("%f\n",cr);
        vetorAlunos[i]=CriaAluno(nome,data,curso,ingresso,conclusao,cr);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    for (int i = 0; i < numeroAlunos; i++)
    {
        free(alunos[i]);
    }
    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    FILE * fp;
    fp = fopen(fileName, "wb");
    int numB = 0,tam=0;
    // printf("%d\n",numeroAlunos);
    numB += sizeof(int)*fwrite(&numeroAlunos, sizeof(int), 1, fp);
    // printf("%s",alunos[1]->nome);
    for (int i = 0; i < numeroAlunos; i++)
    {
        tam=strlen(alunos[i]->nome);
        numB+=sizeof(int)*fwrite(&tam,sizeof(int),1,fp);

        numB+=fwrite(alunos[i]->nome,sizeof(char),tam,fp);

        tam=strlen(alunos[i]->data);
        numB+=sizeof(int)*fwrite(&tam,sizeof(int),1,fp);

        numB+=fwrite(alunos[i]->data,sizeof(char),tam,fp);

        tam=strlen(alunos[i]->curso);
        numB+=sizeof(int)*fwrite(&tam,sizeof(int),1,fp);

        numB+=fwrite(alunos[i]->curso,sizeof(char),tam,fp);

        tam=strlen(alunos[i]->ingresso);
        numB+=sizeof(int)*fwrite(&tam,sizeof(int),1,fp);

        numB+=fwrite(alunos[i]->ingresso,sizeof(char),tam,fp);

        numB+=sizeof(int)*fwrite(&alunos[i]->conclusao,sizeof(int),1,fp);
        numB+=sizeof(float)*fwrite(&alunos[i]->cr,sizeof(float),1,fp);
    }
    fclose(fp);
    printf("Numero de bytes salvos: %d\n", numB);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    FILE* fp;
    char nome[100]="",data[100]="",curso[100]="",ingresso[100]="";
    int qtdAlunos,tamString,conclusao;
    float cr;
    fp=fopen(fileName,"rb");
    fread(&qtdAlunos,sizeof(int),1,fp);
    for (int i = 0; i < qtdAlunos; i++){
        fread(&tamString,sizeof(int),1,fp);
        fread(nome,sizeof(char),tamString,fp);
        nome[tamString]='\0';
        fread(&tamString,sizeof(int),1,fp);
        fread(data,sizeof(char),tamString,fp);
        data[tamString]='\0';
        fread(&tamString,sizeof(int),1,fp);
        fread(curso,sizeof(char),tamString,fp);
        curso[tamString]='\0';
        fread(&tamString,sizeof(int),1,fp);
        fread(ingresso,sizeof(char),tamString,fp);
        ingresso[tamString]='\0';
        fread(&conclusao,sizeof(int),1,fp);
        fread(&cr,sizeof(float),1,fp);
        alunos[i]=CriaAluno(nome,data,curso,ingresso,conclusao,cr);
        // printf("%.2f\n",cr);
    }
    fclose(fp);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    for (int i = 0; i < numeroAlunos; i++)
    {
        printf("Aluno %d:\n",i);
        printf("Nome: %s\n",alunos[i]->nome);
        printf("Data Nascimento: %s\n",alunos[i]->data);
        printf("Curso: %s\n",alunos[i]->curso);
        printf("Periodo Ingresso: %s\n",alunos[i]->ingresso);
        printf("%% Conclusao do Curso: %d\n",alunos[i]->conclusao);
        printf("CRA: %.2f\n",alunos[i]->cr);
    }
}