#include"filme.h"
#include<stdio.h>
#include<string.h>
tFilme criarFilme (char* nome, int codigo, int valor, int quantidade){
    tFilme rtn;
    int i=0;
    while(nome[i]){
        rtn.nome[i]=nome[i];
        i++;
    }
    rtn.nome[i]='\0';
    rtn.codigo=codigo;
    rtn.valor=valor;
    rtn.qtdEstoque=quantidade;
    rtn.qtdAlugada=0;
    return rtn;
}
int obterCodigoFilme (tFilme filme){
    return filme.codigo;
}
void imprimirNomeFilme (tFilme filme){
    printf("%s",filme.nome);
}
int obterValorFilme (tFilme filme){
    return filme.valor;
}
int obterQtdEstoqueFilme (tFilme filme){
    return filme.qtdEstoque;
}
int obterQtdAlugadaFilme (tFilme filme){
    return filme.qtdAlugada;
}
int ehMesmoCodigoFilme (tFilme filme, int codigo){
    return (filme.codigo==codigo)?1:0;
}
tFilme alugarFilme (tFilme filme){
    filme.qtdEstoque--;
    filme.qtdAlugada++;
    return filme;
}
tFilme devolverFilme (tFilme filme){
    filme.qtdEstoque++;
    filme.qtdAlugada--;
    return filme;
}
int compararNomesFilmes (tFilme filme1, tFilme filme2){
    return strcmp(filme1.nome,filme2.nome);
}
tFilme leFilme(int codigo){
    tFilme rtn;
    rtn.codigo=codigo;
    scanf("%*[\n]");
    scanf("%[^,],%d,%d\n",rtn.nome,&rtn.valor,&rtn.qtdEstoque);
    rtn.qtdAlugada=0;
    return rtn;
}