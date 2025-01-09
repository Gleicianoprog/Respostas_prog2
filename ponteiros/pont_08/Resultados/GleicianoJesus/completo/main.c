#include<stdio.h>
#include"tDepartamento.h"
int LeDpt(int i,tDepartamento *dptos);
int main(){
    int qtd;
    scanf("%d\n",&qtd);
    tDepartamento dptos[qtd];
    for ( int i = 0; i < qtd; i++){
        if(LeDpt(i,dptos)){
            continue;
        }else{
            i--;
            printf("\n");
            printf("Digite um departamento com médias válidas");
            continue;
        }
    }
    OrdenaDepartamentosPorMedia(dptos,qtd);
    for ( int i = 0; i < qtd; i++){
        ImprimeAtributosDepartamento(dptos[i]);
    }
    return 0;
}
int LeDpt(int i,tDepartamento *dptos){
    tDepartamento departamento;
    int n1,n2,n3;
    scanf("%s",departamento.nome);
    scanf("%s",departamento.diretor);
    scanf("%s",departamento.curso1);
    scanf("%s",departamento.curso2);
    scanf("%s",departamento.curso3);
    scanf("%d %d %d",&n1,&n2,&n3);
    if(n1>=0&&n3>=0&&n2>=0&&n1<=10&&n2<=10&&n3<=10){
        departamento.m1=n1;
        departamento.m2=n2;
        departamento.m3=n3;
        dptos[i]=departamento;
        return 1;
    }else{
        return 0;
    }
}