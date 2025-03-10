//#define MAXTAM_STRINGS 100
#include"livro.h"
#include<stdio.h>
#include<stdlib.h>
//typedef struct Livro Livro;
struct Livro
{
    char titulo[MAXTAM_STRINGS];
    char autor[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
    char editora[MAXTAM_STRINGS];
    int ano;
};

// Aloca dinamicamente uma nova estrutura Livro e realiza a leitura dos dados
// de entrada associados ao livro. Retorna o ponteiro para o objeto Livro.
// Retorna: Ponteiro para o Livro recém-criado, com os dados carregados.
Livro* livro_construct(){
    Livro* rtn;
    rtn=malloc(sizeof(Livro));
    scanf("%s %s %s\n%s %d\n",rtn->titulo,rtn->autor,rtn->genero,rtn->editora,&rtn->ano);
    return rtn;
}
// Imprime os dados do livro. Recebe um ponteiro genérico para o livro
// e exibe suas informações relevantes, como título, autor, etc.
// Parâmetros:
//  l - Ponteiro para o Livro a ser impresso.
void livro_print(void* l){
    Livro* livro;
    livro=(Livro*)l;
    printf("LIVRO\n");
    printf("Titulo: %s\nAutor: %s\nGenero: %s\nEditora: %s\nAno: %d\n",livro->titulo,livro->autor,livro->genero,livro->editora,livro->ano);
}

// Libera a memória alocada para o livro, desalocando a estrutura Livro
// e seus dados associados de forma adequada.
// Parâmetros:
//  l - Ponteiro para o Livro a ser destruído.
void livro_destroy(void* l){
    free(l);
}
