#include"data.h"
#include<stdio.h>
#include<stdlib.h>
struct Data
{
    int dia;
    int mes;
    int ano;
};
tData* CriaData(){
    tData* rtn;
    rtn=malloc(sizeof(tData));
    rtn->dia=-1;
    rtn->mes=-1;
    rtn->ano=-1;
    return rtn;
}
void LeData(tData* data){
    scanf("%d/%d/%d\n",&data->dia,&data->mes,&data->ano);
}
void LiberaData(tData* data){
    free(data);
}
int VerificaDataValida(tData* data){
    if(data->dia<=0||data->dia>31){
        return 0;
    }
    if(data->mes>12||data->mes<=0){
        return 0;
    }
    if((data->mes==1)||(data->mes==3)||(data->mes==5)||(data->mes==7)||(data->mes==8)||(data->mes==10)||(data->mes==12)){
        return 1;
    }
    if(data->mes==2&&!VerificaBissexto(data)&&data->dia>29){
        return 0;
    }else if(data->mes==2&&data->dia>28){
        return 0;
    }
    return 1;
}
void ImprimeMesExtenso(tData* data){
    if(data->mes==1){
        printf("Janeiro");
    }else if(data->mes==2){
        printf("Fevereiro");
    }else if(data->mes==3){
        printf("Marco");
    }else if(data->mes==4){
        printf("Abril");
    }else if(data->mes==5){
        printf("Maio");
    }else if(data->mes==6){
        printf("Junho");
    }else if(data->mes==7){
        printf("Julho");
    }else if(data->mes==8){
        printf("Agosto");
    }else if(data->mes==9){
        printf("Setembro");
    }else if(data->mes==10){
        printf("Outubro");
    }else if(data->mes==11){
        printf("Novembro");
    }else if(data->mes==12){
        printf("Dezembro");
    }
}
void ImprimeDataExtenso(tData* data){
    printf("%02d de ",data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n",data->ano);
}
int VerificaBissexto(tData* data){
    if((data->ano%4)==0){
        return 1;
    }
    return 0 ;
}
int NumeroDiasMes(tData* data){
    if((data->mes==1)||(data->mes==3)||(data->mes==5)||(data->mes==7)||(data->mes==8)||(data->mes==10)||(data->mes==12)){
        return 31;
    }
    if(data->mes==2 && VerificaBissexto(data)){
        return 29;
    }
    if(data->mes==2){
        return 28;
    }
    return 30;
}
int ComparaData(tData* data1, tData* data2){
    if(data1->dia==data2->dia&&data1->ano==data2->ano&& data1->mes==data2->mes){
        return 0;
    }
    if(data1->ano>data2->ano){
        return 1;
    }else if(data1->ano==data2->ano){
        if(data1->mes>data2->mes){
            return 1;
        }else if(data1->mes==data2->mes){
            if(data1->dia>data2->dia){
                return 1;
            }
        }
    }
    return -1;
}
int CalculaDiasAteMes(tData* data){
    int ano=data->ano;
    int aux=data->mes;
    int num=0;
    data->mes=1;
    data->ano=1900;
    while ((data->ano)<ano){
        //printf("%d\n",num);
        if(VerificaBissexto(data)){
            num+=1;
        }
        num+=365;
        data->ano++;
        // printf("%d\n",num);
    }
    data->ano=ano;
    // printf("%d\n",num);
    while(data->mes<aux){
        //d->mes=mes;
        num+=NumeroDiasMes(data);
        (data->mes)++;
        //printf("%d\n",num);
    }
    //(data->mes)++;
    //LiberaData(d);
    return num;
}
int CalculaDiferencaDias(tData* data1, tData* data2){
    long unsigned int diasD1=0,diasD2=0;
    diasD1=CalculaDiasAteMes(data1);
    diasD2=CalculaDiasAteMes(data2);
    diasD2+=data2->dia;
    diasD1+=data1->dia;
    //ImprimeDataExtenso(data1);
    //printf("%d\n",diasD2);
    if(diasD1<diasD2){
        //printf("A primeira data eh mais antiga\n");
        return diasD2-diasD1;
    }else if(diasD1>diasD2){
        //printf("A segunda data eh mais antiga\n");
        return diasD1-diasD2;
    }else{
        // printf("As datas sao iguais\n");
        return 0;
    }
}