public class Node { // Classe dos nós da arvore
    int value;
    Node left; // Valor alocado à esquerda
    Node right; // Valor alocado à direita

    public Node(int value) { // Construtor do Node
        this.value = value;
        left = right = null;
    }
}