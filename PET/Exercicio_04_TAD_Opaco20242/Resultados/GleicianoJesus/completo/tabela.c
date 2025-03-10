#include"tabela.h"
#include"time.h"
#include<stdlib.h>
#include<string.h>
struct _Tabela
{
    tTime** times;
    int numTimes;
};

/**
 * @brief Construtor do tipo tabela. Deve criar os times.
 * @param numTimes Numero de times a serem criados.
*/
tTabela* CriaTabela(int numTimes){
    tTabela* rtn;
    rtn=malloc(sizeof(tTabela));
    rtn->times=malloc(sizeof(tTime*)*numTimes);
    rtn->numTimes=numTimes;
    for (int i = 0; i < numTimes; i++){
        rtn->times[i]=LeTime();
    }
    return rtn;
}
/**
 * @brief Libera a memoria alocada para a tabela e seus times.
*/
void DesalocaTabela(tTabela* tabela){
    for (int i = 0; i < tabela->numTimes; i++){
        DesalocaTime(tabela->times[i]);
    }
    free(tabela->times);
    free(tabela);
}

/**
 * @brief Ordena a tabela de acordo com os criterios definidos.
*/
void OrdenaTabela(tTabela* tabela){
    tTime* aux;
    for (int i = 0; i < tabela->numTimes; i++){
        for (int j = i+1; j < tabela->numTimes; j++){
            if(ObtemVitorias(tabela->times[j])>ObtemVitorias(tabela->times[i])){
                aux=tabela->times[i];
                tabela->times[i]=tabela->times[j];
                tabela->times[j]=aux;
            }else if(ObtemVitorias(tabela->times[j])==ObtemVitorias(tabela->times[i])){
                if(DesempataTimes(tabela->times[i],tabela->times[j])==1){
                    aux=tabela->times[i];
                    tabela->times[i]=tabela->times[j];
                    tabela->times[j]=aux;
                }
            }
        }
        
    }
    
}

/**
 * @brief Dado um nome, retorna o time correspondente.
*/
tTime* ObtemTimeTabela(tTabela* tabela, char* time){
    //printf("%d\n",tabela->numTimes);
    int j=tabela->numTimes,i=0;
    for (i = 0; i < j;i++){
        if(!strcmp(ObtemNomeTime(tabela->times[i]),time)){
            return tabela->times[i];
        }
    }
    return NULL;
}

/**
 * @brief Dado um nome, desaloca e remove o time correspondente da tabela.
*/
void RemoveTimeTabela(tTabela* tabela, char* time){
    tTime* t,*aux;
    t=ObtemTimeTabela(tabela,time);
    for (int i = 0; i < tabela->numTimes; i++){
        if(t==tabela->times[i]){
            aux=tabela->times[(tabela->numTimes)-1];
            tabela->times[(tabela->numTimes)-1]=tabela->times[i];
            tabela->times[i]=aux;
            free(tabela->times[(tabela->numTimes)-1]);
            tabela->numTimes-=1;
            break;
        }
    }
    
}

/**
 * @brief Imprime a tela de premiacao no final do campeonato.
*/
void ImprimePremiacao(tTabela* tabela, float valorPremio){
    if(!(tabela->numTimes)){
        printf("Premio de R$%.2f acumulado para a proxima edicao\n",valorPremio);
    }else{
        if(tabela->numTimes>=2&&tabela->numTimes<4){
            printf("1º lugar - %s: R$%.2f\n",ObtemNomeTime(tabela->times[0]),0.6*(valorPremio));
            printf("2º lugar - %s: R$%.2f\n",ObtemNomeTime(tabela->times[1]),0.4*(valorPremio));
        }else if(tabela->numTimes>=4){
            printf("1º lugar - %s: R$%.2f\n",ObtemNomeTime(tabela->times[0]),0.5*(valorPremio));
            printf("2º lugar - %s: R$%.2f\n",ObtemNomeTime(tabela->times[1]),0.3*(valorPremio));
            printf("3º lugar - %s: R$%.2f\n",ObtemNomeTime(tabela->times[2]),0.2*(valorPremio));

        }
    }
}

/**
 * @brief Imprime todos os times da tabela.
*/
void ImprimeTabela(tTabela* tabela){
    //printf("%d\n",tabela->numTimes);
    if(tabela->numTimes){
        printf("Classificação:\n");
        printf("Nome | Pontos | Vitorias | Derrotas | Empates | Saldo\n");
        for (int i = 0; i < tabela->numTimes; i++){
            ImprimeTime(tabela->times[i]);
        }
        printf("\n");
    }
}