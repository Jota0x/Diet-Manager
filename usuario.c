#include "usuario.h"

void cadastroUsuario(Usuario *usuario)
{
    FILE *arquivo;

    while (getchar() != '\n') // limpa buffer
        ;

    // abre arquivo para gravação
    arquivo = fopen("usuario.txt", "w");

    // trata erro na gravação
    if (arquivo == NULL)
    {
        printf("\nErro ao gravar em arquivo!");
    }
    else
    {
        // menu base cadastro
        printf("\n ---MENU DE CADASTRO ---\n");
        printf("Nome: ");
        fgets(usuario->nome, 50, stdin);

        // Remove quebra de linha
        usuario->nome[strcspn(usuario->nome, "\n")] = 0;

        do
        {
            printf("Sexo: ");
            scanf(" %c", &usuario->sexo);

            usuario->sexo = toupper(usuario->sexo);

            // trata sexo indefinido
            if (usuario->sexo != 'M' && usuario->sexo != 'F')
            {
                printf("Sexo Indefinido!");
            }

            while (getchar() != '\n') // limpa buffer
                ;

        } while (usuario->sexo != 'M' && usuario->sexo != 'F');

        printf("Idade: ");
        scanf("%d", &usuario->idade);
        while (getchar() != '\n') // limpa buffer
            ;

        printf("Peso: ");
        scanf("%f", &usuario->peso);
        while (getchar() != '\n') // limpa buffer
            ;

        printf("Altura: ");
        scanf("%f", &usuario->altura);
        while (getchar() != '\n') // limpa buffer
            ;

        // grava em arquivo
        fprintf(arquivo, "%s; %c;%d;%f;%f;\n", usuario->nome, usuario->sexo, usuario->idade, usuario->peso, usuario->altura);

        // fecha arquivo
        fclose(arquivo);

    } // end else

} // end cadastroUsuario

void apresentarUsuario(Usuario *usuario)
{
    FILE *arquivo;

    // abre arquivo para leitura
    arquivo = fopen("usuario.txt", "r");

    // trata erro na leitura
    if (arquivo == NULL)
    {
        printf("\nErro na leitura de arquivo");
    }
    else
    {
        fscanf(arquivo, "%[^;];%c;%d;%f;%f", usuario->nome, usuario->sexo, usuario->idade, usuario->peso, usuario->peso); // %[^;] lê até o ;
        printf("\n --- USUARIO ---\n");
        printf("Nome: %s", usuario->nome);
        printf("Sexo: %c", usuario->sexo);
        printf("Idade: %d", usuario->idade);
        printf("Peso: %f", usuario->peso);
        printf("Altura: %f", usuario->altura);
        printf("TBM: %.2f", TBMcalculo(usuario));
        printf("IMC: %.2f", IMCcalculo(usuario));
    } // end else

} // end apresentarUsuario

float TBMcalculo(Usuario *usuario)
{
    float TBM;

    if (usuario->sexo == 'F')
    {
        TBM = 88.362 + (13.397 * usuario->peso) + (4.799 * usuario->altura) - (5.677 * usuario->idade);
    }
    else
        447.593 + (9.247 * usuario->peso) + (3.098 * usuario->altura) - (4.330 * usuario->idade);

    return TBM;

} // end TBMcalculo

// Verificar sexo para calculo
float IMCcalculo(Usuario *usuario)
{
    float IMC;

    IMC = usuario->peso / (usuario->altura * usuario->altura);

    return IMC;

} // end IMCcalculo