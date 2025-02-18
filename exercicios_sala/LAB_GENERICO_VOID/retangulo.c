#include"retangulo.h"
struct retangular{
    int c;
    int l;
};
double CalculaAreaR(Retangulo_pt r){
    double rtn;
    rtn=(r->c)*(r->l);
    return rtn;
}
