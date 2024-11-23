#include"eleicao.h"
#include"candidato.h"
#include"eleitor.h"
#include<stdio.h>
tEleicao InicializaEleicao(){
    tEleicao rtn;
    tCandidato candidatoAtual;
    int qtd=0,i=0,j=0;
    char cargo;
    rtn.votosBrancosPresidente=0;
    rtn.votosNulosPresidente=0;
    rtn.votosBrancosGovernador=0;
    rtn.votosNulosGovernador=0;
    rtn.totalPresidentes=0;
    rtn.totalGovernadores=0;
    rtn.totalEleitores=0;
    scanf("%d\n",&qtd);
    while (qtd){
        candidatoAtual=LeCandidato();
        cargo=ObtemCargo(candidatoAtual);
        if(cargo=='G'){
            rtn.totalGovernadores++;
            rtn.governadores[i]=candidatoAtual;
            i++;
        }else{
            rtn.totalPresidentes++;
            rtn.presidentes[j]=candidatoAtual;
            j++;
        }
        qtd--;
    }
    return rtn;
}
tEleicao RealizaEleicao(tEleicao eleicao){
    tEleitor eleitorAtual;
    int qtd=0,votoP=0,votoG=0,i=0,j=0,votouP=0,votouG=0;
    scanf("%d\n",&qtd);
    while(qtd){
        votouP=0;
        votouG=0;
        eleitorAtual=LeEleitor();
        eleicao.totalEleitores++;
        votoP=ObtemVotoPresidente(eleitorAtual);
        votoG=ObtemVotoGovernador(eleitorAtual);
        for ( i = 0; i < eleicao.totalPresidentes; i++){
            if(VerificaIdCandidato(eleicao.presidentes[i],votoP)){
                eleicao.presidentes[i]=IncrementaVotoCandidato(eleicao.presidentes[i]);
                votouP=1;
            }
        }
        for ( i = 0; i < eleicao.totalGovernadores; i++){
            if(VerificaIdCandidato(eleicao.governadores[i],votoG)){
                eleicao.governadores[i]=IncrementaVotoCandidato(eleicao.governadores[i]);
                votouG=1;
            }
        }
        if(votoP==0){
            eleicao.votosBrancosPresidente++;
            votouP=1;
        }
        if(votoG==0){
            eleicao.votosBrancosGovernador++;
            votouG=1;
        }
        if(!votouP){
            eleicao.votosNulosPresidente++;
        }
        if(!votouG){
            eleicao.votosNulosGovernador++;
        }
        eleicao.eleitores[j]=eleitorAtual;
        j++;
        qtd--;
    }
    return eleicao;
}
void ImprimeResultadoEleicao(tEleicao eleicao){
    int i=0,anula=0,j=0,nulos=0,brancos=0,empate=0;
    float percentil;
    tCandidato vencedorP=CriaCandidato("a", "a", 'P', -1),vencedorG=CriaCandidato("a", "a", 'G', -1);
    if(eleicao.totalEleitores>MAX_ELEITORES||eleicao.totalPresidentes>MAX_CANDIDATOS_POR_CARGO||eleicao.totalGovernadores>MAX_CANDIDATOS_POR_CARGO){
        printf("ELEICAO ANULADA\n");
    }else{
        for ( i=0; i < eleicao.totalEleitores; i++){
            for ( j= i+1; j < eleicao.totalEleitores; j++){
                if(EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j])){
                    anula=1;
                }
            }
        }
        if(!anula){
            for ( i = 0; i < eleicao.totalGovernadores; i++){
                if(ObtemVotos(eleicao.governadores[i])>=ObtemVotos(vencedorG)){
                    vencedorG=eleicao.governadores[i];
                }
            }
            for ( i = 0; i < eleicao.totalPresidentes; i++){
                if(ObtemVotos(eleicao.presidentes[i])>=ObtemVotos(vencedorP)){
                    vencedorP=eleicao.presidentes[i];
                }
            }
            printf("- PRESIDENTE ELEITO: ");
            for ( i = 0; i < eleicao.totalPresidentes; i++){
                if(ObtemVotos(vencedorP)==ObtemVotos(eleicao.presidentes[i])&&!EhMesmoCandidato(vencedorP,eleicao.presidentes[i])){
                    empate=1;
                }
            }
            percentil=CalculaPercentualVotos(vencedorP, eleicao.totalEleitores);
            if(!empate){
                if(eleicao.votosBrancosPresidente+eleicao.votosNulosPresidente>ObtemVotos(vencedorP)){
                    printf("SEM DECISAO");
                    printf("\n");
                }else{
                    ImprimeCandidato (vencedorP, percentil);
                }
            }else{
                printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO");
                printf("\n");
            }
            empate=0;
            percentil=CalculaPercentualVotos(vencedorG, eleicao.totalEleitores);
            printf("- GOVERNADOR ELEITO: ");
            for ( i = 0; i < eleicao.totalGovernadores; i++){
                if(ObtemVotos(vencedorG)==ObtemVotos(eleicao.governadores[i])&&!EhMesmoCandidato(vencedorG,eleicao.governadores[i])){
                    empate=1;
                }
            }
            if(!empate){
                if(eleicao.votosBrancosGovernador+eleicao.votosNulosGovernador>ObtemVotos(vencedorG)){
                    printf("SEM DECISAO");
                    printf("\n");
                }else{
                    ImprimeCandidato (vencedorG, percentil);
                }
            }else{
                printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO");
                printf("\n");
            }
            nulos=eleicao.votosNulosPresidente+eleicao.votosNulosGovernador;
            brancos=eleicao.votosBrancosPresidente+eleicao.votosBrancosGovernador;
            printf("- NULOS E BRANCOS: %d, %d\n",nulos,brancos);
        }else{
            printf("ELEICAO ANULADA\n");
        }
    }
}