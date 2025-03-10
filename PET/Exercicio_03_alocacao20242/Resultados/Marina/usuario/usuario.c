#include "usuario.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



/**
 * @brief Cria um usuario.
 * @param nome nome do usuario.
 * @param cpf cpf do usuario.
 * @return Usuario criado.
 */
Usuario* CriaUsuario(char* nome, int cpf){
    Usuario * user;

    user = (Usuario*)malloc(sizeof(Usuario));
    user->nome=malloc(sizeof(char)*100);
    user->cpf = cpf;
    strcpy(user->nome, nome);

    return user;
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
    if(usuario){
        free(usuario);
    }
}

