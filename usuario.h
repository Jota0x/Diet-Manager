#include <stdio.h>
#include <stdlib.h>

//dados base
typedef struct
{
    char nome[50];
    char sexo;
    int idade;
    float peso;
    float altura;
} Usuario;

Usuario usuario;

void cadastroUsuario();
void apresentarUsuario();