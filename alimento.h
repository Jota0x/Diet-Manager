// bibliotecas básicas
#include <stdio.h>
#include <stdlib.h>

// dados alimento
typedef struct
{
    char nome[50];
    float porcao;
    float carboidrato;
    float proteina;
    float gordura;

} Alimento;

Alimento alimento;

// --- gravação e leitura ---
void adicionarALimento();
void apresentarAlimento();

// --- calculo ---
void totalCaloria(Alimento alimento);
