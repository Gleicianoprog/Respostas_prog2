#include"pessoa.h"
#include<stdio.h>
tPessoa CriaPessoa(){
    tPessoa rtn;
    rtn.nome[0]='\0';
    rtn.irmao=NULL;
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
    tPessoa *p=pessoa->pai;
    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n",pessoa->nome);
        if(p){
            printf("PAI: %s\n",(p)->nome);
        }else{
            printf("PAI: NAO INFORMADO\n");
        }
        p=pessoa->mae;
        if(p){
            printf("MAE: %s\n",(p)->nome);
        }else{
            printf("MAE: NAO INFORMADO\n");
        }
        p=pessoa->irmao;
        if(p){
            printf("IRMAO: %s\n",p->nome);
        }else{
            printf("IRMAO: NAO INFORMADO\n");
        }
        printf("\n");
    }
}
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    if(pessoa1->pai && pessoa2->pai && pessoa1->mae && pessoa2->mae){
        if( ( (pessoa1->mae) == (pessoa2->mae) ) && ( (pessoa1->pai) == (pessoa2->pai) )){
            return 1;
        }
    }
    return 0;
}
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
    int qtd,idxMae,idxPai,idxFilho;
    scanf("%d\n",&qtd);
    for (int i = 0; i < qtd; i++){
        scanf("mae: %d, pai: %d, filho: %d\n",&idxMae,&idxPai,&idxFilho);
        if((idxMae>-1) && (idxMae<numPessoas)){
            pessoas[idxFilho].mae=&pessoas[idxMae];
        }
        if((idxPai>-1) && (idxPai<numPessoas)){
            pessoas[idxFilho].pai=&pessoas[idxPai];
        }
    }
    for (int i = 0; i < numPessoas; i++){
        for ( int j= i+1; j < numPessoas; j++){
            if(VerificaIrmaoPessoa(&pessoas[i],&pessoas[j])){
                pessoas[i].irmao=&pessoas[j];
                pessoas[j].irmao=&pessoas[i];
            }
        }
    }
    
}