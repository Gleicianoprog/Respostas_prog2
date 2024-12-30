#include <stdio.h> 
#include"utils_char.h"
int main(){
    int tamanho;
    char * c;
    scanf("%d\n",&tamanho);
    c=CriaVetor(tamanho);
    ImprimeString(c,tamanho);
    LeVetor(c,tamanho);
    ImprimeString(c,tamanho);
    LiberaVetor(c);
    return 0;
}