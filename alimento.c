// headers
#include "alimento.h"

// máximo de alimentos
#define MAX = 100;
// define o nuemro atual de elementos cadastrados no programa
int totalAtual = 0;

// --- Alimento --- //

// --- SEM TESTE --- //
// CHECAR GRAVAÇÂO NO ARQUIVO E FORMATAÇÃO
void adicionarALimento()
{
    FILE *arquivo;

    // verifica se o arquivo esta vazio
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

        totalAtual++;
    } // end else

    // fecha arquivo
    fclose(arquivo);

    // mensagem de sucesso
    printf("Dados cadastrados com sucesso!");

} // adicionarAlimento

// apresentarALimento
// Precisa acrescentar CHAVE DE PESQUISA
void apresentarAlimento()
{
    FILE *arquivo;

    arquivo = fopen("alimetno.txt", "r");

    // verifica se arquivo esta vazio
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo");
        // return --- Checar necessidade --- c pá nem precisa
    } // end if
    else
    {
        // verifica se todos os 5 dados foram lidos antes da apresentação
        if (fscanf(arquivo, "%[^;];%f;%f;%f;%f", alimento.nome, &alimento.porcao, &alimento.carboidrato, &alimento.proteina, &alimento.gordura) == 5) //%[^;] le string até ;
        {
            // Menu de alimento
            printf("\n --- Alimento --- \n");
            // apresenta dados cadastrados
            printf("Nome: %s", alimento.nome);
            printf("\nPorcao: %.2f", alimento.porcao);
            printf("\nCarboidrato: %.2f", alimento.carboidrato);
            printf("\nProteina: %.2f", alimento.proteina);
            printf("\nGordura: %f", alimento.gordura);

        } // end if
        else
        {
            printf("Erro na leitura do arquivo");
        } // end else

    } // end else

    // fecha arquivo
    fclose(arquivo);

} // Apresentar ALimento

// --- provavelmente ta errado --- SEM TESTE
void buscaALimento(char chave[], Alimento alimento[])
{
    FILE *arquivo;

    // abre arquivo para leitura
    arquivo = fopen("alimento.txt", "r");

    // trata erro de arquivo
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo");
    } // end if
    else
    {
        // le chave de busca
        scanf("%s", chave[50]); 

        // busca a palavra digitada
        for (int i = 0; i < totalAtual; i++)
        {
            // verifica alimento com nome pesquisado
            if (chave == alimento[i].nome)
            {   
                //imprime alimento, caso ache 
                printf("%s", alimento[i].nome);
            } // end if
            else
                printf("Nunhum item encontrado");
        } // end for
    } // end else
}

// --- Alimento --- //