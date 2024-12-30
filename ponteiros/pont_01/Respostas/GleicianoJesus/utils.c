#include"utils.h"
int TrocaInterios(int * n1, int * n2){
    int contN1,contN2;
    contN1=*n1;
    contN2=*n2;
    if(*n1<=*n2){
        return 0;
    }else{
        *n1=contN2;
        *n2=contN1;
        return 1;
    }
}