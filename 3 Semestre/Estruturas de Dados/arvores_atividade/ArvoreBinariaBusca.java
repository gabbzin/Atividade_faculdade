public class ArvoreBinariaBusca {
    No raiz;

    // Inserindo na árvore
    public void inserir(int valor){
        raiz = inserirRec(raiz, valor);
    }

    private No inserirRec(No raiz, int valor){
        if (raiz == null) { // Se a raiz não tiver nada
            return new No(valor);
        }

        if(valor < raiz.valor){ // Verifica se o valor é menor que a raiz
            raiz.esquerda = inserirRec(raiz.esquerda, valor);
        } else if(valor > raiz.valor){
            raiz.direita = inserirRec(raiz.direita, valor);
        }

        return raiz;
    }

    public void emOrdem(){
        emOrdemRec(raiz);
    }

    private void emOrdemRec(No raiz){
        if (raiz != null){
            emOrdemRec(raiz.esquerda);
            System.out.println(raiz.valor);
            emOrdemRec(raiz.direita);
        }
    }
}
