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

} Usuario;

Usuario usuario;
// ---- usuario ---- //

void cadastrarUsuario();
void apresentarUsuario();

// ---- usuario ---- //

// ---- calculo ---- //

float imcCalculo(float altura, float peso);
float tbmCalculo(float altura, float peso, int idade, char sexo);

// ---- calculo ---- //
