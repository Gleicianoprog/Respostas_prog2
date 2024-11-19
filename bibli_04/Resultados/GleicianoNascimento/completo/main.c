#include<stdio.h>
#include"data.h"
int main(){
    int dia1=0,mes1=0,ano1=0;
    scanf("%02d/%02d/%04d",&dia1,&mes1,&ano1);
    if(verificaDataValida(dia1,mes1,ano1)){
        printf("Data informada: ");
        imprimeDataExtenso(dia1, mes1, ano1);
        if(verificaBissexto(ano1)){
            printf("O ano informado eh bissexto\n");
        }else{
            printf("O ano informado nao eh bissexto\n");
        }
        printf("O mes informado possui %02d dias\n",numeroDiasMes(mes1, ano1));
        printf("A data seguinte eh: ");
        imprimeProximaData(dia1, mes1,ano1);
    }else{
        printf("A data informada eh invalida\n");
    }
    
    return 0;
}