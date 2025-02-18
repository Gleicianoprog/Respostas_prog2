#include"ponto_geometrico.h"
#include<string.h>
struct ponto_geometrico{
    DESTE_TIPO_ x;
    DESTE_TIPO_ y;
};
tPonto *CriarPonto(DESTE_TIPO_ x, DESTE_TIPO_ y){
    tPonto *rtn;
    rtn= (tPonto*) malloc(sizeof(DESTE_TIPO_)*2);
    rtn->x=x;
    rtn->y=y;
    return rtn;
}
void ImprimirPonto(tPonto *p){
    char formato[20]="{%.2";
    strcat(formato,DESTE_FORMATO_);
    strcat(formato,", %.2");
    strcat(formato,DESTE_FORMATO_);
    strcat(formato,"}\n");
    printf(formato,p->x,p->y);
}
void LiberarPonto(tPonto *p){
    free(p);
}