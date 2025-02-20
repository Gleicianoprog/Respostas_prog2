#include<stdio.h>
#include<stdlib.h>
#include"conta.h"
#include"usuario.h"
void imprimeConta(Conta* conta){
    printf("Conta: %d\n",RecuperaNConta(conta));
    printf("Saldo: R$ %.2f\n",RecuperaSaldo(conta));
    printf("Nome: %s\n",RecuperaNomeUsuario(conta->usuario));
    printf("CPF: %d\n",RecuperaCpfUsuario(conta->usuario));
    printf("\n");
}
void ordenaTransacoes(Conta *conta,int qtd){
    float aux;
    for (int i = 0; i < (qtd/2); i++){
        aux=conta->movimentacoes[qtd-i-1];
        conta->movimentacoes[qtd-i-1]=conta->movimentacoes[i];
        conta->movimentacoes[i]=aux;
    }
}
void imprimeTrasancoes(Conta* conta,int qtd){
    for (int i = 0; i < qtd; i++){
        printf("%.2f\n",conta->movimentacoes[i]);
    }
    printf("\n");
}
int main(){
    int op=0,nConta2=0,nConta1=-1,qtdContas=0,cpf=-1,idx1=0,idx2=0,qtdTransacoes=0;
    char nome[100]="aaa";
    float valor;
    Conta **contas,*contaAtual,*outraConta;
    Usuario* user;
    contas=malloc(sizeof(Conta*)*100);
    
    while (1){
        scanf("%d",&op);
        scanf("%*[\n]");
        if(op==0){
            break;
        }else if(op==1){
            scanf("%d %f\n",&nConta1,&valor);
            if(contaAtual=BuscaConta(contas, qtdContas,nConta1)){
                valor=Saque(contaAtual,valor);
            }
        }else if(op==2){
            scanf("%d %f\n",&nConta1,&valor);
            if(contaAtual=BuscaConta(contas, qtdContas,nConta1)){
                Deposito(contaAtual,valor);
            }
        }else if(op==3){
            scanf("%d %d %f\n",&nConta1,&nConta2,&valor);
            contaAtual=BuscaConta(contas, qtdContas,nConta1);
            outraConta=BuscaConta(contas, qtdContas,nConta2);
            if(contaAtual&&outraConta){
                Transferencia(contaAtual,outraConta,valor);
            }
        }else if(op==4){
            scanf("%s %d %d\n",nome,&cpf,&nConta1);
            user=CriaUsuario(nome,cpf);
            contas[qtdContas]=CriaConta(user,nConta1);
            contas[qtdContas]->usuario=user;
            qtdContas++;
        }else if(op==5){
            printf("===| Imprimindo Relatorio |===\n");
            for (int i = 0; i < qtdContas; i++)
            {
                imprimeConta(contas[i]);
            }
            
        }else if(op==6){
            scanf("%d %d",&nConta1,&qtdTransacoes);
            printf("===| Imprimindo Extrato |===\n");
            contaAtual=BuscaConta(contas,qtdContas,nConta1);
            if(qtdTransacoes>contaAtual->qtdMovimentacoes){
                qtdTransacoes=contaAtual->qtdMovimentacoes;
            }
            imprimeConta(contaAtual);
            printf("Ultimas %d transações\n",qtdTransacoes);
            ordenaTransacoes(contaAtual,contaAtual->qtdMovimentacoes);
            imprimeTrasancoes(contaAtual,qtdTransacoes);
        }
    }
    for (int i = 0; i < qtdContas; i++)
    {
        DestroiUsuario(contas[i]->usuario);
        DestroiConta(contas[i]);
    }
    free(contas);
    return 0;
}