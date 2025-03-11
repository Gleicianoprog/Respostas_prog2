#include"produto.h"
#include<string.h>
#include<stdlib.h>
struct Produto{
    char nome[51];
    int codigo;
    float preco;
    int quantidade;
};
/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade){
    tProduto* rtn;
    rtn=malloc(sizeof(tProduto));
    rtn->codigo=codigo;
    rtn->preco=preco;
    rtn->quantidade=quantidade;
    strcpy(rtn->nome,nome);
    return rtn;
}

/**
 * @brief Função para destruir um produto.
 * @param produto Um ponteiro para o produto a ser destruído.
 */
void DestroiProduto(tProduto *produto){
    free(produto);
}

/**
 * @brief Função para ler um produto de um arquivo binário.
 * @param arquivo O arquivo de onde o produto será lido.
 * Formato do arquivo: 
 * Código (int) 
 * Nome (string) 
 * Preço (float) 
 * Quantidade (int).
 * @return Um ponteiro para o produto lido.
 */
tProduto *LeProduto(FILE *arquivo){
    tProduto* rtn;
    char nome[50];
    float preco;
    int codigo,estoque;
    fread(&codigo,sizeof(int),1,arquivo);
    fread(nome,sizeof(char),50,arquivo);
    fread(&preco,sizeof(float),1,arquivo);
    fread(&estoque,sizeof(int),1,arquivo);
    rtn=CriaProduto(codigo,nome,preco,estoque);
    return rtn;
}

/**
 * @brief Função para verificar se um produto tem estoque.
 * @param produto Um ponteiro para o produto.
 * @return 1 se o produto tem estoque, 0 caso contrário.
 */
int TemEstoqueProduto(tProduto *produto){
    if(produto->quantidade==0){
        return 0;
    }
    return 1;
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto){
    // código;nome;preço.
    printf("%d;%s;%.2f\n",produto->codigo,produto->nome,produto->preco);
}