#include"registro.h"
#include"jogador.h"
#include<stdio.h>
Registro leRegistro(int idPartida){
    Registro rtn;
    int i=0,id=0;
    rtn.idPartida=idPartida;
    for ( i = 0; i < 5; i++){
        scanf("%d: ",&id);
        rtn.jogadores[i]=leJogador(id);
    }
    return rtn;
}
Jogador buscaJogadorRegistro(Registro r, int idJog){
    int i=0;
    Jogador rtn;
    rtn=inicializaJogador(idJog);
    for ( i = 0; i < 5; i++){
        if(getIdJogador(r.jogadores[i])==idJog){
            rtn=r.jogadores[i];
            break;
        }else{
            rtn.id=-1;
        }
    }
    return rtn;
}