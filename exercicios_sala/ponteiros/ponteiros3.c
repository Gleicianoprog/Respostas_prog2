#include<stdio.h>
int TrocaInteiros(int *n1,int *n2){
    int*temp;
    if(*n1>*n2){
        temp=n1;
        n1= n2;
        n2=temp;
        //*n1=*n2;
        //*n2=temp;
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n1,n2;
    while (scanf("%d %d", &n1,&n2)){
        if(TrocaInteiros(&n1,&n2)){
            printf("TROCADO:%d %d\n",n1,n2);

        }else{
            printf("ORIGINAL:%d %d\n",n1,n2);
        }
    }
    
    return 0;
}