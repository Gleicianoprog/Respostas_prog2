#include<stdio.h>
#include"pessoa.h"
int main(){
    int qtd;
    scanf("%d",&qtd);
    tPessoa pessoa,pessoas[qtd];
    for (int i = 0; i < qtd; i++){
        pessoa=CriaPessoa();
        LePessoa(&pessoa);
        pessoas[i]=pessoa;
    }
    AssociaFamiliasGruposPessoas(pessoas,qtd);
    for (int i = 0; i < qtd; i++){
        ImprimePessoa(&pessoas[i]);
    }
    return 0;
}