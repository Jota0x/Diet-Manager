// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>
#include "usuario.h"

//VEREIFICAR PARAMETROS
int main()
{
    SetConsoleOutputCP(65001);

    setlocale(LC_ALL, "pt_BR.UTF-8");

    int opcao;
    // variavel de controle de usuario
    bool usuario = false;

    // menu
    do
    {
        // modificar futuramente
        printf("\n   --- MENU --- \n");
        printf("\n 1 - Usuário");
        printf("\n 2 - Adicionar Alimento");
        printf("\n 3 - Adicionar Refeição");
        printf("\n 4 - Registro de Refeição");
        printf("\n 0 - Sair");
        printf("\n Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            // trata usuario
            if (usuario == FALSE)
            {
                cadastroUsuario();
                usuario == true;
            }
            else if (usuario == TRUE)
            {
                apresentarUsuario();
            }
            else
                printf("ERRO USUARIO");
            break;

        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            break;
        default:
            printf("\n Opção inválida!");
            break;
        }

    } while (opcao != 0);

} // end main