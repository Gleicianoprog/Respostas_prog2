#include"conta.h"
#include"banco.h"
#include<stdio.h>
#include<stdlib.h>
struct Banco{
    tConta **contas;
    int idx;
};
tBanco *CriaBanco(){
    tBanco *rtn;
    rtn=malloc(sizeof(struct Banco));
    rtn->contas=malloc(sizeof(tConta*)*5);
    rtn->idx=0;
    return rtn;
}
void DestroiBanco(tBanco *banco){
    for (int i = 0; i < banco->idx; i++){
        DestroiConta(banco->contas[i]);
    }
    free(banco->contas);
    free(banco);
}
void AbreContaBanco(tBanco *banco){
    banco->contas[banco->idx]=CriaConta(banco->contas[banco->idx]);
    LeConta(banco->contas[banco->idx]);
    banco->idx=(banco->idx)+1;
}
void SaqueContaBanco(tBanco *banco){
    float valor;
    int id;
    scanf("%d %f\n",&id,&valor);
    for (int i = 0; i < banco->idx ; i++){
        if(VerificaConta(banco->contas[i],id)){
            SaqueConta(banco->contas[i],valor);
            break;
        }   
    }
}
void DepositoContaBanco(tBanco *banco){
    float valor;
    int id;
    scanf("%d %f\n",&id,&valor);
    for (int i = 0; i < banco->idx ; i++){
        if(VerificaConta(banco->contas[i],id)){
            DepositoConta(banco->contas[i],valor);
            break;
        }   
    }
}
void TransferenciaContaBanco(tBanco *banco){
    float valor;
    int id1,id2,i=0,j=0;
    scanf("%d %d %f\n",&id2,&id1,&valor);
    for (i = 0; i < banco->idx ; i++){
        if(VerificaConta(banco->contas[i],id1)){
            //DepositoConta(banco->contas[i],valor);
            break;
        }   
    }
    for (j = 0; j< banco->idx ; j++){
        if(VerificaConta(banco->contas[j],id2)){
            //DepositoConta(banco->contas[i],valor);
            break;
        }   
    }
    TransferenciaConta(banco->contas[j],banco->contas[i],valor);
}
void ImprimeRelatorioBanco(tBanco *banco){
    printf("===| Imprimindo Relatorio |===\n");
    for (int i = 0; i < banco->idx; i++){
        ImprimeConta(banco->contas[i]);
    }
}