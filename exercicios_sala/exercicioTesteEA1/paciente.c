#include"paciente.h"
#include<string.h>
#include<stdio.h>
tPaciente lePaciente(){
    tPaciente rtn;
    scanf("%[^\n]",rtn.nome);
    scanf("%*[\n]");
    rtn.data=ledata();
    scanf("%[^\n]",rtn.cartao);
    scanf("%*[\n]");
    scanf("%c",&rtn.genero);
    rtn.idade=calculaIdade(rtn.data);
    rtn.qtdLesao=0;
    return rtn;
}
void imprimePaciente(tPaciente p){
    printf("- %s - ",p.nome);
}
tPaciente vinculaLesao(tLesao l,tPaciente p){
    p.lesoes[p.qtdLesao]=l;
    p.qtdLesao++;
    return p;
}
int ehMesmoCartao(char cartao[19],tPaciente p){
    // printf("%s %s",cartao,p.cartao);
    if(strcmp(cartao,p.cartao)){
        return 1;
    }
    return 0;
}
int idadePaciente(tPaciente c){
    return c.idade;
};
int qtdLesao(tPaciente p){
    return p.qtdLesao;
}
tPaciente adicionaLesaoPaciente(tLesao l,tPaciente p){
    //printf("AAAAAAAAA");
    if(p.qtdLesao<10){
        p.lesoes[p.qtdLesao]=l;
        p.qtdLesao++;
    }
    return p;
}
void imprimeIdLesoes(tPaciente p){
    int i=0;
    for ( i = 0; i < p.qtdLesao ; i++){
        imprimeIdlesao(p.lesoes[i]);
    }
    
}