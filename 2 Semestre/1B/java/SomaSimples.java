import java.util.Scanner;

public class SomaSimples { // Questão 1
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite o primeiro número: ");
        int num1 = scanner.nextInt();
        System.out.print("Digite o segundo número: ");
        int num2 = scanner.nextInt();
        int soma = num1 + num2;
        System.out.println("A soma é: " + soma);
        scanner.close();
    }
}
