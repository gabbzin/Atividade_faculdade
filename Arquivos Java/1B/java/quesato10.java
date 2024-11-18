import java.util.Scanner;
public class MaiorNumeroArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite o número de elementos do array: ");
        int tamanho = scanner.nextInt();
        int[] numeros = new int[tamanho];
        for (int i = 0; i < tamanho; i++) {
            System.out.print("Digite o número " + (i + 1) + ": ");
            numeros[i] = scanner.nextInt();
        }
        int maior = numeros[0];
        for (int i = 1; i < tamanho; i++) {
            if (numeros[i] > maior) {
                maior = numeros[i];
            }
        }
        System.out.println("O maior número do array é: " + maior);
    }
}
