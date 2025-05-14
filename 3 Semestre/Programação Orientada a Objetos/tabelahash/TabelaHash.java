
import java.util.HashMap;

public class TabelaHash {
    public static void main(String[] args) {
        HashMap<String, Integer> notas = new HashMap<>();

        // Inserindo valores
        notas.put("Ana", 9);
        notas.put("Carlos", 7);
        notas.put("Beatriz", 10);

        // Acessando um valor
        System.out.println("Nota da Ana: " + notas.get("Ana"));

        // Verificando se existe uma chave
        if (notas.containsKey("Carlos")){
            System.out.println("Carlos está no mapa");
        }
        for (String nome : notas.keySet()){
            System.out.println(nome + " tirou nota " + notas.get(nome));
        }
    }
}