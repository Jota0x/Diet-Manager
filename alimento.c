#include "alimento.h"

//cadastro
void cadastro(Alimento *alimento)
{
    FILE *arquivo;

    // abre para escrita
    arquivo = fopen("alimento.txt", "a");

    if (arquivo == NULL)
        printf("Erro ao abrir arquivo");
    else
    {

        // leitura de alimento
        printf(" \n ==== Cadastro de alimento ==== \n");
        printf("Nome: ");
        scanf("%[^\n]", alimento->nome);
        printf("\nCarboidrato (100g): ");
        scanf(" %f", &alimento->carboidrato);
        printf("\nProteina (100g): ");
        scanf(" %f", &alimento->proteina);
        printf("\nGordura (100g): ");
        scanf(" %f", &alimento->gordura);
        fprintf(arquivo, "%s%.2f%.2f%.2f", alimento->nome, alimento->carboidrato, alimento->proteina, alimento->gordura);

        printf("\nNovo Alimento cadastrado com sucesso!");
        totalAlimentos++;

        fclose(arquivo);
    }
}//end cadastro

