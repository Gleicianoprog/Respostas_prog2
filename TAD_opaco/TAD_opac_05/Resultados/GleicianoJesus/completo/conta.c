#include"conta.h"
#include"usuario.h"
#include<stdio.h>
#include<stdlib.h>
struct Conta
{
    tUsuario * user;
    int id;
    float saldo;
};
tConta *CriaConta(){
    tConta * rtn;
    rtn=malloc(sizeof(struct Conta));
    rtn->user=CriaUsuario();
    rtn->saldo=0;
    return rtn;
}
void DestroiConta(tConta *conta){
    DestroiUsuario(conta->user);
    free(conta);
}
void LeConta(tConta *conta){
    LeUsuario(conta->user);
    scanf("%d\n",&conta->id);
}
void ImprimeConta(tConta *conta){
    printf("Conta: %d\n",conta->id);
    printf("Saldo: R$ %.2f\n",conta->saldo);
    ImprimeUsuario(conta->user);
}
int VerificaConta(tConta *conta, int numero){
    return conta->id==numero;
}
void SaqueConta(tConta *conta, float valor){
    if(conta->saldo>=valor){
        conta->saldo=conta->saldo-valor;
    }
}
void DepositoConta(tConta *conta, float valor){
    conta->saldo=conta->saldo+valor;
}
void TransferenciaConta(tConta *destino, tConta *origem, float valor){
    if((origem->saldo)>=valor){
        SaqueConta(origem,valor);
        DepositoConta(destino,valor);
    }
}
