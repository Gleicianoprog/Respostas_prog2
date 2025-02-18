#include"defesa.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct defesa
{
    float Cx;
    char nome[100];
    float Cy;
    float tam;
    float poder;
    char tipo;
    int qtd;
};

tDefesa LeDefesa(){
    tDefesa rtn;
    char nome[40];
    rtn=malloc(sizeof(struct defesa));
    scanf("%s %f %f %c %f %f %d\n",nome,&rtn->Cx,&rtn->Cy,&rtn->tipo,&rtn->tam,&rtn->poder,&rtn->qtd);
    rtn->nome[0]='D';
    rtn->nome[1]='-';
    rtn->nome[2]='\0';
    strcat(rtn->nome,nome);
    return rtn;
}   
void ImprimeDefesa(tDefesa defesa){
    printf("%s: %d\n",defesa->nome,defesa->qtd);
}
void LiberaDefesa(tDefesa defesa){
    free(defesa);
}
int VerificaSeDentroArea(tDefesa defesa, float x, float y){
    float distancia=0,raio;
    distancia=pow(((defesa->Cx)-x),2)+pow(((defesa->Cy)-y),2);
    distancia=sqrt(distancia);
    if(defesa->tam>=distancia){
        return 1;
    }
    return 0;
}
void UsaDefesa(tDefesa defesa){
    defesa->qtd--;
}
float GetDefesaPoder(tDefesa defesa){
    return defesa->poder;
}
int PodeDefender(tDefesa defesa){
    return defesa->qtd;
}