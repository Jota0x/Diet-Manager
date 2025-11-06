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

void cadastroUsuario(Usuario *usuario);
int carregarUsuario(Usuario *usuario);
void apresentarUsuario(const Usuario *usuario);
float calculoTMB(const Usuario *usuario);
float calculoIMC(const Usuario *usuario);
