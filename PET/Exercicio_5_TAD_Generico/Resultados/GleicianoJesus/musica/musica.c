#include"musica.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// ●​ Título (string).
// ●​ Artista (string).
// ●​ Número de participantes (inteiro).
// ●​ Participantes (string), separados por vírgula.
// ●​ Álbum (string).
// ●​ Gênero (string).
struct Musica
{
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    int numP;
    char participantes[(MAXTAM_STRINGS)*10];
    char album[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
};

// Aloca dinamicamente uma nova estrutura Musica e realiza a leitura dos dados
// de entrada associados à música. Pode envolver múltiplos participantes na música.
// Retorna: Ponteiro para a Musica recém-criada, com os dados carregados.
Musica* musica_construct(){
    Musica* rtn;
    int tamanho=0;
    char participante[100],participantes[1000]="";
    rtn=malloc(sizeof(Musica));
    scanf("%s %s %d ",rtn->titulo,rtn->artista,&rtn->numP);
    for (int i = 0; i < rtn->numP; i++){
        scanf("%s ",participante);
        strcat(participantes,participante);
        if(i+1<rtn->numP){
            strcat(participantes,", ");
        }
    }
    strcpy(rtn->participantes,participantes);
    scanf("%s %s\n",rtn->album,rtn->genero);
    return rtn;
}
void musica_print(void* m){
    Musica* musica;
    int tamanho,i=0;
    musica=(Musica*)m;
    printf("MUSICA\n");
    printf("%s - %s (feat. %s)\n",musica->artista,musica->titulo,musica->participantes);
    printf("Album: %s\nGenero: %s\n",musica->album,musica->genero);
}

// Libera a memória alocada para a música, desalocando a estrutura Musica
// e seus dados associados de forma adequada.
// Parâmetros:
//  m - Ponteiro para a Musica a ser destruída.
void musica_destroy(void* m){
    free(m);
}