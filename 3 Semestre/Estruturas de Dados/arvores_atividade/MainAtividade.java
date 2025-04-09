
import java.util.Random;

public class MainAtividade {
    public static void main(String[] args) {
        ArvoreBinariaBusca arvore = new ArvoreBinariaBusca();
        Random gerador = new Random();


        for (int i = 0; i < 10; i++) {
            arvore.inserir(gerador.nextInt(1000_0000, 9999_9999));
        }

        arvore.emOrdem();
    }
}
