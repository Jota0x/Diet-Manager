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
        // int c;
        // while ((c = getchar()) != '\n' && c != EOF)
        //   ;

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

// Nao FUNCIONA 
// Precisa acrescentar CHAVE DE PESQUISA
void apresentarUsuario()
{
    FILE *arquivo;

    // abre o arquivo para leitura
    arquivo = fopen("teste.txt", "r");

    // verifica se o arquivo esta vazio
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        // return; // indica erro
    } // end if
    else
    {
        // le dados gravados no arquivo
        if (fscanf(arquivo, "%[^;];%d;%c;%f;%f", usuario.nome, &usuario.idade, &usuario.sexo, &usuario.peso, &usuario.altura) == 5) // %[^;] le strig até ;
        // caso leitura bem sucedida --- apresenta os dados
        {

            // menu de cadastro do usuario
            printf("\n ---- Cadastro ---- \n");
            // apresneta dados cadastrados
            printf("\nNome: %s\n", usuario.nome);
            printf("\nIdade: %d\n", usuario.idade);
            printf("\nSexo: %c\n", usuario.sexo);
            printf("\nPeso: %.2f Kg\n", usuario.peso);
            printf("\nAltura: %.2f cm\n", usuario.altura);
            // taxas não salvas em arquivo --- verificar depois ---
            //verificar parametros
            printf("\nTaxa metabolica basal(TBM): %f", tbmCalculo(usuario));
            printf("\nIMC: %f", calculoIMC(usuario));
            classificacaoIMC();

        } // end if
        else
        {
            printf("Erro na leitura do arquivo!");
        } // end else

    } // end else

    // fecha arquivo
    fclose(arquivo);

} // apresentarUsuario

// ---- usuario ---- //

// ---- calculo ---- //



// calculo de IMC
<<<<<<< HEAD
float calculoIMC(Usuario usuario)
=======
//calculo nao esta como o esperado - nao está mesmo 
float imcCalculo(float altura, float peso)
>>>>>>> bcfa49b67169577e36026cf07a46046ab4a7a33d
{
    float IMC;
    char classificacao;
    // calculo IMC
    IMC = usuario.peso / (usuario.altura * usuario.altura);

    return IMC;

} // imcCalcular

<<<<<<< HEAD
// classifica IMC
void classificacaoIMC()
{

    // trata classificação do IMC
    if (calculoIMC(usuario) < 18.5)
    {
        printf("\nBaixo Peso");
    }
    else if (calculoIMC(usuario) >= 18.5 && calculoIMC(usuario) < 24.9)
    {
        printf("\nPeso Normal");
    }
    else if (calculoIMC(usuario) >= 25 && calculoIMC(usuario) <= 29.9)
    {
        printf("\nSobrepeso");
    }
    else if (calculoIMC(usuario) >= 30 && calculoIMC(usuario) <= 34.9)
    {
        printf("\nObesidade grau I");
    }
    else if (calculoIMC(usuario) >= 35 && calculoIMC(usuario) <= 39.9)
    {
        printf("\nObesidade grau II");
    }
    else if (calculoIMC(usuario) > 40)
    {
        printf("\nObesidade grau III");
    }
    else
        // caso de erro no calculo
        printf("\nErro na calculo do IMC");

} // classifica IMC

// --- TBM ---

// calculo de TBM
float calculoTBM(Usuario usuario)
=======
// calculo de TBM - tbm n fuciona como esperado
float tbmCalculo(float peso, float altura, int idade, char sexo)
>>>>>>> bcfa49b67169577e36026cf07a46046ab4a7a33d
{
    float TBM;

    if (usuario.sexo == 'M')
    {
        TBM = 66.47 + (13.75 * usuario.peso) + (5.003 * usuario.altura) - (6.755 * usuario.idade);
    } // end if
    else if (usuario.sexo == 'F')
    {
        TBM = 655.1 + (9.563 * usuario.peso) + (1.850 * usuario.altura) - (4.676 * usuario.idade);
    } // end if
    else
        printf("Sexo indefinido");

    return TBM;
} // tbmCalculo

// ---- calculo ---- //
