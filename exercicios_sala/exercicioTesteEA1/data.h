#ifndef DATA_T
#define DATA_T
typedef struct{
    int dia;
    int mes;
    int ano;
}tData;
void imprimeData(tData d);
int calculaIdade(tData d);
tData ledata();
#endif