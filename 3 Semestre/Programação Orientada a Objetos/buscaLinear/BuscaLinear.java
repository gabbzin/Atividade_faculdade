public class BuscaLinear {
    public static int busca(int [] array, int valor){
        for (int i = 0; i < array.length; i++){
            if (array[i] == valor){
                return i;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] numeros = {10,20,30,40,50,60,70};
        int indice = busca(numeros, 30);
        System.out.println("Indice encontrado: " + indice);
    }
}