#include"array.h"
#include<stdio.h>
void imprimeVetor(Array * array){
    for (int i = 0; i < array->tamanho; i++){
        printf("%d ",array->data[i]);
    }
    printf("\n");
}
int main(){
    int num=0,idx;
    Array* array;
    array=CriarArray();
    LerArray(array);
    OrdenarArray(array);
    // imprimeVetor(array);
    //scanf("%*c");
    scanf("%d",&num);
    //scanf("%d",&num);
    //printf("%d\n",num);
    idx=BuscaBinariaArray(array,num);
    if(idx!=-1){
        printf("Elemento %d encontrado no índice %d.\n",num,idx);
    }else{
        printf("Elemento %d não encontrado no array (%d).\n",num,idx);
    }
    DestruirArray(array);
    return 0;
}