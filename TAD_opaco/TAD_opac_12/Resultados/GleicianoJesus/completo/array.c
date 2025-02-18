#include"array.h"
#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int *nums;
    int tam;
};
Array *CriarArray(){
    Array* rtn;
    rtn=malloc(sizeof(Array));
    rtn->nums=malloc(sizeof(int));
    rtn->tam=0;
    return rtn;
}
void DestruirArray(Array *array){
    free(array->nums);
    free(array);
}
void LerArray(Array *array){
    char lixo='\0';
    array->tam=0;
    while (1){
        array->nums=realloc(array->nums,sizeof(int)*((array->tam)+1));
        scanf("%d%c",&array->nums[array->tam],&lixo);
        // printf("%d",array->nums[array->tam]);
        array->tam++;
        if(lixo=='.'){
            break;
        }
    }
}
void OrdenarArray(Array *array){
    int aux;
    for (int i = 0; i < array->tam; i++){
        for (int j = i+1; j < array->tam; j++){
            if(array->nums[j]<array->nums[i]){
                aux=array->nums[i];
                array->nums[i]=array->nums[j];
                array->nums[j]=aux;
            }
        }
    }
}
int BuscaBinariaArray(Array *array, int elementoBuscado){
    int menor=0,maior=array->tam,meio=(maior+menor)/2;
    // OrdenarArray(array);
    while (meio<maior&&meio>menor){
        if(array->nums[meio]==elementoBuscado){
            return meio;
        }else if(elementoBuscado > array->nums[meio]){
            menor=meio;
            meio=(menor+maior)/2;
        }else{
            maior=meio;
            meio=(menor+maior)/2;
        }
        // printf("%d",meio);
    }
    return -1;
}