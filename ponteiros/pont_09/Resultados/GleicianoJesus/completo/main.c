#include<stdio.h>
#include"pessoa.h"
int main(){
    int qtd=0;
    scanf("%d",&qtd);
    tPessoa pessoas[qtd],pessoa;
    for ( int i = 0; i < qtd; i++){
        pessoa=CriaPessoa();
        LePessoa(&pessoa);
        pessoas[i]=pessoa;
    }
    AssociaFamiliasGruposPessoas(pessoas);
    for ( int i = 0; i < qtd; i++){
        ImprimePessoa(&pessoas[i]);
    }
    return 0;
}