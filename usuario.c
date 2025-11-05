#include "usuario.h"

void cadastroUsuario(Usuario *usuario)
{
    FILE *arquivo;

    // abre para escrita
    arquivo = fopen("usuario.txt", "w");

    if (arquivo == NULL)
        printf("ERRO USUARIO");
    else
    {
        printf("\n === CADASTRO === \n");
        printf("Nome: ");
        scanf(" %[^\n]", usuario->nome);

        printf("Idade: ");
        scanf(" %d", &usuario->idade);

        printf("Altura: ");
        scanf(" %f", &usuario->altura);

        printf("Peso:");
        scanf(" %f", &usuario->peso);

        // trata sexo indefinido
        do
        {
            printf("Sexo: ");
            scanf(" %c", &usuario->sexo);
            if (toupper(usuario->sexo) != 'M' && toupper(usuario->sexo) != 'F')
                printf("Erro indefinido");

        } while (toupper(usuario->sexo) != 'M' && toupper(usuario->sexo) != 'F');

        printf("Cadastro realizado com sucesso!");

        // escreve em arquivo
        fprintf(arquivo, "%s;%d;%f;%f;%c\n", usuario->nome, usuario->idade, usuario->altura, usuario->peso, usuario->sexo);

        fclose(arquivo);
    }

} // end cadastro

int carregarUsuario(Usuario *usuario)
{
    FILE *arquivo;

    // abre arquivo para leitura
    arquivo = fopen("usuario.txt", "r");

    if (arquivo == NULL)
        return 0; // erro

    if (fscanf(arquivo, "%[^;];%d;%f;%f; %c\n", usuario->nome, &usuario->idade, &usuario->altura, &usuario->peso, &usuario->sexo) == 5)
    {
        fclose(arquivo);
        return 1;
    }
    else
        fclose(arquivo);
    return 0; // erro
}

// apresentar
void apresentarUsuario(const Usuario *usuario)
{

    printf("\n === DADOS DE USUARIO === \n");
    printf("Nome: %s\n", usuario->nome);
    printf("Idade: %d\n", usuario->idade);
    printf("Altura: %.2f\n", usuario->altura);
    printf("Peso: %.2f\n", usuario->peso);
    printf("TMB: %.2f\n", calculoTMB(usuario));
    printf("IMC: %.2f\n", calculoIMC(usuario));
} // end apresentar

// Calculo TMB Fórmula de Harris-Benedict
float calculoTMB(const Usuario *usuario)
{
    float TMB = 0;
    float alturaCM = usuario->altura * 100;

    if (toupper(usuario->sexo) == 'M')
        TMB = 88.362 + (13.397 * usuario->peso) + (4.799 * alturaCM) - (5.677 * usuario->idade);
    else if (toupper(usuario->sexo) == 'F')
        TMB = 447.593 + (9.247 * usuario->peso) + (3.098 * alturaCM) - (4.330 * usuario->idade);
    else
        // erro
        TMB = -1;

    return TMB;
} // calculo TMB

// calculo IMC
float calculoIMC(const Usuario *usuario)
{
    float IMC = 0;

    IMC = usuario->peso / (usuario->altura * usuario->altura);

    return IMC;
} // end calculoIMC