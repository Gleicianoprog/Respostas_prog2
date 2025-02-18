#include"usuario.h"
#include<stdio.h>
#include<stdlib.h>
struct Usuario{
    char nome[100];
    char cpf[100];
    //int conta;
};
tUsuario *CriaUsuario(){
    tUsuario *rtn;
    rtn=malloc(sizeof(struct Usuario));
    //rtn->nome=malloc(sizeof(char)*100);
    return rtn;
}
void DestroiUsuario(tUsuario *user){
    free(user);
}
void LeUsuario(tUsuario *user){
    scanf("%s %s ",user->nome,user->cpf);
    //printf("%d",user->conta);
}
void ImprimeUsuario(tUsuario *user){
    printf("Nome: %s\n",user->nome);
    printf("CPF: %s\n\n",user->cpf);
}
