#include"empresa.h"
#include"funcionario.h"
#include<stdio.h>
#include<stdlib.h>
struct empresa{
    int id;
    int qtd;
    tFuncionario **funcionarios;
};

tEmpresa* CriaEmpresa(){
    tEmpresa* rtn;
    rtn=malloc(sizeof(tEmpresa));
    rtn->id=-1;
    rtn->qtd=-1;
    //rtn->funcionarios=malloc(sizeof(tFuncionario*));
    // rtn->idx=0;
    rtn->funcionarios=NULL;
    return rtn;
}
void LeEmpresa(tEmpresa* empresa){
    int id,qtd;
    scanf("%d",&id);
    scanf("%d",&qtd);
    // scanf("%*c");
    tFuncionario *aux[qtd];
    empresa->id=id;
    empresa->qtd=0;
    // empresa->funcionarios=malloc(sizeof(tFuncionario*)*(qtd));
    for (int i = 0; i < qtd; i++){
        aux[i]=CriaFuncionario();
    }
    for (int i = 0; i < qtd; i++){
        LeFuncionario(aux[i]);
        ContrataFuncionarioEmpresa(empresa, aux[i]);
        // ApagaFuncionario(aux);
    }
}
void ApagaEmpresa(tEmpresa* empresa){
    for (int i = 0; i < empresa->qtd; i++){
        ApagaFuncionario(empresa->funcionarios[i]);
    }
    free(empresa->funcionarios);
    free(empresa);
}
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario){
    int contratado=0;
    for ( int i = 0; i < empresa->qtd; i++){
        if(GetIdFuncionario(empresa->funcionarios[i])==GetIdFuncionario(funcionario)){
            contratado=1;
        }
    }
    if(!contratado){
        empresa->qtd++;
        empresa->funcionarios=realloc(empresa->funcionarios,sizeof(tFuncionario*)*empresa->qtd);
        empresa->funcionarios[(empresa->qtd)-1]=funcionario;
    }else{
        printf("A empresa %d ja possui um funcionario com o id %d\n",empresa->id,GetIdFuncionario(funcionario));
        ApagaFuncionario(funcionario);
    }
}
void ImprimeEmpresa(tEmpresa *empresa){
    printf("Empresa %d:\n",empresa->id);
    // printf("%d",empresa->qtd);
    for (int i = 0; i < empresa->qtd; i++){
        ImprimeFuncionario(empresa->funcionarios[i]);
    }
}