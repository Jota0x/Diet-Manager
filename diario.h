// bibliotecas padrão
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// dados para relatorio
typedef struct
{
    int dia;
    int mes;
    int ano;
    // ver implementação de outras possiveis variaveis
} Diario;

Diario dia;

// funções principais para relatorio
bool verificarData(Diario diario);
void salvarDiario();
void apresentarDiario();
void apresentarSemanal();
void apresentarMensal();
