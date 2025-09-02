// bibliotecas básicas
#include <stdio.h>
#include <stdlib.h>

//dados usuario
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
// --- IMC --- //
float calculoIMC(Usuario usuario);
void classificacaoIMC();

// --- TMB --- //
float calculoTBM(Usuario usuario);

// ---- calculo ---- //
