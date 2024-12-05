#include<stdio.h>
#include"paciente.h"
#include"data.h"
#include"clinica.h"
#include"lesao.h"
int main(){
    char op,cartao[19];
    int i=0;
    tPaciente p;
    tClinica c;
    tLesao l;
    c=inicializaClinica();
    while(1){
        scanf("%c",&op);
        if(op=='P'){
            scanf("%*c");
            p=lePaciente();
            c=adicionaPacienteClinica(c,p);
        }else if(op=='L'){
            scanf("%s\n",cartao);
            for(i=0;i<c.qtdPacientes;i++){
                if(ehMesmoCartao(cartao,c.pacientes[i])){
                    l=leLesao();
                    c.pacientes[i]=adicionaLesaoPaciente(l,c.pacientes[i]);
                    if(EhlesaoCirurgica(l)){
                        c.qtdCirurgias++;
                    }
                    c.qtdLesoes++;
                }
            }
        }else if(op=='F'){
            break;
        }
    }
    c=somaLesoes(c);
    imprimeClinica(c);
    return 0;
}