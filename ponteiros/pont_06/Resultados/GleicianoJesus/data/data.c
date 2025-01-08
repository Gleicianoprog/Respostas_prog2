#include"data.h"
#include<stdio.h>
void InicializaDataParam( int dia, int mes, int ano, tData *data){
    tData dataRtn;
    dataRtn.dia=dia;
    dataRtn.mes=mes;
    dataRtn.ano=ano;
    *data=dataRtn;
}
void LeData( tData *data ){
    tData rtn;
    int dias;
    scanf("%d %d %d",&rtn.dia,&rtn.mes,&rtn.ano);
    dias=InformaQtdDiasNoMes(&rtn);
    if(rtn.dia>dias){
        rtn.dia=dias;
    }
    if(rtn.dia<1){
        rtn.dia=1;
    }
    if(rtn.mes>12){
        rtn.mes=12;
    }
    if(rtn.mes<1){
        rtn.mes=1;
    }
    *data=rtn;
}
void ImprimeData( tData *data ){
    tData rtn;
    rtn=*data;
    printf("'%02d/%02d/%02d'",rtn.dia,rtn.mes,rtn.ano);
}
int EhBissexto( tData *data ){
    tData rtn;
    rtn=*data;
    if(((rtn.ano%100!=0)&&(rtn.ano%4==0))||(rtn.ano%400==0)){
        return 1;
    }
    return 0;
    // if ano % 100 != 0 and ano % 4 == 0 or ano % 400 == 0:
}
int InformaQtdDiasNoMes( tData *data ){
    tData rtn;
    rtn=*data;
    if(rtn.mes==1||rtn.mes==3||rtn.mes==5||rtn.mes==7||rtn.mes==8||rtn.mes==10||rtn.mes==12){
        return 31;
    }
    if(rtn.mes==2){
        if(EhBissexto(data)){
            return 29;
        }else{
            return 28;
        }
    }
    return 30;
}
void AvancaParaDiaSeguinte( tData *data ){
    tData rtn=*data;
    int dias;
    dias=InformaQtdDiasNoMes(data);
    if(rtn.dia<dias){
        rtn.dia++;
    }else{
        if(rtn.mes<12){
            rtn.mes++;
            rtn.dia=1;
        }else{
            rtn.ano++;
            rtn.mes=1;
            rtn.dia=1;
        }
    }
    *data=rtn;
}
int EhIgual( tData *data1, tData *data2 ){
    tData d1,d2;
    d1=*data1;
    d2=*data2;
    if(d1.dia==d2.dia&&d1.mes==d2.mes&&d2.ano==d1.ano){
        return 1;
    }
    return 0;
}