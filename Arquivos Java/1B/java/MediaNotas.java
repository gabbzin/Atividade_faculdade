import java.util.Scanner;

public class MediaNotas {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite o número de notas: ");
        int numNotas = scanner.nextInt();
        
        double[] notas = new double[numNotas]; // Array para armazenar as notas
        double soma = 0;
        
        for (int i = 0; i < numNotas; i++) {
            System.out.print("Digite a nota " + (i + 1) + ": ");
            notas[i] = scanner.nextDouble(); // Lê cada nota e armazena no array
            soma += notas[i]; // Soma as notas
        }
        
        double media = soma / numNotas; // Calcula a média
        System.out.println("A média é: " + media);
        
        if (media >= 6) {
            System.out.println("Aprovado");
        } else {
            System.out.println("Reprovado");
        }
    }
}
