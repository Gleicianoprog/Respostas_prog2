#include"terreno.h"
#include"retangulo.h"
#include"circulo.h"
#include"triangulo.h"
struct terreno{
    void * terreno;
    enum TERRENO tipo;
};
Terreno_pt InicializaTerreno(void * terreno, enum TERRENO tipo){
    Terreno_pt rtn;
    rtn=malloc(sizeof(struct terreno));
    rtn->tipo=tipo;
    rtn->terreno=terreno;
    return rtn;
}
double  Area(Terreno_pt t){
    double rtn;
    switch (t->tipo){
    case 0:
        rtn=CalculaAreaC(t->terreno);
        break;
    case 1:
        rtn=CalculaAreaR(t->terreno);
        break;
    case 2:
        rtn=CalculaAreaT(t->terreno);
        break;
    }
    return rtn;
}
void liberaTerreno(Terreno_pt t){
    free(t->terreno);
    free(t);
}