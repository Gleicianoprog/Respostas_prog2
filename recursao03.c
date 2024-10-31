#include<stdio.h>
int ContaOcorrencias(int *vet,int numElementos,int numeroProcurado);
int main(){
    int v[5]={2,2,2,2,3};
    printf("%d\n",ContaOcorrencias(v,5,2));
    return 0;
}
int ContaOcorrencias(int *vet,int numElementos,int numeroProcurado){
    int x=0;
    numElementos--;
    if(numElementos<0){
        return 0;
    }
    x=(vet[numElementos]==numeroProcurado)?1:0;
    return x+ContaOcorrencias(vet,numElementos,numeroProcurado);
}