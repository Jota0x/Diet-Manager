#include "diario.h"

// verifica data
// acho q parametros estão errados --- verificar ---
bool verificarData(Diario diario)
{
    bool dataValida = true;
    // trata dia
    // precisa tratar ano bissexto !!
    if (diario.dia > 31 && diario.dia)
    {
        dataValida = false;
    }
    // trata mes
    if (diario.mes > 12 && diario.mes < 1)
    {
        dataValida = false;
    }

} // verifica data


// FINALIZAR FUNÇÂO
// salva data
void salvaData(Diario diario)
{
    FILE *arquivo;

    arquivo = fopen("diario.txt", "w");

    // trata erro no arquivo
    if (arquivo == NULL)
    {
        printf("\nErro ao abrir arquivo");
    }
    else
    {
        printf("\nDia: ");
        scanf("%d", diario.dia);
        printf("\nMes: ");
        scanf("%d", diario.mes);
        printf("\nAno: ");
        scanf("%d", diario.ano);
    }
} // salva Data

//criação de funções semanal e mensal para diário