#include<stdio.h>
int main(){
    int nI=0;
    char c='c';
    float nF=1.0;
    //printf("%d %.2f %c\n",nI,nF,c);
    int *pnI;
    float *pnF;
    char *pC;
    pnI=&nI;
    pnF=&nF;
    pC=&c;
    *pnI=2;
    *pnF=2.0;
    *pC='a';
    printf("%d %.2f %c\n",nI,nF,c);
    return 0;
}