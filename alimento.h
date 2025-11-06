#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nome[100];
    float carboidrato;
    float proteina;
    float gordura;

} Alimento;

void cadastroAlimento(Alimento *alimento, int *total);
int carregarAlimento(Alimento *alimento, int max);
void listarAlimento(const Alimento *alimento, int total);
