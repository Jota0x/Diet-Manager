//bibliotecas básicas
#include <stdio.h>
#include <stdlib.h> 

//modelo base para cadastro de alimento
typedef struct
{
    char nome[50];
    float porcao; 
    float carboidrato;
    float proteina;
    float gordura;  

}Alimento;

Alimento alimento;

void adicionarALimento();
