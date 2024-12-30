#include"utils.h"
#include<stdio.h>
void LeIntervalo(int * m, int * n){
    scanf("%d %d",m,n);
}
int EhPrimo(int n){
    int count=0,divisor=1;
    for ( divisor ; divisor <= n; divisor++){
        if(!(n%divisor)){
            count++;
        }
        if(count>2){
            return 0;
        }
    }
    if(count>=1){
        return 1;
    }
    return 0;   
}
void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    int maiorNum=m,menorNum=n;
    for ( m ; m <= n; m++){
        if(EhPrimo(m) && (m>maiorNum)){
            maiorNum=m;
        }
        if(EhPrimo(m)&& (m<menorNum)){
            menorNum=m;
        }
    }
    if(EhPrimo(maiorNum)){
        *maior=maiorNum;
    }
    if(EhPrimo(menorNum)){
        *menor=menorNum;
    }
}