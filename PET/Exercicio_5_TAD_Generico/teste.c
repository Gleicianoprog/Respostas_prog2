#include<stdio.h>
#include<string.h>
int main(){
    int tamanho=0;
    char participantes[100];
    for (int i = 0; i < 3; i++){
        if(i){
            scanf("%s",((participantes)+(tamanho+1)));
        }else{
            scanf("%s",((participantes)+(tamanho)));
        }
        tamanho=(strlen(participantes));
        participantes[tamanho]=',';
    }
    participantes[tamanho]='\0';
    printf("%s",participantes);
    return 0;
}