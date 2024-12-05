#include "lesao.h"
#include<stdio.h>
tLesao leLesao(){
    tLesao rtn;
    scanf("%[^\n]",rtn.id);
    scanf("%*[\n]");
    scanf("%[^\n]",rtn.diagnostico);
    scanf("%*[\n]");
    scanf("%[^\n]",rtn.regiao);
    scanf("%d",&rtn.malignidade);
    return rtn;
}
void imprimeLesao(tLesao l){
    printf("%s %s %s %d\n",l.id,l.diagnostico,l.regiao,l.malignidade);
}
int EhlesaoCirurgica(tLesao l){
    if(l.malignidade>50){
        return 1;
    }
    return 0;
}
void imprimeIdlesao(tLesao l){
    printf("%s ",l.id);
}