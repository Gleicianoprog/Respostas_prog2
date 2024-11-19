#include"ponto.h"
#include<stdio.h>
int main(){
    double x1=0,y1=0,x2=0,y2=0;
    double distancia=0;
    Ponto p1,p2;
    scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
    p1=pto_cria (x1,y1);
    p2=pto_cria (x2,y2);
    distancia = pto_distancia (p1, p2);
    printf("%g\n",distancia);
    return 0;
}