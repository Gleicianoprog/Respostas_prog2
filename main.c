#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"bitmap.h"
#include"abb.h"
int main(int argc, char* argv[]){
    FILE* fp;
    Abb* abb[256];
    int vet[256],tam=100000,idx=0;
    char* buffer;
    buffer=malloc(sizeof(char)*tam);
    buffer[idx]='\0';
    for (int i = 0; i < 256; i++)
    {
        vet[i]=0;
    }

    // bitmap* bm=bitmapInit(10);
    char* nomeArquivo;
    nomeArquivo=strdup(argv[1]);
    fp=fopen(nomeArquivo,"rb");
    assert(fp);
    unsigned char codigoCaracterLido='\0';
    while (1)
    {
        fread(&codigoCaracterLido,sizeof(char),1,fp);
        if(feof(fp)){
            break;
        }
        buffer[idx]=codigoCaracterLido;
        if( idx+1 == tam){
            tam=tam*2;
            buffer=realloc(buffer,sizeof(char)*tam);
        }
        buffer[idx+1]='\0';
        vet[((int)codigoCaracterLido)]++;
        // printf("%c",buffer[idx]);
        idx++;
    }
    // printf("\n");
    idx=0;
    // printf("%s",buffer);
    for (int i = 0; i < 256; i++)
    {
        if(vet[i]){
            abb[idx]=abb_criaNo(vet[i],(char)i,NULL,NULL);
            idx++;
        }
    }
    for (int i = 0; i < idx; i++)
    {
        imprimeNo(abb[i]);
    }
    
    fclose(fp);
    free(nomeArquivo);
    free(buffer);
    return 0;
}

