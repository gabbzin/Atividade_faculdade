
import java.util.PriorityQueue;

public class FilaPrioridade {
    public static void main(String[] args) {
        PriorityQueue<Integer> fila = new PriorityQueue<>();

        // Adicionando elementos
        fila.add(10);
        fila.add(5);
        fila.add(20);
        fila.add(1);
        fila.add(30);

        System.out.println("Elementos estão em ordem crescente");

        while (!fila.isEmpty()){
            System.out.println(fila.poll());
        }
    }
}