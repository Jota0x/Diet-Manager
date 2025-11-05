#include "alimento.h"

// cadastro
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
        fprintf(arquivo, "%s;%f;%f;%f", alimento->nome, alimento->carboidrato, alimento->proteina, alimento->gordura);

        printf("\nNovo Alimento cadastrado com sucesso!");
        totalAlimentos++;

        fclose(arquivo);
    }
} // end cadastro

// lista
void listaAlimento(Alimento *alimento, int total)
{
    FILE *arquivo;

    // abre pra leitura
    arquivo = fopen("alimento.txt", "r");

    if (arquivo == NULL)
        printf("Erro ao abrir arquivo");
    else
    {
        printf("\n ==== Tabela alimento ==== \n");

        for (int i = 0; i < total; i++)
        {
            printf("=================================================================");
            printf("Alimento %d", i + 1);
            fscanf(arquivo, "%[^;];%f;%f;%f", alimento->nome, alimento->carboidrato, alimento->proteina, alimento->gordura);
            printf("%s", alimento->nome);
            printf("Carboidrato: %.2f", alimento->carboidrato);
            printf("Proteina: %.2f", alimento->proteina);
            printf("Gordura: %.2f", alimento->gordura);
        }
    }

} // lista
