#include<stdio.h>
#include"departamento.h"
int main(){
    int qtd,m1=0,m2=0,m3=0,i=0;
    char dep[100],diretor[100],c1[100],c2[100],c3[100];
    tDepartamento dpts[100];
    scanf("%d\n",&qtd);
    while (qtd){
        scanf("%[^\n]",dep);
        scanf("%*[\n]");
        scanf("%[^\n]",diretor);
        scanf("%*[\n]");
        scanf("%[^\n]",c1);
        scanf("%*[\n]");
        scanf("%[^\n]",c2);
        scanf("%*[\n]");
        scanf("%[^\n]",c3);
        scanf("%*[\n]");
        scanf("%d %d %d\n",&m1,&m2,&m3);
        if(validaMediaDepartamento(m1)&&validaMediaDepartamento(m2)&&validaMediaDepartamento(m3)){
            dpts[i]=criaDepartamento(c1,c2,c3,dep,m1,m2,m3,diretor);
            i++;
            //imprimeAtributosDepartamento(dpt);
        }
        qtd--;
    }
    ordenaPorMediaDepartamentos(dpts,i);
    for ( qtd=0 ; qtd < i ; qtd++){
        imprimeAtributosDepartamento(dpts[qtd]);
    }
    
    return 0;
}