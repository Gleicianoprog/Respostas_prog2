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
        locadora.filme[locadora.numFilmes]=filme;
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
    printf("%d\n",locadora.lucro);
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
    locadora.numFilmes=0;
    locadora.lucro=0;
    while (scanf("%d,",&codigo)){
        locadora.filme[i]=leFilme(codigo);
        printf("Filme cadastrado %d - ",obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf("\n");
        locadora.numFilmes++;
        i++;
    }
    printf("\n");
    scanf("%*c");
    return locadora;
}
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i=0,j=0;
    for ( i = 0; i < quantidadeCodigos; i++){
        for ( j = 0; j < locadora.numFilmes ; j++){
            if(ehMesmoCodigoFilme (locadora.filme[j],codigos[i])){
                locadora.filme[j]=alugarFilme(locadora.filme[j]);
                locadora.lucro+=obterValorFilme(locadora.filme[j]);
            }
        }
    }
    return locadora;
}
tLocadora lerAluguelLocadora (tLocadora locadora){
    char codigo='0';
    int qtdCodigos=0,codigos[100];
    while(1){
        scanf("%c",&codigo);
        if(codigo=='#'){
            break;
        }else if(codigo=='\n'){
            continue;
        }
        if(verificarFilmeCadastrado(locadora,codigo)){
            codigos[qtdCodigos]=codigo;
            qtdCodigos++;
        }else{
            printf("filme nao encontrado\n");
        }
    }
    locadora=alugarFilmesLocadora(locadora,codigos, qtdCodigos);
    return locadora;
}
// tLocadora lerDevolucaoLocadora (tLocadora locadora){
//     return locadora;
// }