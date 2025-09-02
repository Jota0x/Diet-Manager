// bibliotecas básicas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// headers
#include "usuario.h"
#include "alimento.h"

int main()
{
    int opcao;
    bool cadastrado = false;

    // prototipo menu --- teste menu --- OK
    do
    {
        printf("\n     --- MENU --- \n");
        printf("1 - Cadastro de usario\n");
        printf("2 - Dados Usuario\n");
        printf("3 - \n");
        printf("4 - Listar Receitas Cadastradas\n");
        printf("0 - Sair do programa");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarUsuario();

            break;
        case 2:
            apresentarUsuario();
            break;

        default:
            break;
        }

    } while (opcao != 0);

} // fim main