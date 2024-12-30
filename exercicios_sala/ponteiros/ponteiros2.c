#include<stdio.h>
int main(){
    int x=0,y=0;
    int*x1,*x2;
    x1=&x;
    x2=&y;
    if(x1>x2){
        printf("O endereço %p é maior do que o endereco %p\n",x1,x2);
    }else{
        printf("O endereço %p é maior do que o endereco %p\n",x2,x1);
    }
    return 0;
}