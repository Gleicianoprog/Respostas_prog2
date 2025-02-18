#include"circulo.h"
struct circular{
    int raio;
};
double CalculaAreaC(Circular_pt c){
    double rtn;
    rtn=PI*((c->raio)*(c->raio));
    return rtn;
}