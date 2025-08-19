#include <pessoa.h>

// cadastro de pessoa
void cadastrarPessoa()
{
    printf(" --- Cadastro de Pessoa --- ");
    printf("Nome: \n");
    scanf(" %s", pessoa.nome);
    printf("Peso: \n");
    scanf("%f", pessoa.peso);
    printf("Altura: ");
    scanf("%f", pessoa.altura);

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