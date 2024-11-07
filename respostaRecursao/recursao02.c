#include<stdio.h>
int SomaElementosPares(int *vet,int numElementos);
int main(){
    int vetTeste[5]={2,2,3,22,5};
    printf("%d\n",SomaElementosPares(vetTeste,5));
    return 0;
}
int SomaElementosPares(int *vet,int numElementos){
    int x=0;
    numElementos--;
    if(numElementos<0){
        return 0;
    }
    x=(vet[numElementos]%2==0)?vet[numElementos]:0;
    return x+SomaElementosPares(vet,numElementos);
}