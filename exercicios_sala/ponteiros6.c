#include<stdio.h>
void LeDadosParaVetor(int* vet,int tam){
    int i=0;
    for ( i = 0; i < tam; i++){
        scanf("%d",&vet[i]);
    }
}
void OrdeneCrescente(int* vet,int tam){
    int i=0,j=0,flag=0;
    for ( i = 0; i < tam; i++){
        for ( j=i+1; j < tam; j++){
            if(vet[j]<vet[i]){
                flag=vet[i];
                vet[i]=vet[j];
                vet[j]=flag;
            }
        }
    }
}
void ImprimeDadosVetor(int* vet,int tam){
    int i=0;
    for ( i = 0; i < tam; i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}
int main(){
    int casos;
    scanf("%d",&casos);
    while (casos){
        int tam;
        scanf("%d",&tam);
        int vet[tam];
        LeDadosParaVetor(vet,tam);
        OrdeneCrescente(vet,tam);
        ImprimeDadosVetor(vet,tam);
        casos--;
    }
    return 0;
}