#include<stdio.h>
#include"conta.h"
#include"usuario.h"
int main(){
    int qtdMax=0,op=0,i=0,qtdCadastrada=0,numero=0;
    float valor=0;
    char nome[20],cpf[15];
    tUsuario usuario;
    scanf("%d\n",&qtdMax);
    tConta contas[qtdMax];
    while (1){
        scanf("%d",&op);
        if(op==0){
            break;
        }else if(op==1){
            scanf("%d %f",&numero,&valor);
            for ( i = 0; i < qtdCadastrada; i++){
                if(VerificaConta(contas[i],numero)){
                    contas[i]=SaqueConta(contas[i],valor);
                }
            }
        }else if(op==2){
            scanf("%d %f",&numero,&valor);
            for ( i = 0; i < qtdCadastrada; i++){
                if(VerificaConta(contas[i],numero)){
                    contas[i]=DepositoConta(contas[i],valor);
                }
            }
        }else if(op==3){
            scanf("%s %s",nome,cpf);
            usuario=CriaUsuario(nome,cpf);
            scanf("%d",&numero);
            contas[qtdCadastrada]=CriaConta(numero,usuario);
            qtdCadastrada++;
        }else if(op==4){
            printf("===| Imprimindo Relatorio |===\n");
            for ( i = 0; i < qtdCadastrada; i++){
                ImprimeConta(contas[i]);   
                printf("\n");
            }
        }
    }
    
    return 0;
}