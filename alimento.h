#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALIMENTOS 100

typedef struct
{
    char nome[50];
    float calorias;
    float carboidrato;
    float proteinas;
    float gordura;

} Alimento;

Alimento bancoAlimento[MAX_ALIMENTOS]; // bando de dados
int totalAlimento = 0;

void cadastroAlimento(Alimento *alimento);
void listarAlimento();
void gerenciarAlimento();
