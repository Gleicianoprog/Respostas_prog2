#include<stdlib.h>
#include"funcionario.h"
#include<stdio.h>
#include"empresa.h"
int main(){
    int qtd;
    scanf("%d",&qtd);
    // scanf("%*c");
    // printf("%d",qtd);
    tEmpresa *empresas[qtd];
    for ( int i = 0; i < qtd; i++){
        empresas[i]=CriaEmpresa();
        LeEmpresa(empresas[i]);
    }
    for ( int i = 0; i < qtd; i++){
        // empresas[i]=CriaEmpresa();
        // LeEmpresa(empresas[i]);
        ImprimeEmpresa(empresas[i]);
        ApagaEmpresa(empresas[i]);
    }
    return 0;
}