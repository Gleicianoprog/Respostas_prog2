#include"array.h"
#include"assert.h"
#include<stdio.h>
#include<stdlib.h>
Array *CriarArray(){
    Array*rtn;
    rtn=malloc(sizeof(Array));
    assert(rtn);
    rtn->data=malloc(sizeof(int) * 100);
    assert(rtn->data);
    rtn->tamanho=0;
    return rtn;
}
void DestruirArray(Array *array){
    free(array->data);
    free(array);
}
void LerArray(Array *array){
    int num=0;
    char lixo='\0';
    assert(array);
    // scanf("%[^.]",nums);
    // sscanf(nums,"%s",array->data);
    while (1){
        scanf("%*[\n]");
        scanf("%d",&num);
        scanf("%c",&lixo);
        array->data[array->tamanho]=num;
        array->tamanho=array->tamanho+1;
        if(lixo=='.'){
            break;
        }
    }
    //scanf("%*[\n]");
    // printf("%d",num);
    // printf("%c",lixo);
    //pr/intf("%c",lixo);
        // scanf("%*[^.][0-9]");:
    // scanf("%*c");
    // scanf("%d",&num);
}
void OrdenarArray(Array *array){
    int aux;
    for (int i = 0; i < array->tamanho; i++){
        for (int j = i+1; j < array->tamanho; j++){
            if(array->data[j]<array->data[i]){
                aux=array->data[i];
                array->data[i]=array->data[j];
                array->data[j]=aux;
            }
        }
    }
}
int BuscaBinariaArray(Array *array, int elementoBuscado){
    int maiorIdx=(array->tamanho)-1,idxMeio=0,menorIdx=0,elementoAnterior=-1;
    idxMeio=((maiorIdx+menorIdx)/2);
    while (idxMeio>menorIdx){
        if(elementoBuscado<array->data[(idxMeio)]){
            maiorIdx=idxMeio;
            idxMeio=((maiorIdx+menorIdx)/2);
        }else if(elementoBuscado>array->data[(idxMeio)]){
            menorIdx=(idxMeio);
            idxMeio=((maiorIdx+menorIdx)/2);
        }else if(elementoBuscado== array->data[idxMeio]){
            //idxMeio=((maiorIdx+menorIdx)/2);
            return idxMeio;
        }
        //elementoAnterior=idxMeio;
    }
    return -1;
    
}