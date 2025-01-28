#include"ponto.h"
#include"circulo.h"
#include<stdio.h>
int main(){
    float Cx,Cy,r,Px,Py;
    tCirculo circulo;
    tPonto p;
    scanf("%f %f %f %f %f",&Cx,&Cy,&r,&Px,&Py);
    circulo=Circulo_Cria(Cx,Cy,r);
    p=Pto_Cria(Px,Py);
    if(Circulo_Interior(circulo,p)){
        printf("1\n");
    }else{
        printf("0\n");
    }
    Pto_Apaga(p);
    Circulo_Apaga(circulo);
    return 0;
}