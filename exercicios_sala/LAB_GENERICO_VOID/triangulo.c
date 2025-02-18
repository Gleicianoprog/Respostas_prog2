#include"triangulo.h"
struct triangular{
    int c;
    int l;
};
double CalculaAreaT(Triangular_pt t){
    double rtn;
    rtn=(t->c)*(t->l);
    rtn/=2;
    return rtn;
}