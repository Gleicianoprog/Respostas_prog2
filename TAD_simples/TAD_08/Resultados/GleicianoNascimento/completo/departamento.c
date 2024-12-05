#include"departamento.h"
#include<math.h>
#include<stdio.h>
tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    tDepartamento rtn;
    sprintf(rtn.c1,"%s",c1);
    sprintf(rtn.c2,"%s",c2);
    sprintf(rtn.c3,"%s",c3);
    sprintf(rtn.nome,"%s",nome);
    sprintf(rtn.diretor,"%s",diretor);
    rtn.m1=m1;
    rtn.m2=m2;
    rtn.m3=m3;
    rtn.media_geral=calculaMediaGeralDepartamento(rtn);
    return rtn;
}
void imprimeAtributosDepartamento (tDepartamento depto){
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n",depto.nome);
    printf("diretor => %s\n",depto.diretor);
    printf("curso1 => %s, media1 => %d\n",depto.c1,depto.m1);
    printf("curso2 => %s, media2 => %d\n",depto.c2,depto.m2);
    printf("curso3 => %s, media3 => %d\n",depto.c3,depto.m3);
    printf("media geral => %.2lf\n",depto.media_geral);
    printf("desvio padrao => %.2lf\n\n",calculaDesvioPadraoDepartamento(depto));
}
int validaMediaDepartamento (int media){
    if(media>=0&&media<=10){
        return 1;
    }
    return 0;
}
double calculaDesvioPadraoDepartamento(tDepartamento depto){
    double somatorio=0;
    int i=0;
    somatorio+=pow(depto.m1-depto.media_geral,2);
    somatorio+=pow(depto.m2-depto.media_geral,2);
    somatorio+=pow(depto.m3-depto.media_geral,2);
    somatorio=somatorio/3.0;
    somatorio=sqrt(somatorio);
    return somatorio;
    
}
double calculaMediaGeralDepartamento(tDepartamento depto){
    double mediaGeral;
    mediaGeral=(depto.m1+depto.m2+depto.m3)/3.00;
    return mediaGeral;
}
void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho){
    int i=0,j=0;
    tDepartamento aux;
    for ( i = 0; i < tamanho; i++){
        for ( j = i+1; j < tamanho; j++){
            if(d[j].media_geral>d[i].media_geral){
                aux=d[i];
                d[i]=d[j];
                d[j]=aux;
            }
        }
    }
}