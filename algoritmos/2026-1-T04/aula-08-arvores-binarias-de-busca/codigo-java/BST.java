import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

/**
 * Árvore Binária de Busca (BST) genérica.
 *
 * Mapeia chaves Key (Comparable) a valores Value, como um dicionário ordenado.
 * Estilo Sedgewick (Algorithms in Java, cap. 12): inserção recursiva que
 * retorna a subárvore modificada; remoção por Hibbard (sucessor in-order).
 *
 * Complexidade: O(h) por operação, onde h é a altura.
 *   - Árvore balanceada por inserções aleatórias: h = O(log n) esperado.
 *   - Pior caso (inserções ordenadas): h = n - 1 (degenera em lista).
 *
 * @param <Key>   tipo da chave (deve ser Comparable)
 * @param <Value> tipo do valor associado
 */
public class BST<Key extends Comparable<Key>, Value> {

    /** Nó interno da árvore. */
    private static final class Node<K, V> {
        K key;
        V value;
        Node<K, V> left, right;
        int size;                    // tamanho da subárvore (Sedgewick)

        Node(K key, V value) {
            this.key = key;
            this.value = value;
            this.size = 1;
        }
    }

    private Node<Key, Value> root;

    // ---------- Tamanho ----------

    public int size() {
        return size(root);
    }

    private int size(Node<Key, Value> x) {
        return (x == null) ? 0 : x.size;
    }

    public boolean isEmpty() {
        return root == null;
    }

    // ---------- Busca (CLRS TREE-SEARCH iterativo) ----------

    public Value get(Key key) {
        if (key == null) throw new IllegalArgumentException("chave nula");
        Node<Key, Value> x = root;
        while (x != null) {
            int cmp = key.compareTo(x.key);
            if      (cmp < 0) x = x.left;
            else if (cmp > 0) x = x.right;
            else              return x.value;
        }
        return null;
    }

    public boolean contains(Key key) {
        return get(key) != null;
    }

    // ---------- Inserção (Sedgewick: recursiva retornando subárvore) ----------

    public void put(Key key, Value value) {
        if (key == null) throw new IllegalArgumentException("chave nula");
        root = put(root, key, value);
    }

    private Node<Key, Value> put(Node<Key, Value> x, Key key, Value value) {
        if (x == null) return new Node<>(key, value);
        int cmp = key.compareTo(x.key);
        if      (cmp < 0) x.left  = put(x.left,  key, value);
        else if (cmp > 0) x.right = put(x.right, key, value);
        else              x.value = value;                  // atualiza
        x.size = 1 + size(x.left) + size(x.right);
        return x;
    }

    // ---------- Mínimo / Máximo (CLRS TREE-MINIMUM/MAXIMUM) ----------

    public Key min() {
        if (isEmpty()) throw new NoSuchElementException("BST vazia");
        return min(root).key;
    }

    private Node<Key, Value> min(Node<Key, Value> x) {
        return (x.left == null) ? x : min(x.left);
    }

    public Key max() {
        if (isEmpty()) throw new NoSuchElementException("BST vazia");
        Node<Key, Value> x = root;
        while (x.right != null) x = x.right;
        return x.key;
    }

    // ---------- Remoção do mínimo (passo auxiliar de Hibbard) ----------

    public void deleteMin() {
        if (isEmpty()) throw new NoSuchElementException("BST vazia");
        root = deleteMin(root);
    }

    private Node<Key, Value> deleteMin(Node<Key, Value> x) {
        if (x.left == null) return x.right;
        x.left = deleteMin(x.left);
        x.size = 1 + size(x.left) + size(x.right);
        return x;
    }

    // ---------- Remoção (Hibbard: substitui pelo sucessor in-order) ----------

    public void delete(Key key) {
        if (key == null) throw new IllegalArgumentException("chave nula");
        root = delete(root, key);
    }

    private Node<Key, Value> delete(Node<Key, Value> x, Key key) {
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        if      (cmp < 0) x.left  = delete(x.left,  key);
        else if (cmp > 0) x.right = delete(x.right, key);
        else {
            // Casos 1 e 2: nó com 0 ou 1 filho
            if (x.right == null) return x.left;
            if (x.left  == null) return x.right;
            // Caso 3: nó com 2 filhos — substitui por sucessor in-order
            Node<Key, Value> t = x;
            x = min(t.right);                 // sucessor
            x.right = deleteMin(t.right);     // remove o sucessor da subárvore direita
            x.left  = t.left;
        }
        x.size = 1 + size(x.left) + size(x.right);
        return x;
    }

    // ---------- Travessia in-order (chaves em ordem crescente) ----------

    public Iterable<Key> keysInOrder() {
        List<Key> out = new ArrayList<>();
        inorder(root, out);
        return out;
    }

    private void inorder(Node<Key, Value> x, List<Key> out) {
        if (x == null) return;
        inorder(x.left,  out);
        out.add(x.key);
        inorder(x.right, out);
    }

    // ---------- Altura (útil para análise) ----------

    public int height() {
        return height(root);
    }

    private int height(Node<Key, Value> x) {
        if (x == null) return -1;
        return 1 + Math.max(height(x.left), height(x.right));
    }
}
