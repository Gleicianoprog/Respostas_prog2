#include"data.h"
#include<stdio.h>
#include<stdlib.h>
struct data{
    int dia;
    int mes;
    int ano;
};
tData* LeData(){
    tData * rtn;
    int dia,mes,ano;
    scanf("%d/%d/%d\n",&dia,&mes,&ano);
    rtn=CriaData(dia,mes,ano);
    return rtn;
}
tData* CriaData(int dia, int mes, int ano){
    tData *rtn;
    rtn=malloc(sizeof(tData));
    rtn->dia=dia;
    rtn->mes=mes;
    rtn->ano=ano;
    return rtn;
}
void LiberaData(tData* d){
    free(d);
}
int CalculaIdadeData(tData* nascimento, tData* diacalc){
    int rtn=0;
    if((nascimento->dia>=diacalc->dia)&&(nascimento->mes>=diacalc->mes)){
        rtn+=1;
    }
    rtn+=(diacalc->ano-nascimento->ano);
    // printf("%dAAA",rtn);
    // ImprimeData(nascimento);
    // ImprimeData(diacalc);
    return rtn;
}
void ImprimeData(tData* d){
    printf("%02d,%02d,%04d\n",d->dia,d->mes,d->ano);
}