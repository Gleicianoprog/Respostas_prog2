#include"locadora.h"
#include"filme.h"
#include<stdio.h>
#include<string.h>
int main(){
    char op[30];
    int primeiro=1;
    tLocadora locadora;
    // locadora=lerCadastroLocadora(locadora);
    locadora=criarLocadora ();
    // locadora=lerAluguelLocadora(locadora);
    while(scanf("%s",op)){
        if(!strcmp("Cadastrar",op)){
            locadora=lerCadastroLocadora(locadora);
        }else if(!strcmp("Estoque",op)){
            locadora=ordenarFilmesLocadora (locadora);
            consultarEstoqueLocadora (locadora);
            scanf("%s",op);
        }else if(!strcmp("Alugar",op)){
            locadora=lerAluguelLocadora (locadora);
        }else if(!strcmp("Devolver",op)){
            locadora=lerDevolucaoLocadora(locadora);
        }else{
            break;
        }
        printf("\n");
    }
    consultarLucroLocadora(locadora);
    return 0;
}