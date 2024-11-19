#include"data.h"
#include<stdio.h>
int verificaBissexto(int ano){
    if(!(ano%400)||((ano%100)&&!(ano%4))){
        return 1;
    }
    return 0;
}
int verificaDataValida(int dia, int mes, int ano){
    if((mes==1||mes==3||mes==5||mes==7||mes==10||mes==12||mes==8)&&(dia<=31&&dia>=1)){
        return 1;
    }
    if((mes==4||mes==6||mes==9||mes==11)&&(dia<=30&&dia>=1)){
        return 1;
    }
    if((mes==2)&&(dia>=1&&dia<=29)&&(verificaBissexto(ano))){
        return 1;
    }
    if((mes==2)&&(dia>=1&&dia<=28)){
        return 1;
    }
    return 0;
}
void imprimeMesExtenso(int mes){
    printf(" ");
    switch (mes){
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Fevereiro");
        break;
    case 3:
        printf("Marco");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;
    }
    printf(" ");
}
void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de",dia);
    imprimeMesExtenso(mes);
    printf("de %d\n",ano);
}
int numeroDiasMes(int mes, int ano){
    if((mes==1||mes==3||mes==5||mes==7||mes==10||mes==12||mes==8)){
        return 31;
    }
    if((mes==4||mes==6||mes==9||mes==11)){
        return 30;
    }
    if((mes==2)&&(verificaBissexto(ano))){
        return 29;
    }
    if((mes==2)){
        return 28;
    }
    return 0;
}
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1>ano2){
        return 1;
    }else if(ano1==ano2){
        if(mes1>mes2){
            return 1;
        }else if(mes1==mes2){
            if(dia1>dia2){
                return 1;
            }else if(dia1==dia2){
                return 0;
            }else{
                return -1;
            }
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}
int calculaDiasAteMes(int mes, int ano){
    int soma=0,count=0;
    while(count!=ano){
        if(verificaBissexto(count)){
            soma+=366;
        }else{
            soma+=365;
        }
        count++;
    }
    count=0;
    while (count!=mes){
        soma+=numeroDiasMes(count,ano);
        count++;
    }
    return soma;
}
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int dataMaior=comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
    if(dataMaior==1){
        return calculaDiasAteMes(mes1,ano1)-calculaDiasAteMes(mes2,ano2)+(dia1-dia2);
    }else if(dataMaior==-1){
        return calculaDiasAteMes(mes2,ano2)-calculaDiasAteMes(mes1,ano1)+(dia2-dia1);
    }else{
        return 0;
    }
}
void imprimeData(int dia, int mes, int ano){
    printf("%02d/%02d/%04d\n",dia,mes,ano);
}
void imprimeProximaData(int dia, int mes, int ano){
    int diasMes=0;
    diasMes=numeroDiasMes(mes, ano);
    if(dia<diasMes){
        dia++;
    }else{
        if(mes<12){
            mes++;
            dia=1;
        }else{
            dia=1;
            mes=1;
            ano++;
        }
    }
    printf("%02d/%02d/%04d\n",dia,mes,ano);
}