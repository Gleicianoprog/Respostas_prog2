#include"usuario.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * @brief Cria um usuario.
 * @param nome nome do usuario.
 * @param cpf cpf do usuario.
 * @return Usuario criado.
 */
Usuario* CriaUsuario(char* nome, int cpf){
    Usuario* rtn;
    rtn=malloc(sizeof(Usuario));
    rtn->nome=malloc(sizeof(char)*100);
    sprintf(rtn->nome,"%s",nome);
    rtn->cpf=cpf;
    return rtn;
}

/**
 * @brief Retorna o nome de um usuario.
 * @param usuario  um usuario.
 * @return nome do usuario.
 */
char* RecuperaNomeUsuario(Usuario* usuario){
    return usuario->nome;
}

/**
 * @brief Retorna o cpf de um usuario.
 * @param usuario  um usuario.
 * @return cpf do usuario.
 */
int RecuperaCpfUsuario(Usuario* usuario){
    return usuario->cpf;
}

/**
 * @brief Destroi um usuario.
 * @param usuario  um usuario.
 */
void DestroiUsuario(Usuario* usuario){
    free(usuario->nome);
    free(usuario);
    //usuario->nome=' ';
}