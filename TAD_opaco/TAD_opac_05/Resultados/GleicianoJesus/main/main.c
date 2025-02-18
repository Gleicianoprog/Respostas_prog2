#include"banco.h"
#include"conta.h"
#include"usuario.h"
int main(){
    tBanco * b;
    char op;
    b=CriaBanco();
    while (1){
        scanf("%c\n",&op);
        if(op=='F'){
            break;
        }else if(op=='A'){
            AbreContaBanco(b);
        }else if(op=='T'){
            TransferenciaContaBanco(b);
        }else if(op=='D'){
            DepositoContaBanco(b);
        }else if(op=='S'){
            SaqueContaBanco(b);
        }else if(op=='R'){
            ImprimeRelatorioBanco(b);
        }
    }
    
    DestroiBanco(b);
    return 0;
}