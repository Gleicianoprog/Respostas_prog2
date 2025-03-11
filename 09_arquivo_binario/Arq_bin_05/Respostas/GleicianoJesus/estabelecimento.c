#include"estabelecimento.h"
#include"vector.h"
#include"produto.h"
struct Estabelecimento
{
    Vector * produtos;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento(){
    tEstabelecimento* rtn;
    rtn=malloc(sizeof(tEstabelecimento));
    rtn->produtos=VectorConstruct();
    return rtn;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento){
    VectorDestroy(estabelecimento->produtos,DestroiProduto);
    free(estabelecimento);
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto){
    VectorPushBack(estabelecimento->produtos,produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento){
    char arquivo[400];
    int qtd;
    scanf("%s\n",arquivo);
    FILE * fp;
    fp=fopen(arquivo,"r");
    fread(&qtd,sizeof(int),1,fp);
    for (int i = 0; i < qtd; i++)
    {
        AdicionaProdutoEstabelecimento(estabelecimento,LeProduto(fp));
    }
    fclose(fp);
}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento){
    void* p;
    int count=0,i=0;
    tProduto * pr;
    printf("Produtos em falta:\nCodigo;Nome;Preco\n");
    for (i = 0; i < VectorSize(estabelecimento->produtos);i++){
        p=VectorGet(estabelecimento->produtos,i);
        pr=(tProduto*)p;
        if(!TemEstoqueProduto(pr)){
            ImprimeProduto(pr);
            count--;
        }
        count++;
    }
    if(count==i){
        printf("Nao ha produtos em falta!\n");
    }
}