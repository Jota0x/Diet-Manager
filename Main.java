import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner dado = new Scanner(System.in);

        final int MAX_ALIMENTOS = 100; // define tamanho maximo do vetor
        Alimento[] lista = new Alimento[MAX_ALIMENTOS]; // cria vetor
        int n = 0; // variavel de controle

        int opcao;

        do {
            System.out.println("--- MENU OPCAO --- \n");
            System.out.println("1 - Usuario\n");
            System.out.println("2 - Cadastrar\n");
            System.out.println("3 - Listar\n");

            opcao = dado.nextInt();
            dado.nextLine();

            switch (opcao) {
                case 1:
                    break;
                case 2:

                    if (n < MAX_ALIMENTOS) {
                        System.out.println(" --- CADASTRO ---\n");
                        System.out.println("Nome: ");
                        String nome = dado.nextLine();
                        System.out.println("\nCarboidrato: ");
                        double carboidrato = dado.nextDouble();
                        System.out.println("\n Proteina: ");
                        double proteina = dado.nextDouble();
                        System.out.println("\n Gordura: ");
                        double gordura = dado.nextDouble();

                        System.out.println("\n Cadastro realizado!");

                        dado.nextLine();

                        Alimento novoAlimento = new Alimento(nome, carboidrato, proteina, gordura);

                        lista[n] = novoAlimento;
                        n++;

                        novoAlimento.salvar();

                        System.out.println("Salvo com sucesso!");
                    } else
                        System.out.println("Vetor cheio!");

                case 3:
                    System.out.println(" --- LISTA DE ALIMENTOS --- \n");

                    for (int i = 0; i < lista.length; i++)
                        lista[i].imprimir();

                    break;
                default:
                    System.out.println("Opcao invalida!");

            }

        } while (opcao != 0);
    }
}
