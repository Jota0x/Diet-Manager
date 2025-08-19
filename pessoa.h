// bibliotecas básicas
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int idade;
    char sexo;
    float peso;
    float altura;

} Pessoa;

Pessoa pessoa;

void cadastrarPessoa();
float imcCalculo(float altura, float peso);
float tbmCalculo(float altura, float peso, int idade, char sexo);


