#ifndef PONTO_GEOMETRICO
#define PONTO_GEOMETRICO
#define DESTE_TIPO_ int
#define DESTE_FORMATO_ "d"
#include<stdio.h>
#include<stdlib.h>
typedef struct ponto_geometrico tPonto;
tPonto *CriarPonto(DESTE_TIPO_ x, DESTE_TIPO_ y);
void ImprimirPonto(tPonto *p);
void LiberarPonto(tPonto *p);
tPonto *InicializaPonto();
#endif