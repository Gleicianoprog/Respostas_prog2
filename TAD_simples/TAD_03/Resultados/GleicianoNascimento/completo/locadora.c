#include"locadora.h"
#include"filme.h"
#include<stdio.h>
tLocadora criarLocadora (){
    tLocadora rtn;
    rtn.numFilmes=0;
    rtn.lucro=0;
    return rtn;
}
int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    int i=0;
    for ( i = 0; i < locadora.numFilmes; i++){
        if(ehMesmoCodigoFilme (locadora.filme[i],codigo)){
            return 1;
        }
    }
    return 0;
}
tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
    if(!verificarFilmeCadastrado(locadora,obterCodigoFilme(filme))){
        printf("Filme cadastrado %d - ",obterCodigoFilme(filme));
        locadora.filme[locadora.numFilmes]=filme;
        imprimirNomeFilme(locadora.filme[locadora.numFilmes]);
        printf("\n");
        locadora.numFilmes++;
    }else{
        printf("Filme ja cadastrado no estoque\n");
    }
    return locadora;
}
tLocadora ordenarFilmesLocadora (tLocadora locadora){
    int i=0,j=0;
    tFilme filme;
    filme=locadora.filme[0];
    for ( i = 0; i < locadora.numFilmes; i++){
        for ( j = i+1; j < locadora.numFilmes; j++){
            if(compararNomesFilmes(locadora.filme[j],locadora.filme[i])<0){
                filme=locadora.filme[i];
                locadora.filme[i]=locadora.filme[j];
                locadora.filme[j]=filme;
            }
        }
    }
    return locadora;
}
void consultarLucroLocadora (tLocadora locadora){
    if(locadora.lucro){
        printf("Lucro total R$%d\n",locadora.lucro);
    }
}
void consultarEstoqueLocadora (tLocadora locadora){
    int i=0;
    printf("~ESTOQUE~\n");
    for ( i = 0; i < locadora.numFilmes; i++){
        printf("%d - ",obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n",obterQtdEstoqueFilme(locadora.filme[i]));
    }
}
tLocadora lerCadastroLocadora (tLocadora locadora){
    int i=0,codigo=0;
    while (scanf("%d,",&codigo)){
        locadora=cadastrarFilmeLocadora(locadora,leFilme(codigo));
    }
    scanf("%*c");
    return locadora;
}
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i=0,j=0,total=0,qtdAlugados=quantidadeCodigos;
    for ( i = 0; i < quantidadeCodigos; i++){
        for ( j = 0; j < locadora.numFilmes ; j++){
            if(ehMesmoCodigoFilme (locadora.filme[j],codigos[i])){
                if(!obterQtdEstoqueFilme(locadora.filme[j])){
                    printf("Filme %d - ",obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    qtdAlugados--;
                }else{
                    locadora.filme[j]=alugarFilme(locadora.filme[j]);
                    // locadora.lucro+=obterValorFilme(locadora.filme[j]);
                    total+=obterValorFilme(locadora.filme[j]);
                }
            }
        }
    }
    if(qtdAlugados){
        printf("Total de filmes alugados: %d com custo de R$%d\n",qtdAlugados,total);
    }
    return locadora;
}
tLocadora lerAluguelLocadora (tLocadora locadora){
    int qtdCodigos=0,codigos[100],valorTotal=0,codigo=0;
    while(scanf("%d",&codigo)){
        if(verificarFilmeCadastrado(locadora,codigo)){
            codigos[qtdCodigos]=codigo;
            qtdCodigos++;
        }else{
            printf("Filme %d nao cadastrado.\n",codigo);
            continue;
        }
    }
    scanf("%*c");
    locadora=alugarFilmesLocadora(locadora,codigos, qtdCodigos);
    return locadora;
}
tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i=0,j=0,cod=0;
    for ( i = 0; i < quantidadeCodigos; i++){
        for ( j = 0; j < locadora.numFilmes ; j++){
            if(ehMesmoCodigoFilme (locadora.filme[j],codigos[i])){
                if(obterQtdAlugadaFilme(locadora.filme[j])){
                    locadora.filme[j]=devolverFilme(locadora.filme[j]);
                    printf("Filme %d - ",obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" Devolvido!\n");
                    locadora.lucro+=obterValorFilme(locadora.filme[j]);
                }else{
                    printf("Nao e possivel devolver o filme %d - ",obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(".\n");
                }
            }
        }
    }
    return locadora;
}
tLocadora lerDevolucaoLocadora (tLocadora locadora){
    int qtdCodigos=0,codigos[100],i=0,codigo=0;
    while(scanf("%d",&codigo)){
        if(verificarFilmeCadastrado(locadora,codigo)){
            codigos[qtdCodigos]=codigo;
            qtdCodigos++;
        }else{
            printf("Filme %d nao cadastrado.\n",codigo);
        }
    }
    scanf("%*c");
    locadora=devolverFilmesLocadora(locadora,codigos, qtdCodigos);
    return locadora;
}