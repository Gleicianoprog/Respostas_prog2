#include "utils_char2.h"
#include<stdio.h>
int main(){
    int tam=TAM_PADRAO;
    char *vet;
    vet=CriaVetorTamPadrao();
    //ImprimeString(vet);
    vet=LeVetor(vet,&tam);
    ImprimeString(vet);
    LiberaVetor(vet);
    return 0;
}