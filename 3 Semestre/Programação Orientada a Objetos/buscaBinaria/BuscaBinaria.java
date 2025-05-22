public class BuscaBinaria {
    public static int buscar(int[] array, int valor){
        int inicio = 0;
        int fim = array.length - 1;

        while(inicio <= fim){
            int meio = (inicio + fim) / 2;
            if (array[meio] == valor){
                return meio;
            }
            else if (array[meio] < valor){
                inicio = meio + 1;
            }
            else {
                fim = meio - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] numeros = {10,20,30,40,50};
        int indice = buscar(numeros, 50);
        System.out.println("Indice encontrado: " + indice);
    }
}
