

public class HeapMaximo {

    private final int[] Heap;
    private int tamanho;
    private final int tamanhoMaximo;

    public HeapMaximo(int tamanhoMaximo) {
        this.tamanhoMaximo = tamanhoMaximo;
        this.tamanho = 0;
        Heap = new int[this.tamanhoMaximo + 1];
        Heap[0] = Integer.MAX_VALUE;
    }

    private int noPai(int pos) {
        return pos / 2;
    }

    private int filhoAEsquerda(int pos) {
        return (2 * pos);
    }

    private int filhoADireita(int pos) {
        return 2 * pos + 1;
    }

    private boolean ehNoFolha(int pos) {
        return pos >= (tamanho / 2) && pos <= tamanho;
    }

    private void trocarPosicoes(int pos1, int pos2) {
        int tmp = Heap[pos1];
        Heap[pos1] = Heap[pos2];
        Heap[pos2] = tmp;
    }

    public void repararHeap(int pos) {
        if (ehNoFolha(pos)) return;
        int esq = filhoAEsquerda(pos);
        int dir = filhoADireita(pos);
        int maior = pos;

        if (esq <= this.tamanhoMaximo && Heap[esq] > Heap[pos])
            maior = esq;

        if (dir <= this.tamanhoMaximo && Heap[dir] > Heap[maior])
            maior = dir;

        if (maior != pos) {
            trocarPosicoes(pos, maior);
            repararHeap(maior);
        }
    }

    public void construirDeBaixoParaCima() {
        for (int i = this.tamanho / 2; i >= 1; --i) {
            int pai = i;
            int valorPai = Heap[pai];
            boolean ehHeap = false;

            while (!ehHeap && 2 * pai <= this.tamanho) {
                int filho = 2 * pai;

                if (filho < this.tamanho) {
                    if (Heap[filho] < Heap[filho + 1]) filho++;
                }

                if (valorPai >= Heap[filho]) {
                    ehHeap = true;
                } else {
                    Heap[pai] = Heap[filho];
                    pai = filho;
                }
                Heap[pai] = valorPai;
            }
        }
    }

    public void inserir(int elemento) {
        if (tamanho >= tamanhoMaximo) {
            throw new OutOfMemoryError("O limite do heap já foi alcançado");
        }

        Heap[++tamanho] = elemento; // Adicionando elemento ao Heap no último elemento
        int pos = tamanho;

        while (pos > 1 && Heap[pos] > Heap[noPai(pos)]){
            trocarPosicoes(pos, noPai(pos));
            pos = noPai(pos);
        }

    }

    public int removerMaximo() {
        if (tamanho == 0){
            throw new IllegalStateException("O Heap está vazio");
        }

        int valorRemovido = Heap[1];
        Heap[1] = Heap[tamanho];
        tamanho--;

        repararHeap(1);

        return valorRemovido;
    }

    public void imprimirHeap(){
        for (int i = 1; i <= tamanho; i++){
            System.out.print(Heap[i] + " ");
        }

        System.out.println("");
    }

    public static void main(String[] arg) {
        // Construção do Heap a partir da lista: 5, 3, 17, 10, 84, 19, 6, 22, 9
        HeapMaximo maxHeap = new HeapMaximo(15);

        maxHeap.inserir(5);
        maxHeap.inserir(3);
        maxHeap.inserir(17);
        maxHeap.inserir(10);
        maxHeap.inserir(84);
        maxHeap.inserir(19);
        maxHeap.inserir(6);
        maxHeap.inserir(22);
        maxHeap.inserir(9);
        // Valor máximo: 84
        System.out.println("O valor máximo do heap é: " + maxHeap.removerMaximo());
        maxHeap.imprimirHeap();
    }
}