#include <stdio.h>
#include <stdlib.h>

#define MAX_ALIMENTO 500

int totalAlimentos = 0;

typedef struct
{
    char nome[100];
    float carboidrato;
    float proteina;
    float gordura;

} Alimento;

Alimento alimento;

void cadastroAlimento(Alimento *alimento);
