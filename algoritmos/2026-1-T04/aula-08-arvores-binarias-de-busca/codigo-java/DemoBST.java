/**
 * Demonstração de uso da BST genérica.
 *
 * Para compilar e executar (Java 17+):
 *   javac BST.java DemoBST.java
 *   java DemoBST
 */
public class DemoBST {

    public static void main(String[] args) {
        BST<Integer, String> arv = new BST<>();

        // Inserção
        int[] chaves = {15, 6, 18, 3, 7, 17, 20, 13, 9};
        for (int k : chaves) arv.put(k, "v" + k);

        System.out.println("Tamanho:  " + arv.size());        // 9
        System.out.println("Altura:   " + arv.height());
        System.out.println("Mínimo:   " + arv.min());         // 3
        System.out.println("Máximo:   " + arv.max());         // 20
        System.out.println("get(13):  " + arv.get(13));       // v13
        System.out.println("get(42):  " + arv.get(42));       // null
        System.out.println("In-order: " + arv.keysInOrder());

        // Remoção (caso 3: 6 tem dois filhos)
        arv.delete(6);
        System.out.println("\nApós delete(6):");
        System.out.println("Tamanho:  " + arv.size());        // 8
        System.out.println("In-order: " + arv.keysInOrder()); // ainda ordenado

        // BST com chaves String
        BST<String, Integer> freq = new BST<>();
        for (String w : "the quick brown fox jumps over the lazy dog".split(" ")) {
            Integer c = freq.get(w);
            freq.put(w, (c == null) ? 1 : c + 1);
        }
        System.out.println("\nFrequência de palavras (in-order): " + freq.keysInOrder());
        System.out.println("freq[the] = " + freq.get("the"));
    }
}
