import java.util.ArrayList;
import java.util.List;

public class AVLTree<K extends Comparable<K>> {

    private static class Node<K> {
        K key;
        Node<K> left, right;
        int height;

        Node(K key) {
            this.key = key;
            this.height = 1;
        }
    }

    private Node<K> root;
    private int size;

    public int size() { return size; }
    public boolean isEmpty() { return root == null; }

    private int height(Node<K> n) { return n == null ? 0 : n.height; }

    private int balanceFactor(Node<K> n) {
        return n == null ? 0 : height(n.left) - height(n.right);
    }

    private void updateHeight(Node<K> n) {
        n.height = 1 + Math.max(height(n.left), height(n.right));
    }

    private Node<K> rotateRight(Node<K> y) {
        Node<K> x = y.left;
        Node<K> t2 = x.right;
        x.right = y;
        y.left = t2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    private Node<K> rotateLeft(Node<K> x) {
        Node<K> y = x.right;
        Node<K> t2 = y.left;
        y.left = x;
        x.right = t2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    private Node<K> rebalance(Node<K> n) {
        updateHeight(n);
        int bf = balanceFactor(n);
        if (bf > 1) {
            if (balanceFactor(n.left) < 0) {
                n.left = rotateLeft(n.left);
            }
            return rotateRight(n);
        }
        if (bf < -1) {
            if (balanceFactor(n.right) > 0) {
                n.right = rotateRight(n.right);
            }
            return rotateLeft(n);
        }
        return n;
    }

    public void insert(K key) {
        root = insert(root, key);
    }

    private Node<K> insert(Node<K> n, K key) {
        if (n == null) {
            size++;
            return new Node<>(key);
        }
        int cmp = key.compareTo(n.key);
        if (cmp < 0) n.left = insert(n.left, key);
        else if (cmp > 0) n.right = insert(n.right, key);
        else return n;
        return rebalance(n);
    }

    public boolean contains(K key) {
        Node<K> n = root;
        while (n != null) {
            int cmp = key.compareTo(n.key);
            if (cmp == 0) return true;
            n = cmp < 0 ? n.left : n.right;
        }
        return false;
    }

    public void remove(K key) {
        root = remove(root, key);
    }

    private Node<K> remove(Node<K> n, K key) {
        if (n == null) return null;
        int cmp = key.compareTo(n.key);
        if (cmp < 0) n.left = remove(n.left, key);
        else if (cmp > 0) n.right = remove(n.right, key);
        else {
            size--;
            if (n.left == null || n.right == null) {
                return n.left != null ? n.left : n.right;
            }
            Node<K> succ = minNode(n.right);
            n.key = succ.key;
            size++;
            n.right = remove(n.right, succ.key);
        }
        return rebalance(n);
    }

    private Node<K> minNode(Node<K> n) {
        while (n.left != null) n = n.left;
        return n;
    }

    public List<K> inorder() {
        List<K> out = new ArrayList<>();
        inorder(root, out);
        return out;
    }

    private void inorder(Node<K> n, List<K> out) {
        if (n == null) return;
        inorder(n.left, out);
        out.add(n.key);
        inorder(n.right, out);
    }

    public int height() { return height(root); }

    public static void main(String[] args) {
        AVLTree<Integer> t = new AVLTree<>();
        int[] keys = {10, 20, 30, 40, 50, 25, 5, 1, 35, 45};
        for (int k : keys) t.insert(k);

        System.out.println("Inorder: " + t.inorder());
        System.out.println("Altura: " + t.height());
        System.out.println("Tamanho: " + t.size());
        System.out.println("Contém 25? " + t.contains(25));
        System.out.println("Contém 99? " + t.contains(99));

        t.remove(30);
        t.remove(40);
        System.out.println("Após remover 30 e 40: " + t.inorder());
        System.out.println("Altura: " + t.height());
    }
}
