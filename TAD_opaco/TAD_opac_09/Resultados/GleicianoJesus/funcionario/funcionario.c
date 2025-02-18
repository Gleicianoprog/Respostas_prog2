#include"funcionario.h"
#include<stdio.h>
#include<stdlib.h>
struct funcionario
{
    int id;
    float salario;
};
tFuncionario* CriaFuncionario(){
    tFuncionario *rtn;
    rtn=malloc(sizeof(tFuncionario*));
    rtn->id=-1;
    rtn->salario=-1;
    return rtn;
}
void ApagaFuncionario(tFuncionario* funcionario){
    free(funcionario);
}
void LeFuncionario(tFuncionario* funcionario){
    scanf("%d %f",&funcionario->id,&funcionario->salario);
}
int GetIdFuncionario(tFuncionario* funcionario){
    return funcionario->id;
}
void ImprimeFuncionario(tFuncionario* funcionario){
    printf("- Funcionario %d: RS %.2f\n",funcionario->id,funcionario->salario);
}