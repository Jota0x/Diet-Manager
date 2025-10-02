#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// dados base
typedef struct
{
    char nome[50];
    char sexo;
    int idade;
    float peso;
    float altura;
} Usuario;

Usuario *usuario;

void cadastroUsuario(Usuario *usuario);
void apresentarUsuario(Usuario *usuario);
float TBMcalculo(Usuario *usuario);
float IMCcalculo(Usuario *usuario);