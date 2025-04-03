public class Main {
    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree(); // Instanciando a árvore

        bst.insert(44);
        bst.insert(11);
        bst.insert(60);
        bst.insert(20);
        bst.insert(80);
        bst.insert(77);

        System.out.println("Inorder transversal da árvore: ");
        bst.inorder();
    }
}
