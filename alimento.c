#include "alimento.h"

// cadastro
void cadastroAlimento(Alimento *alimento, int *total)
{
    FILE *arquivo;

    // abre para escrita
    arquivo = fopen("alimento.txt", "a");

    if (arquivo == NULL)
        printf("Erro ao abrir arquivo");
    else
    {
        if (*total < 500)
        {
            // leitura de alimento
            printf(" \n ==== Cadastro de alimento ==== \n");

            printf("Nome: ");
            scanf(" %[^\n]", alimento->nome);

            printf("Carboidrato (100g): ");
            scanf(" %f", &alimento->carboidrato);

            printf("Proteina (100g): ");
            scanf(" %f", &alimento->proteina);

            printf("Gordura (100g): ");
            scanf(" %f", &alimento->gordura);

            printf("\n\n--- DEBUG ---");
            printf("O que a struct 'alimento' recebeu:\n");
            printf("Nome na struct: '%s'\n", alimento->nome);
            printf("Carb na struct: %f\n", alimento->carboidrato);
            printf("Prot na struct: %f\n", alimento->proteina);
            printf("Gord na struct: %f\n", alimento->gordura);
            printf("--- FIM DEBUG ---\n\n");

            fprintf(arquivo, "%s;%f;%f;%f\n", alimento->nome, alimento->carboidrato, alimento->proteina, alimento->gordura);

            printf("\nNovo Alimento cadastrado com sucesso!");
            (*total)++;
        }
        else
            printf("Total de cadastros atingido!");

        fclose(arquivo);
    }
} // end cadastro

// carregar alimento
int carregarAlimento(Alimento *alimento, int max)
{
    FILE *arquivo;
    int contador = 0;

    arquivo = fopen("alimento.txt", "r");

    if (arquivo == NULL)
        return 0;

    while (contador < max && fscanf(arquivo, "%[^;];%f;%f;%f\n", alimento[contador].nome, &alimento[contador].carboidrato, &alimento[contador].proteina, &alimento[contador].gordura) == 4)
        contador++;

    fclose(arquivo);

    return contador;
} // end carregar alimento

// lista
void listarAlimento(const Alimento *alimento, int total)
{

    printf("\n ==== Tabela alimento ==== \n");

    if (total == 0)
        printf("Nenhum alimento cadastrado!");
    else
        for (int i = 0; i < total; i++)
        {
            printf("\nAlimento #%d \n", i + 1);
            printf("%s\n", alimento[i].nome);
            printf("Carboidrato: %.2f\n", alimento[i].carboidrato);
            printf("Proteina: %.2f\n", alimento[i].proteina);
            printf("Gordura: %.2f\n", alimento[i].gordura);
        }

} // lista
