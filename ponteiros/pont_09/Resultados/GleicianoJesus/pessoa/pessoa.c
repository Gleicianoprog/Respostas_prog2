#include"pessoa.h"
#include<stdio.h>
#include<stdlib.h>
tPessoa CriaPessoa(){
    tPessoa rtn;
    rtn.nome[0]='\0';
    rtn.mae=NULL;
    rtn.pai=NULL;
    return rtn;
}
void LePessoa(tPessoa *pessoa){
    scanf("%*[\n]");
    scanf("%[^\n]\n",pessoa->nome);
}
int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->pai||pessoa->mae){
        return 1;
    }
    return 0;
}
void ImprimePessoa(tPessoa *pessoa){
    tPessoa *p;
    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n",pessoa->nome);
        if(!(pessoa->pai)){
            printf("PAI: NAO INFORMADO\n");
        }else{
            p=pessoa->pai;
            printf("PAI: %s\n",p->nome);
        }
        if(!(pessoa->mae)){
            printf("MAE: NAO INFORMADO\n");
        }else{
            p=pessoa->mae;
            printf("MAE: %s\n",p->nome);
        }
        printf("\n");
    }
}
void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
    int qtd,indiceM=0,indiceP=0,indiceF=0;
    tPessoa *pMae,p,*pPai;
    //p=CriaPessoa();
    scanf("%d\n",&qtd);
    for ( int i = 0; i < qtd; i++){
        scanf("mae: %d, pai: %d, filho: %d\n",&indiceM,&indiceP,&indiceF);
        //printf("%d %d %d\n",indiceM,indiceP,indiceF);
        if(indiceM!=-1){
            pMae=&pessoas[indiceM];
            pessoas[indiceF].mae=pMae;
        }
        if(indiceP!=-1){
            pPai=&pessoas[indiceP];
            pessoas[indiceF].pai=pPai;
        }
    }
        // pMae=p;
        // pPai=p;
}