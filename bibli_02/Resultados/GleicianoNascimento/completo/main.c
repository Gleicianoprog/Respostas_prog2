#include <stdio.h>
#include"matrix_utils.h"
int main(){
    int choice=0,rows1=0,cols1=0,rows2=0,cols2=0;
    scanf("%d %d\n",&rows1,&cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);
    scanf("%d %d\n",&rows2,&cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);
    do{
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");
        scanf("%d",&choice);
        if(choice==1){
            int result[rows1][cols1];
            if(possible_matrix_sum(rows1, cols1, rows2, cols2)){
                matrix_add(rows1, cols1, matrix1, rows2,cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }else if(choice==2){
            int result[rows1][cols1];
            if(possible_matrix_sub(rows1, cols1, rows2, cols2)){
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }else if(choice==3){
            if(possible_matrix_multiply(cols1, rows2)){
                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols2, result);
            }else{
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        }else if(choice==4){
            int scalar=0,wichMatrix=0;
            scanf("%d",&scalar);
            scanf("%d",&wichMatrix);
            if(wichMatrix==1){
                scalar_multiply(rows1, cols1,matrix1,scalar);
                matrix_print(rows1, cols1, matrix1);
            }else if(wichMatrix==2){
                scalar_multiply(rows2, cols2,matrix2,scalar);
                matrix_print(rows1, cols1, matrix2);
            }
        }else if(choice==5){
            int result1[cols1][rows1],result2[cols2][rows2];
            transpose_matrix(rows1, cols1, matrix1, result1);
            transpose_matrix(rows2, cols2, matrix2, result2);
            matrix_print(cols1, rows1, result1);
            matrix_print(cols2, rows2, result2);
        }
    }while(choice!=6);
    return 0;
}