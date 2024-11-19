#include"ponto.h"
#include<math.h>
Ponto pto_cria (float x, float y){
    Ponto rtn;
    rtn.x=x;
    rtn.y=y;
    return rtn;
}
float pto_acessa_x (Ponto p){
    return p.x;
}
float pto_acessa_y (Ponto p){
    return p.y;
}
Ponto pto_atribui_x (Ponto p, float x){
    p.x=x;
    return p;
}
Ponto pto_atribui_y (Ponto p, float y){
    p.y=y;
    return p;
}
float pto_distancia (Ponto p1, Ponto p2){
    double x1,x2,y1,y2;
    x1=pto_acessa_x (p1);
    x2=pto_acessa_x (p2);
    y1=pto_acessa_y (p1);
    y2=pto_acessa_y (p2);
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}