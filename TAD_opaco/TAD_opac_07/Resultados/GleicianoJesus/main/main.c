#include<stdio.h>
#include"data.h"
int main(){
    tData * d1=CriaData(),*d2=CriaData();
    int diff=0;
    LeData(d1);
    LeData(d2);
    if(VerificaDataValida(d1)&&VerificaDataValida(d2)){
        diff=CalculaDiferencaDias(d1,d2);
        printf("Primeira data: ");
        ImprimeDataExtenso(d1);
        printf("Segunda data: ");
        ImprimeDataExtenso(d2);
        if(ComparaData(d1,d2)==-1){
            printf("A primeira data eh mais antiga\n");
        }else if(ComparaData(d1,d2)==1){
            printf("A segunda data eh mais antiga\n");
        }else{
            printf("As datas sao iguais\n");
        }
        printf("A diferenca em dias entre as datas eh: %02d dias\n",diff);
    }else{
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
    LiberaData(d1);
    LiberaData(d2);
    return 0;
}