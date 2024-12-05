#ifndef _TLESAO_
#define _TLESAO_
typedef struct{
    char id[10];
    char diagnostico[100];
    char regiao[100];
    int malignidade;
}tLesao;
tLesao leLesao();
void imprimeLesao(tLesao l);
void imprimeIdlesao(tLesao l);
int EhlesaoCirurgica(tLesao l);
#endif