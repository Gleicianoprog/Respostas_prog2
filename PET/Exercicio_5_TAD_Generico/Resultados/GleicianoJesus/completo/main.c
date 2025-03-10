#include"livro.h"
#include"musica.h"
#include"midia.h"
#include"pintura.h"
#include"roteiro.h"
int main(){
    Roteiro *r;
    Pintura* p;
    Livro* l;
    Musica* m;
    char c;
    int qtd;
    r=roteiro_construct();
    scanf("%d\n",&qtd);
    for (int i = 0; i < qtd; i++){
        scanf("%c ",&c);
        if(c=='P'){
            p=pintura_construct();
            roteiro_inserir_midia(r,p,pintura_print,pintura_destroy);
        }else if(c=='L'){
            l=livro_construct();
            roteiro_inserir_midia(r,l,livro_print,livro_destroy);

        }else if(c=='M'){
            m=musica_construct();
            roteiro_inserir_midia(r,m,musica_print,musica_destroy);
        }
    }
    roteiro_imprimir_midias(r);
    roteiro_destroy(r);
    return 0;
}