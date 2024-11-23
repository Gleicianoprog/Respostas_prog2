#include"candidato.h"
#include<stdio.h>
tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato rtn;
    int i=0;
    while(nome[i]){
        rtn.nome[i]=nome[i];
        i++;
    }
    rtn.nome[i]='\0';
    i=0;
    while(partido[i]){
        rtn.partido[i]=partido[i];
        i++;
    }
    rtn.partido[i]='\0';
    rtn.cargo=cargo;
    rtn.id=id;
    rtn.votos=0;
    return rtn;
}
tCandidato LeCandidato(){
    tCandidato rtn;
    scanf("%*[\n]");
    scanf("%[^,^\n], ",rtn.nome);
    scanf("%[^,^\n], ",rtn.partido);
    scanf("%c, ",&rtn.cargo);
    scanf("%d, ",&rtn.id);
    rtn.votos=0;
    return rtn;
}
int VerificaIdCandidato(tCandidato candidato, int id){
    if(candidato.id==id){
        return 1;
    }
    return 0;
}
char ObtemCargo(tCandidato candidato){
    return candidato.cargo;
}
int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2){
    if((VerificaIdCandidato(candidato1, candidato2.id))&&(ObtemCargo(candidato1)==ObtemCargo(candidato2))){
        return 1;
    }
    return 0;
}
tCandidato IncrementaVotoCandidato(tCandidato candidato){
    tCandidato rtn;
    rtn=candidato;
    rtn.votos++;
    return rtn;
}
int ObtemVotos(tCandidato candidato){
    return candidato.votos;
}
float CalculaPercentualVotos(tCandidato candidato, int totalVotos){
    float percentual=0,votos=(totalVotos*1.0);
    percentual=(candidato.votos/votos)*100;
    return percentual;
}
void ImprimeCandidato (tCandidato candidato, float percentualVotos){
    printf("%s (%s), %d voto(s), %.2f%%\n",candidato.nome,candidato.partido,candidato.votos,percentualVotos);
}