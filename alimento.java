import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

class Alimento {

    private String nome;
    private double carboidrato;
    private double proteina;
    private double gordura;

    // construtor
    public Alimento() {
        this.nome = "";
        carboidrato = 0;
        proteina = 0;
        gordura = 0;
    };

    public Alimento(String n, double c, double p, double g) {
        nome = n;
        carboidrato = c;
        proteina = p;
        gordura = g;
    }

    // setters
    public void setNome(String n) {
        nome = n;
    }

    public void setCarboidrato(double c) {
        carboidrato = c;
    }

    public void setProteina(double p) {
        proteina = p;
    }

    public void setGordura(double g) {
        gordura = g;
    }

    // gettes
    public String getNome() {
        return nome;
    }

    public double getCarboidrato() {
        return carboidrato;
    }

    public double getProteina() {
        return proteina;
    }

    public double getGordura() {
        return gordura;
    }

    public void salvar() {

        try (FileWriter fw = new FileWriter("Alimento.txt", true); PrintWriter pw = new PrintWriter(fw)) {

            pw.println(nome + ";" + carboidrato + ";" + proteina + ";" + gordura);

        } catch (IOException e) {
            System.out.println("Erro no arquivo: " + e.getMessage());
        }

    }

    public void imprimir() {

        System.out
                .println("Alimento: " + nome + " Carboidrato: " + carboidrato + " Proteina: " + proteina + " Gordura: "
                        + gordura);

    }

}