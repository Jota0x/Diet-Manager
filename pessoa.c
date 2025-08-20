#include <pessoa.h>

// cadastro de pessoa --- SEM TESTE!
void cadastrarPessoa()
{
    // criação arquivo
    FILE *arquivo;

    // abre arquivo para a gravação(escrita)
    arquivo = fopen("teste.dat", 'wb');

    // mensagem de erro caso arquivo esteje vazio
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
    }
    else
    {
        // limpa buffer para leitura
        fflush(stdin);

        // cadastro de pessoa (com arquivo) - SEM TESTE !!! -
        printf(" \n--- Cadastro de Pessoa ---\n ");
        printf("Nome: \n");
        fgets(pessoa.nome, 50, stdin); // le o nome com espaços, mas deixa \n no final
        printf("Idade: \n");
        scanf("%d", pessoa.idade);
        printf("Sexo: \n");
        scanf(" %c", pessoa.sexo);
        printf("Peso: \n");
        scanf("%f", pessoa.peso);
        printf("Altura: ");
        scanf("%f", pessoa.altura);

        // armazena informações no arquivo
        fprintf(arquivo, "%s;%d;%c;%f;%f\n", pessoa.nome, pessoa.idade, pessoa.sexo, pessoa.peso, pessoa.altura);
    }
    fclose(arquivo);
    // sucesso caso cadastrado
    printf("Dados cadastrados com sucesso!");

} // cadastrarPessoa

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
        TBM = 655, 1 + (9.563 * peso) + (1.850 * altura) - (4.676 * idade);
    } // end if
    else
        printf("Sexo indefinido");

    return TBM;
} // tbmCalculo