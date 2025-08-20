#include <alimento.h>

void cadastrarAlimento()
{
    // Cadastro de alimento ( Sem arquivo ainda )
    printf("\n --- Alimento --- \n");
    printf(" Nome:  \n");
    scanf(" %s", alimento.nome[50]);
    printf(" Porcao: \n");
    scanf("%f", alimento.porcao);
    printf(" Carbiodrato por porcao: \n");
    scanf(" %f", alimento.carboidrato);
    printf("Proteina por porcao: \n");
    scanf(" %f", alimento.proteina);
    printf(" Gordura por porcao: \n");
    scanf(" %f", alimento.gordura);

} // cadastrarAlimento

