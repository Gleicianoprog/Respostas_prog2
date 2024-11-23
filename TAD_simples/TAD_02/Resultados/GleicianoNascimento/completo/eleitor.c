#include "eleitor.h"
#include<stdio.h>
tEleitor CriaEleitor(int id, int votoP, int votoG){
    tEleitor rtn;
    rtn.id=id;
    rtn.votoP=votoP;
    rtn.votoG=votoG;
    return rtn;
}
tEleitor LeEleitor(){
    tEleitor rtn;
    scanf("%d %d %d",&rtn.id,&rtn.votoP,&rtn.votoG);
    return rtn;
}
int ObtemVotoPresidente(tEleitor eleitor){
    return eleitor.votoP;
}
int ObtemVotoGovernador(tEleitor eleitor){
    return eleitor.votoG;
}
int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2){
    if(eleitor1.id==eleitor2.id){
        return 1;
    }
    return 0;
}