// bibliotecas básicas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int opcao;
    bool cadastrado = false;

    // prototipo menu
    do
    {
        printf("\n     --- MENU --- \n");
        printf("1 - Cadastrar Pessoa\n");
        printf("2 - Cadastrar Receita\n");
        printf("3 - \n");
        printf("4 - Listar Receitas Cadastradas\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

    } while (opcao != 0);
    

} // fim main