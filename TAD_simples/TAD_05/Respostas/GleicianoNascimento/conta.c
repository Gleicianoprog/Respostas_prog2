#include"conta.h"
#include"usuario.h"
#include<stdio.h>
tConta CriaConta(int numero, tUsuario user){
    tConta rtn;
    rtn.numero=numero;
    rtn.user=user;
    rtn.saldo=0;
    return rtn;
}
void ImprimeConta(tConta conta){
    printf("Conta: %d\nSaldo: R$ %.2f\n",conta.numero,conta.saldo);
    ImprimeUsuario(conta.user);
}
int VerificaConta(tConta conta, int numero){
    return conta.numero==numero;
}
tConta SaqueConta(tConta conta, float valor){
    conta.saldo-=valor;
    return conta;
}
tConta DepositoConta(tConta conta, float valor){
    conta.saldo+=valor;
    return conta;
}