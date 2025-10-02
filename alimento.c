#include "alimento.h"

void cadastroAlimento(Alimento *alimento)
{

    while (getchar() != '\n') // limpa buffer
        ;

    printf("\n --- MENU ALIMENTO --- \n");
    printf("Nome: ");
    fgets(alimento->nome, 50, stdin);

    // Remove quebra de linha
    alimento->nome[strcspn(alimento->nome, "\n")] = 0;

    printf("Calorias (por 100g): ");
    scanf("%f", &alimento->calorias);
    while (getchar() != '\n') // limpa buffer
        ;

    printf("Carboidratos (por 100g): ");
    scanf("%f", &alimento->carboidrato);
    while (getchar() != '\n') // limpa buffer
        ;

    printf("Proteinas (por 100g): ");
    scanf("%f", &alimento->proteinas);
    while (getchar() != '\n') // limpa buffer
        ;

    printf("Gorduras (por 100g): ");
    scanf("%f", &alimento->gordura);
    while (getchar() != '\n') // limpa buffer
        ;

} // end cadastroAlimento

// permite gravação no arquivo
void gerenciarAlimento()
{

    Alimento novoAlimento;

    // trata banco de dados cheio
    if (totalAlimento >= MAX_ALIMENTOS)
    {
        printf("Limite de cadastros atingidos!");
    } // end if
    else
    {
        cadastroAlimento(&novoAlimento);
        printf("Cadastro realizado com sucesso!");

        bancoAlimento[totalAlimento] = novoAlimento;

        // abre arquivo
        FILE *arquivo;

        arquivo = fopen("alimento.txt", "a");

        if (arquivo == NULL)
        {
            printf("Erro ao gravar");
        } // end if
        else
        {
            // salva em arquivo
            fprintf(arquivo, "%s;%.2f;%.2f;%.2f;%.2f\n",
                    novoAlimento.nome, novoAlimento.calorias, novoAlimento.carboidrato,
                    novoAlimento.proteinas, novoAlimento.gordura);
            fclose(arquivo);
        }

        totalAlimento++;
        printf("Total de alimentos cadastrados: %d", totalAlimento);
    } // end else

} // end gerenciarAlimento

void listarAlimento()
{
    if (totalAlimento == 0)
    {
        printf("Nenhum alimento cadastrado!");
    } // end if
    else
    {
        printf("\n--- TABELA DE ALIMENTOS CADASTRADOS (%d de %d) ---\n",
               totalAlimento, MAX_ALIMENTOS);

        // Configuração do cabeçalho da tabela
        printf("%-4s | %-20s | %-8s | %-8s | %-8s | %-8s\n",
               "ID", "NOME", "KCAL", "CARB (g)", "PROT (g)", "GORD (g)");
        printf("--------------------------------------------------------------------------------\n");

        for (int i = 0; i < totalAlimento; i++)
        {

            Alimento *alimentoAtual = &bancoAlimento[i];

            // impressão das infromações
            printf("%-4d | %-20s | %-8.0f | %-8.1f | %-8.1f | %-8.1f\n", i + 1, alimentoAtual->nome, alimentoAtual->calorias, alimentoAtual->carboidrato, alimentoAtual->proteinas, alimentoAtual->gordura);
        }

        printf("--------------------------------------------------------------------------------\n");
    } // end else

} // end apresentarAlimento