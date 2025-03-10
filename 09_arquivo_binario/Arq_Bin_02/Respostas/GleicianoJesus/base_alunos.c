#include"base_alunos.h"
#include"aluno.h"
#include<stdio.h>
#include<stdlib.h>
struct BaseAlunos
{
    int qtdMax;
    tAluno** alunos;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos(){
    tBaseAlunos *rtn;
    rtn=malloc(sizeof(tBaseAlunos));
    rtn->qtdMax=0;
    return rtn;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos){
    for (int i = 0; i < baseAlunos->qtdMax; i++)
    {
        free(baseAlunos->alunos[i]);
    }
    free(baseAlunos->alunos);
    free(baseAlunos);
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){
    FILE * fp;
    fp=fopen(nomeArquivo,"rb");
    fread(&(baseAlunos->qtdMax),sizeof(int),1,fp);
    // printf("%d",baseAlunos->qtdMax);
    baseAlunos->alunos=malloc(sizeof(tAluno*)*baseAlunos->qtdMax);
    for (int i = 0; i <baseAlunos->qtdMax; i++){
        baseAlunos->alunos[i]=LeAluno(fp);
    }
    fclose(fp);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){
    float soma=0;
    for (int i = 0; i < baseAlunos->qtdMax; i++){
        soma+=GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }
    soma/=(baseAlunos->qtdMax);
    return soma;
}
