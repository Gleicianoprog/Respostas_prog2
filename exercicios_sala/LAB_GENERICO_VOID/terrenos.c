#include"terrenos.h"
#include"retangulo.h"
#include"circulo.h"
#include"triangulo.h"
#include"terreno.h"
#include<stdio.h>
struct terrenos{
    Terreno_pt *terrenos;
    int qtde;
};
Terrenos_pt InicializaTerrenos(int qtde){
    int i=0;
    Terrenos_pt t;
    t=malloc(sizeof(struct terrenos));
    t->terrenos=malloc(sizeof(Terreno_pt)*(t->qtde));
    return t;
}
void adicionarArea(Terrenos_pt t, Terreno * f){
    t->terrenos[t->qtde]=f;
    t->qtde++;
}
double  AreaTotal(Terrenos_pt t){
    int i=0;
    double rtn=0;
    for ( i = 0; i < t->qtde; i++){
       rtn+=Area(t->terrenos[i]);  
    }
    return rtn;
}
double Media(Terrenos_pt terrenos){
    double rtn=0;
    rtn=AreaTotal(terrenos);
    rtn/=terrenos->qtde;
    return rtn;
}