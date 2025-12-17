import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

class Alimento {

    private String nome;
    private float carboidarato;
    private float proteina;
    private float gordura;

    // construtor
    public Alimento() {
        this.nome = "";
        carboidarato = 0;
        proteina = 0;
        gordura = 0;
    };

    public Alimento(String n, float c, float p, float g) {
        nome = n;
        carboidarato = c;
        proteina = p;
        gordura = g;
    }

    // setters
    public void setNome(String n) {
        nome = n;
    }

    public void setCarboidrato(float c) {
        carboidarato = c;
    }

    public void setProteina(float p) {
        proteina = p;
    }

    public void setGordura(float g) {
        gordura = g;
    }

    // gettes
    public String getNome() {
        return nome;
    }

    public float getCarboidrato() {
        return carboidarato;
    }

    public float getProteina() {
        return proteina;
    }

    public float getGordura() {
        return gordura;
    }

    // Método de cadastro
    public void cadastroALimento(Alimento alimento) {

        // abre arquivo, ou cria caso n exista
        try (FileWriter fw = new FileWriter("ALimento.txt", true); PrintWriter pw = new PrintWriter(fw)) {

            // escreve em arquivo
            pw.println(alimento.getNome() + ";" + alimento.getCarboidrato() + ";" + alimento.getProteina() + ";"
                    + alimento.getGordura());

        } catch (IOException e) {
            System.out.println("Erro no arquivo!");
        }
    }// end cadastroAlimento

    public void listarAlimento(Alimento alimento, int total) {



    }

}