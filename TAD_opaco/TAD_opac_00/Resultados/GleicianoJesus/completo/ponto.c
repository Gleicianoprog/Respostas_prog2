#include<stdlib.h>
#include"ponto.h"
#include<math.h>
struct ponto{
    float x;
    float y;
};
tPonto Pto_Cria (float x, float y){
    tPonto rtn=malloc(sizeof(struct ponto));
    if(!rtn){
        printf("problema ao alocar o ponto!\n");
        return NULL;
    }
    rtn->x=x;
    rtn->y=y;
    return rtn;
}
void Pto_Apaga (tPonto p){
    free(p);
}
float Pto_Acessa_x (tPonto p){
    return p->x;
}
float Pto_Acessa_y (tPonto p){
    return p->y;
}
void Pto_Atribui_x (tPonto p, float x){
    p->x=x;
}
void Pto_Atribui_y (tPonto p, float y){
    p->y=y;
}
float Pto_Distancia (tPonto p1, tPonto p2){
    float x1=Pto_Acessa_x (p1),y1=Pto_Acessa_y (p1), x2=Pto_Acessa_x (p2), y2=Pto_Acessa_y (p2);
    float dy=(y1-y2),dx=(x1-x2),distancia=0;
    distancia=sqrt((dy*dy)+(dx*dx));
    return distancia;
}