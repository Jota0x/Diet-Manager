// headers
#include "alimento.h"

// --- Alimento --- //

// --- SEM TESTE ---
// CHECAR GRAVAÇÂO NO ARQUIVO E FORMATAÇÃO
void adicionarALimento()
{
    FILE *arquivo;

    // mensagem de erro caso arquivo vazio
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
    } // end if
    else
    {
        // abre arquivo para gravação
        arquivo = fopen("alimento.txt", "w");

        // Cadastro de alimento ( Sem arquivo ainda )
        printf("\n --- Alimento --- \n");
        printf("Nome: ");
        fgets(alimento.nome, 50, stdin);
        printf("\nPorcao: ");
        scanf("%f", alimento.porcao);
        printf("\nCarbiodrato por porcao: ");
        scanf(" %f", alimento.carboidrato);
        printf("\nProteina por porcao: ");
        scanf(" %f", alimento.proteina);
        printf("\nGordura por porcao: ");
        scanf(" %f", alimento.gordura);

        // salva informações no arquivo
        fprintf(arquivo, "%s;%f;%f;%f;%f", alimento.nome, alimento.porcao, alimento.carboidrato, alimento.proteina, alimento.gordura);
    } // end else
    
    //fecha arquivo 
    fclose(arquivo);

    //mensagem de sucesso
    printf("Dados cadastrados com sucesso!");

} // adicionarAlimento

// --- Alimento --- //