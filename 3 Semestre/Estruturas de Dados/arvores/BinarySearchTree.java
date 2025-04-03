public class BinarySearchTree{
    Node root;

    // Inserir a árvore
    void insert(int value){
        root = insertRec(root, value);
    }

    Node insertRec(Node root, int value){
        if (root == null){ // Verifica se o root primário é nulo
            return new Node(value);
        }

        if (value < root.value){ // Verifica se o filho vai para à esquerda
            root.left = insertRec(root.left, value);
        } else if (value > root.value){ // Verifica se o filho vai para à direita
            root.right = insertRec(root.right, value);
        }

        return root;
    }

    // Irmpressão em ordem (in-order transversal)
    void inorder(){
        inOrderRec(root);
    }

    void inOrderRec(Node root){
        if (root != null){
            inOrderRec(root.left);
            System.out.println(root.value);
            inOrderRec(root.right);
        }
    }
}