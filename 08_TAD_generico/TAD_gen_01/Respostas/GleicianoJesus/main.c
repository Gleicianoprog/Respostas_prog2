#include<stdio.h>
#include"tadgen.h"
int main(){
    int qtd=0,tipo=-1;
    printf("tad_gen_01\nDigite o tipo e numero de elementos: ");
    scanf("%d %d\n",&tipo,&qtd);
    tGeneric* generico;
    generico=CriaGenerico(tipo,qtd);
    LeGenerico(generico);
    ImprimeGenerico(generico);
    DestroiGenerico(generico);
    return 0;
}