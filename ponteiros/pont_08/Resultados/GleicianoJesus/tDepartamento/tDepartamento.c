#include<stdio.h>
#include"tDepartamento.h"
tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3,char *nome, int m1, int m2, int m3, char *diretor ){
    tDepartamento departamento;
    sprintf(departamento.curso1,"%s",curso1);
    sprintf(departamento.curso2,"%s",curso2);
    sprintf(departamento.curso3,"%s",curso3);
    sprintf(departamento.nome,"%s",nome);
    sprintf(departamento.diretor,"%s",diretor);
    departamento.m1=m1;
    departamento.m2=m2;
    departamento.m3=m3;
    return departamento;
}
void ImprimeAtributosDepartamento(tDepartamento depto){
    float media=0;
    printf("\nDepartamento: %s\n",depto.nome);
    printf("\tDiretor: %s\n",depto.diretor);
    printf("\t1o curso: %s\n",depto.curso1);
    printf("\tMedia do 1o curso: %d\n",depto.m1);
    printf("\t2o curso: %s\n",depto.curso2);
    printf("\tMedia do 2o curso: %d\n",depto.m2);
    printf("\t3o curso: %s\n",depto.curso3);
    printf("\tMedia do 3o curso: %d\n",depto.m3);
    media=depto.m1+depto.m2+depto.m3;
    media=media/3.0;
    printf("\tMedia dos cursos: %.2f",media);
}
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    tDepartamento depto,depto2,aux;
    float media=0,media2=0;
    for (int i = 0; i < num_deptos; i++){
        depto=vetor_deptos[i];
        media=depto.m1+depto.m2+depto.m3;
        media=media/3.0;
        for ( int j = i+1; j < num_deptos; j++){
            depto2=vetor_deptos[i];
            media2=depto2.m1+depto2.m2+depto2.m3;
            media2=media2/3.0;
            if(media2>media){
                aux=vetor_deptos[i];
                vetor_deptos[i]=vetor_deptos[j];
                vetor_deptos[j]=aux;
            }
        }
    }
    
}