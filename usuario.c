// bibliotecas
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// headers
#include "usuario.h"

// ---- usuario ---- //

// cadastro de usuario --- SEM TESTE --- Arquivo implementado
void cadastrarUsuario()
{
    // criação arquivo
    FILE *arquivo;

    // abre arquivo para a gravação(escrita)
    arquivo = fopen("teste.txt", "w");

    // mensagem de erro caso arquivo esteje vazio
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        return; // indica erro
    } // end if
    else
    {
        // limpa buffer para leitura
        fflush(stdin); // talvez n seja preciso fgets ja faz essa função

        // cadastro de pessoa (com arquivo) - SEM TESTE  -
        printf(" \n--- Cadastro de Usuario ---\n ");

        printf("Nome: ");
        fgets(usuario.nome, 50, stdin); // le o nome com espaços, mas deixa \n no final
        // usuario.nome[strcspn(usuario.nome, "\n")] = '\0'; // substitui o \n do final da string por \0 para evitar erro nas  proximas leituras

        printf(" Idade: ");
        scanf("%d", &usuario.idade);

        // limpa o buffer de entrada apos o scanf - evita leitura da quebra de linha
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        // verifica sexo
        do
        {
            printf(" Sexo(M/F): ");
            scanf(" %c", &usuario.sexo);

            // valida letra minuscula
            usuario.sexo = toupper(usuario.sexo);

            // mensagem de erro caso sexo indefinido
            if (usuario.sexo != 'M' && usuario.sexo != 'F')
            {
                printf("Sexo invalido! Digite M ou F");
            } // end if

        } while (usuario.sexo != 'M' && usuario.sexo != 'F');

        printf(" Peso: ");
        scanf("%f", &usuario.peso);

        printf(" Altura: ");
        scanf("%f", &usuario.altura);

        // armazena informações no arquivo
        fprintf(arquivo, "%s;%d;%c;%f;%f\n", usuario.nome, usuario.idade, usuario.sexo, usuario.peso, usuario.altura);
    } // end else
    fclose(arquivo);
    // sucesso caso cadastrado
    printf("Dados cadastrados com sucesso!");

} // cadastrarUsuario

// apresentação de usuario - SEM TESTE - não revisado
void apresentarUsuario()
{
    FILE *arquivo;

    // abre o arquivo para leitura
    arquivo = fopen("teste.txt", "r");

    // verifica se o arquivo esta vazio
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        return; // indica erro
    } // end if
    else
    {
        // le dados gravados no arquivo
        if (fscanf(arquivo, "%[^;];%d;%c;%f;%f", usuario.nome, &usuario.idade, &usuario.sexo, &usuario.peso, &usuario.altura) == 5) // %[^;] le strig até ;
        // caso leitura bem sucedida --- apresenta os dados
        {

            // menu de cadastro do usuario
            printf("\n ---- Cadastro ---- \n");

            printf("Nome: %s\n", usuario.nome);
            printf("Idade: %d\n", usuario.idade);
            printf("Sexo: %c\n", usuario.sexo);
            printf("Peso: %.2f Kg\n", usuario.peso);
            printf("Altura: %.2f cm\n", usuario.altura);
            printf("Taxa metabolica basal(TBM): %f", tbmCalculo(usuario.peso, usuario.altura, usuario.idade, usuario.peso));

        } // end if
        else
        {
            printf("Erro na leitura do arquivo!");
        } // end else

    } // end else if

    fclose(arquivo);

} // apresentarUsuario

// ---- usuario ---- //

// ---- calculo ---- //

// calculo de IMC
float imcCalculo(float altura, float peso)
{
    float IMC;

    IMC = peso / (altura * altura);

    return IMC;

} // imcCalcular

// calculo de TBM
float tbmCalculo(float peso, float altura, int idade, char sexo)
{
    float TBM;

    if (sexo == 'M')
    {
        TBM = 66.47 + (13.75 * peso) + (5.003 * altura) - (6.755 * idade);
    } // end if
    else if (sexo == 'F')
    {
        TBM = 655.1 + (9.563 * peso) + (1.850 * altura) - (4.676 * idade);
    } // end if
    else
        printf("Sexo indefinido");

    return TBM;
} // tbmCalculo

// ---- calculo ---- //
