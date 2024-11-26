#include"locadora.h"
#include"filme.h"
#include<stdio.h>
#include<string.h>
int main(){
    char op[30];
    tLocadora locadora;
    // locadora=lerCadastroLocadora(locadora);
    locadora=criarLocadora ();
    // locadora=lerAluguelLocadora(locadora);
    while(scanf("%s",op)){
        if(!strcmp("Cadastrar",op)){
            locadora=lerCadastroLocadora(locadora);
            printf("\n");
            continue;
        }else if(!strcmp("Estoque",op)){
            locadora=ordenarFilmesLocadora (locadora);
            consultarEstoqueLocadora (locadora);
            scanf("%s",op);
            printf("\n");
            continue;
        }else if(!strcmp("Alugar",op)){
            locadora=lerAluguelLocadora (locadora);
            printf("\n");
            continue;
        }else if(!strcmp("Devolver",op)){
            locadora=lerDevolucaoLocadora(locadora);
            printf("\n");
            continue;
        }else{
            break;
        }
    }
    consultarLucroLocadora(locadora);
    return 0;
}