#include<stdlib.h>
#include"ponto.h"
#include"circulo.h"
struct circulo{
    tPonto centro;
    float raio;
};
tCirculo Circulo_Cria (float x, float y, float r){
    tCirculo rtn;
    rtn=malloc(sizeof(struct circulo));
    tPonto p=Pto_Cria(x,y);
    Circulo_Atribui_Centro(rtn,p);
    Circulo_Atribui_Raio(rtn,r);
    return rtn;
}
void Circulo_Apaga (tCirculo c){
    if(!c){
        printf("problema ao apagar o circulo!\n");
    }
    Pto_Apaga(Circulo_Acessa_Centro(c));
    free(c);
}
tPonto Circulo_Acessa_Centro (tCirculo c){
    return c->centro;
}
float Circulo_Acessa_Raio (tCirculo c){
    return c->raio;
}
void Circulo_Atribui_Centro (tCirculo c, tPonto p){
    c->centro=p;
}
void Circulo_Atribui_Raio (tCirculo c, float r){
    //c->raio=malloc(sizeof(float));
    c->raio=r;
}
int Circulo_Interior (tCirculo c, tPonto p){
    tPonto centro=Circulo_Acessa_Centro(c);
    if(Pto_Distancia(centro,p)<=Circulo_Acessa_Raio(c)){
        return 1;
    }
    return 0;
}