#include"filme.h"
#include"locadora.h"
#include<stdio.h>
tLocadora criarLocadora (){
    tLocadora rtn;
    rtn.numFilmes=0;
    rtn.lucro=0;
    return rtn;
}
int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    for(int i=0;i<locadora.numFilmes;i++){
        if(obterCodigoFilme(locadora.filme[i])==codigo){
            return 1;
        }
    }
    return 0;
}
tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
    locadora.filme[locadora.numFilmes]=filme;
    locadora.numFilmes++;
    return locadora;
}
tLocadora lerCadastroLocadora (tLocadora locadora){
    int codigo;
    tFilme filmeAtual;
    while (1){
        scanf("%d",&codigo);
        if(codigo=='#'){
            scanf("%*[\n]");
            break;
        }
        scanf("%*[,]");
        filmeAtual=leFilme(codigo);
        locadora=cadastrarFilmeLocadora(locadora,filmeAtual);
    }
    return locadora;
}
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    for (int i = 0; i < quantidadeCodigos; i++){
        for ( int j = 0; j <locadora.numFilmes ; j++){
            if(ehMesmoCodigoFilme(locadora.filme[j],codigos[i])){
                locadora.filme[j]=alugarFilme(locadora.filme[j]);
            }
        }
    }
    return locadora;
}