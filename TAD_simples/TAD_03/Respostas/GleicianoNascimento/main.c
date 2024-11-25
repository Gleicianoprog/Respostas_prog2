#include"locadora.h"
#include"filme.h"
#include<stdio.h>
#include<string.h>
int main(){
    char op[30];
    tLocadora locadora;
    // locadora=lerCadastroLocadora(locadora);
    // locadora=lerAluguelLocadora(locadora);
    while (scanf("%s\n",op)){
        if(!strcmp("Cadastrar",op)){
            locadora=lerCadastroLocadora(locadora);
        }else if(!strcmp("Estoque",op)){
            locadora=ordenarFilmesLocadora (locadora);
            consultarEstoqueLocadora (locadora);
        }else{
            break;
        }
    }
    return 0;
}