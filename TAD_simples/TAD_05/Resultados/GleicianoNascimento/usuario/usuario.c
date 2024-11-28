#include"usuario.h"
#include<stdio.h>
tUsuario CriaUsuario(char nome[20], char cpf[15]){
    tUsuario rtn;
    sprintf(rtn.nome,"%s",nome);
    sprintf(rtn.cpf,"%s",cpf);
    return rtn;
}
void ImprimeUsuario(tUsuario user){
    printf("Nome: %s\nCPF: %s\n",user.nome,user.cpf);
}