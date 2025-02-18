#include"cidade.h"
#include<stdlib.h>
#include"defesa.h"
#include"missil.h"
struct cidade
{
    float tamX;
    float tamY;
    int qtdM;
    int qtdD;
    tMissil misseis[QTD_MIS];
    tDefesa defesas[QTD_DEF];
};
tCidade CriaCidade(){
    tCidade rtn;
    rtn=malloc(sizeof(struct cidade));
    rtn->qtdD=0;
    rtn->qtdM=0;
    // rtn->misseis=malloc(size);
    return rtn;
}
tCidade LeEntrada(tCidade cidade){
    char c;
    while (1){        
        scanf("%c",&c);
        if(c=='C'){
            scanf("%f %f\n",&cidade->tamX,&cidade->tamY);
        }else if(c==DEFESA){
            // cidade->defesas=realloc(cidade->defesas,sizeof(tDefesa)*(cidade->qtdD+1));
            cidade->defesas[cidade->qtdD]=LeDefesa();
            cidade->qtdD++;
        }else if(c==MISSIL){
            // cidade->misseis=realloc(cidade->misseis,sizeof(tMissil)*(cidade->qtdM+1));
            cidade->misseis[cidade->qtdM]=LeMissil;
            cidade->qtdM++;
        }else if(c==ENCERRAR){
            break;
        }
    }
    
}