
#include <stdio.h>
#include"aluno.h"
#include<string.h>
#include<stdlib.h>
struct Aluno
{
    char nome[101];
    char data[12];
    char curso[51];
    float cr;
    int periodo;
};

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento){
    tAluno* rtn;
    rtn=malloc(sizeof(tAluno));
    strcpy(rtn->nome,nome);
    strcpy(rtn->data,dataNascimento);
    strcpy(rtn->curso,curso);
    rtn->cr=coeficienteRendimento;
    rtn->periodo=periodo;
    return rtn;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno){
    free(aluno);
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario) {
    tAluno* rtn;
    char nome[101];
    char data[12];
    char curso[51];
    int periodo;
    float cr;
    fread(nome, sizeof(char), 100, arquivo_binario);
    fread(data, sizeof(char), 11, arquivo_binario);
    fread(curso, sizeof(char), 50, arquivo_binario);
    fread(&periodo, sizeof(int), 1, arquivo_binario);
    fread(&cr, sizeof(float), 1, arquivo_binario);
    rtn = CriarAluno(nome, data, curso, periodo, cr);
    return rtn;
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno){
    return aluno->cr;
}
