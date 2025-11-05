// #include "alimento.h"
#include "usuario.h"

int main()
{
    int opcao;
    int usuarioCarregado = carregarUsuario(&usuario);

    printf("\n === INICIANDO DIET MANAGER === \n");

    // trata inicialização de usuario
    if (usuarioCarregado == 0)
    {
        printf("Preparando cadastro...");
        cadastroUsuario(&usuario);
    }
    else
        printf("Usuario %s Carregado com sucesso!", usuario.nome);

    do
    {
        printf("\n ==== MENU ==== \n");
        printf("1 - USUARIO %s\n", usuario.nome);
        printf("2 - ALIMENTO\n");
        // printf("3 - ");
        printf("0 - SAIR\n");
        printf("Opcao: \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            apresentarUsuario(&usuario);
            break;

        case 0:
            printf("Saindo...");
            break;
        default:
            break;
        }

    } while (opcao != 0);

    return 0;

} // end main