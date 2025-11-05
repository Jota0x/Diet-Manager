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
        scanf("%[^\n]", usuario->nome);
        printf("Idade: ");
        scanf("%d", &usuario->idade);
        printf("Altura: ");
        scanf("%f", &usuario->altura);
        printf("Peso:");
        scanf("%f", &usuario->peso);

        // trata sexo indefinido
        do
        {
            printf("Sexo: ");
            scanf(" %c", usuario->sexo);
            if (toupper(usuario->sexo) != 'M' && toupper(usuario->sexo) != 'F')
                printf("Erro indefinido");

        } while (toupper(usuario->sexo) != 'M' && toupper(usuario->sexo) != 'F');

        // escreve em arquivo
        fprintf(arquivo, "%[^\n];%f;%f;%c;%f;%f", usuario->nome, usuario->idade, usuario->altura, usuario->peso, calculoTMB(usuario), calculoIMC(usuario));

        fclose(arquivo);
    }

} // end cadastro

void apresntarUsuario(Usuario *usuario)
{
    FILE *arquivo;

    // abre arquivo para leitura
    arquivo = fopen("usario.txt", "r");

    if (arquivo == NULL)
        printf("ERRO APRESNTACAO");
    else
    {
        if(fscanf(arquivo,""))

    }
}

// Calculo TMB Fórmula de Harris-Benedict
float calculoTMB(Usuario *usuario)
{
    float TMB = 0;

    if (toupper(usuario->sexo) == 'M')
        TMB = 88.362 + (13, 397 * usuario->peso) + (4.799 * usuario->altura) - (5.677 * usuario->idade);
    else if (toupper(usuario->sexo) == 'F')
        TMB = 447, 593 + (9, 247 * usuario->peso) + (3.098 * usuario->altura) - (4.330 * usuario->idade);
    else
        // erro
        TMB = -1;

    return TMB;
} // calculo TMB

// calculo IMC
float calculoIMC(Usuario *usuario)
{
    float IMC = 0;

    IMC = usuario->peso / (usuario->altura * usuario->altura);

    return IMC;
} // end calculoIMC