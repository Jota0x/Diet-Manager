#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char nome[100];
    int idade;
    float altura;
    float peso;
    char sexo;

} Usuario;

Usuario usuario;

void cadastroUsuario(Usuario *usuario);
void apresentarUsuario(Usuario *usuario);    
float calculoTMB(Usuario *usuario);
float calculoIMC(Usuario *usuario);
