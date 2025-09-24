#include "usuario.h"
#include<string.h>


void cadastroUsuario()
{
    FILE *arquivo;

    // abre arquivo para gravação
    arquivo = fopen("usuario.txt", "w");

    // trata erro na gravação
    if (arquivo == NULL)
    {
        printf("\nErro ao gravar em arquivo!");
    }
    else
    {
        // menu base cadastro
        printf("\n ---MENU DE CADASTRO ---\n");
        printf("\nNome: ");
        fgets(usuario.nome, 50, stdin);
        //Remove quebra de linha
        usuario.nome[strcspn(usuario.nome, "\n")] = 0;
        do
        {
            printf("\nSexo: ");
            scanf(" %c", &usuario.sexo);

            // trata sexo indefinido
            if (usuario.sexo != 'M' && usuario.sexo != 'F')
            {
                printf("\nSexo Indefinido!");
            }

        } while (usuario.sexo != 'M' && usuario.sexo != 'F');
        printf("\nIdade: ");
        scanf("%d", &usuario.idade);
        printf("\nPeso: ");
        scanf("%f", &usuario.peso);
        printf("\nAltura: ");
        scanf("%f", &usuario.altura);

        // grava em arquivo
        fprintf(arquivo, "%s; %c;%d;%f;%f;\n", usuario.nome, usuario.sexo, usuario.idade, usuario.peso, usuario.altura);
    } // end else

    // fecha arquivo
    fclose(arquivo);

} // end cadastroUsuario

void apresentarUsuario()
{
    FILE *arquivo;

    // abre arquivo para leitura
    arquivo = fopen("usuario.txt", "r");

    // trata erro na leitura
    if (arquivo == NULL)
    {
        printf("\nErro na leitura de arquivo");
    }
    else
    {
        fscanf(arquivo, "%[^;],%c,%d,%f,%f", usuario.nome, usuario.sexo, usuario.idade, usuario.peso, usuario.peso); // %[^;] lê até o ;
        printf("\n --- USUARIO ---\n");
        printf("Nome: %s", &usuario.nome);
        printf("\nSexo: %c", usuario.sexo);
        printf("\nIdade: %d", &usuario.idade);
        printf("\nPeso: %f", &usuario.peso);
        printf("\nAltura: %f", &usuario.altura);
    } // end else

} // end apresentarUsuario