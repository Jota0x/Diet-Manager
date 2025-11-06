#include "alimento.h"
#include "usuario.h"
#define MAX_ALIMENTO 500

int main()
{

    int opcao;
    int totalAlimentos = 0;

    Usuario usuario;
    Alimento listaAlimento[MAX_ALIMENTO];

    // carrega "banco de dados"
    int usuarioCarregado;
    int alimentosCarregados = carregarAlimento(listaAlimento, MAX_ALIMENTO);

    printf("\n === INICIANDO DIET MANAGER === \n");

    usuarioCarregado = carregarUsuario(&usuario);
    totalAlimentos = carregarAlimento(listaAlimento, MAX_ALIMENTO);

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
        printf("2 - CADASTRAR ALIMENTO\n");
        printf("3 - LISTAR ALIMENTO\n");
        printf("0 - SAIR\n");
        printf("Opcao: \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            apresentarUsuario(&usuario);
            break;
        case 2:
            cadastroAlimento(listaAlimento, &totalAlimentos);
            break;
        case 3:
            listarAlimento(&listaAlimento[totalAlimentos], totalAlimentos);
            break;
        case 0:
            printf("Saindo...");
            break;
        default:
            printf("OPCAO INVALIDA");
            break;
        }

    } while (opcao != 0);

    return 0;

} // end main