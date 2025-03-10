// typedef struct Pintura Pintura;
#include"pintura.h"
//     ●​ Título (string).
// ●​ Artista (string).
// ●​ Movimento (string).
// ●​ Material (string).
// ●​ Ano da pintura (inteiro).
struct Pintura
{
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    char movimento[MAXTAM_STRINGS];
    char material[MAXTAM_STRINGS];
    int ano;
};


// Aloca dinamicamente uma nova estrutura Pintura e realiza a leitura dos dados
// de entrada associados à pintura. Retorna o ponteiro para o objeto Pintura.
// Retorna: Ponteiro para a Pintura recém-criada, com dados carregados.
Pintura* pintura_construct(){
    Pintura* rtn;
    rtn=malloc(sizeof(Pintura));
    scanf("%s %s %s %s %d\n",rtn->titulo,rtn->artista,rtn->movimento,rtn->material,&rtn->ano);
    return rtn;
}

// Imprime os dados de uma pintura. Recebe um ponteiro genérico para a pintura,
// e utiliza a função de impressão para exibir as informações relevantes.
// Parâmetros:
//  p - Ponteiro para a Pintura a ser impressa.
void pintura_print(void* p){
    Pintura* pintura;
    pintura=(Pintura*)p;
    printf("PINTURA\n");
    printf("Titulo: %s\nArtista: %s\nMovimento: %s\nMaterial: %s\nAno: %d\n",pintura->titulo,pintura->artista,pintura->movimento,pintura->material,pintura->ano);
}

// Libera a memória alocada para a pintura, chamando a função de desalocação
// apropriada para os dados da estrutura Pintura.
// Parâmetros:
//  p - Ponteiro para a Pintura a ser destruída.
void pintura_destroy(void* p){
    free(p);
}