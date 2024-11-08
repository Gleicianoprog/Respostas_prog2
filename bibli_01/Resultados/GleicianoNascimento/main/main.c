#include"esfera_utils.h"
#include<stdio.h>
int main(){
    float raio=0,volume=0,area=0;
    scanf("%f",&raio);
    area=calcula_area(raio);
    volume=calcula_volume(raio);
    printf("Area: %.2f\n",area);
    printf("Volume: %.2f\n",volume);
    return 0;
}