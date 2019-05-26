import java.io.*;
import java.util.Scanner;

public class AVL {
    Node root;
    int size = 0;

    static class Node {
        int key;
        Node left, right, parent;
        int balance = 0;
    }

    private static int balance(Node t) {
        if (t == null) return -1;
        else return t.balance;
    }

    Node findParent(int elem, Node vertex) {
        if (vertex == null) return vertex;
        if (vertex.right != null && vertex.right.key == elem || vertex.left != null && vertex.left.key == elem) {
            return vertex;
        } else if (elem < vertex.key) {
            return findParent(elem, vertex.left);
        } else {
            return findParent(elem, vertex.right);
        }
    }

    public Node find(int elem, Node vertex) {
        if (vertex.key == elem) {
            return vertex;
        } else if (elem < vertex.key) {
            return find(elem, vertex.left);
        } else {
            return find(elem, vertex.right);
        }
    }

    public boolean findBool(int elem, Node vertex) {
        if (vertex == null) {
            return false;
        }
        if (vertex.key == elem) {
            return true;
        } else if (elem <= vertex.key) {
            return findBool(elem, vertex.left);
        } else if (elem > vertex.key) {
            return findBool(elem, vertex.right);
        } else
            return false;
    }

    public Node Prev(Node elem, Node par, AVL avl) {
        if (elem.left != null)
            return max(elem.left);
        Node y = par;
        while (y != null && elem == y.left) {
            elem = y;
            y = avl.findParent(y.key, avl.root);
        }
        return y;
    }

    public Node Next(Node elem, Node par, AVL avl) {
        if (elem.right != null)
            return min(elem.right);
        Node y = par;
        while (y != null && elem == y.right) {
            elem = y;
            y = avl.findParent(y.key, avl.root);
        }
        return y;
    }

    public Node min(Node vertex) {
        while (vertex.left != null) {
            vertex = vertex.left;
        }
        return vertex;
    }

    public Node max(Node vertex) {
        while (vertex.right != null) {
            vertex = vertex.right;
        }
        return vertex;
    }

    public void preorderTraversal(Node vertex) {
        if (vertex != null) {
            System.out.print(vertex.key + " ");
            if (vertex.left != null) System.out.print(vertex.left.key + " ");
            if (vertex.right != null) System.out.println(vertex.right.key + " ");
            preorderTraversal(vertex.left);
            preorderTraversal(vertex.right);
        }
    }

    public Node add(Node vertex, int elem) {
        if (vertex == null) {
            Node nodeBuf = new Node();
            nodeBuf.key = elem;
            nodeBuf.left = nodeBuf.right = null;
            return nodeBuf;
        } else if (elem < vertex.key) {
            vertex.left = add(vertex.left, elem);

        } else if (elem > vertex.key) {
            vertex.right = add(vertex.right, elem);

        }

        vertex.balance = Math.max(balance(vertex.left), balance(vertex.right)) + 1;
        if( balance(vertex.right)-balance(vertex.left) == 2 )
        {
            if( balance(vertex.right.right)-balance(vertex.right.left) < 0 )
                vertex.right = rotateRight(vertex.right);
            return rotateLeft(vertex);
        }

        if( balance(vertex.right)-balance(vertex.left) == -2) {
            if( balance(vertex.left.right)-balance(vertex.left.left) > 0  )
                vertex.left = rotateLeft(vertex.left);
            return rotateRight(vertex);
        }


        return vertex;

    }

    public Node rotateLeft(Node a) {
        Node b = a.right;
        a.right = b.left;
        b.left = a;
        a.balance = Math.max(balance(a.left), balance(a.right));
        a.balance++;
        b.balance = Math.max(balance(b.right), a.balance);
        b.balance++;
        return b;
    }

    public Node bigRotateLeft(Node a) {
        a.left = rotateRight(a.left);
        return bigRotateLeft(a);
    }

    public Node rotateRight(Node b) {
        Node a = b.left;
        b.left = a.right;
        a.right = b;
        b.balance = Math.max(balance(b.left), balance(b.right)) + 1;
        a.balance = Math.max(balance(a.left), b.balance) + 1;
        return a;
    }

    public Node bigRotateRight(Node a) {
        a.right = bigRotateLeft(a.right);
        return bigRotateRight(a);
    }

    int subtract(Node p) {
        return balance(p.right)-balance(p.left);
    }

    void fix(Node p) {
        p.balance = Math.max(balance(p.left), balance(p.right)) + 1;
    }

    Node bal(Node vertex){
        fix(vertex);
        if( subtract(vertex)==2 )
        {
            if( subtract(vertex.right) < 0 )
                vertex.right = rotateRight(vertex.right);
            return rotateLeft(vertex);
        }
        if( subtract(vertex)==-2 )
        {
            if( subtract(vertex.left) > 0  )
                vertex.left = rotateLeft(vertex.left);
            return rotateRight(vertex);
        }
        return vertex;
    }

    Node findMin(Node vertex){
        if (vertex.left != null)
            return findMin(vertex.left);
        else return vertex;
    }

    Node removeMin(Node vertex) {
        if(vertex.left == null)
            return vertex.right;
        vertex.left = removeMin(vertex.left);

        return bal(vertex);
    }

    public Node delete(int elem, Node vertex) {
        //System.out.print(elem);System.out.print(" ");System.out.println(vertex.key);
        if (vertex == null) return vertex;
        if (elem < vertex.key) {
            vertex.left = delete(elem, vertex.left);
        } else if (elem > vertex.key) {
            vertex.right = delete(elem, vertex.right);

        } else {

            Node q = vertex.left;
            Node r = vertex.right;
            vertex = null;
            if (r == null) return q;
            Node minNode = findMin(r);
            minNode.right = removeMin(r);
            minNode.left = q;
            return bal(minNode);

        }
        return bal(vertex);
    }


    public static void main(String[] args) throws IOException {
        AVL avl = new AVL();
        int isPositive = 1;

        Scanner in = new Scanner(System.in);
        String buf;
        while (in.hasNextLine()) {
            buf = in.nextLine();
            // if (buf.isEmpty()) break;;
            isPositive = 1;
            String comand = buf.substring(0, 4);
            int i = 4;
            while (buf.charAt(i) != ' ') {
                i++;
            }
            i++;
            while (buf.charAt(i) == ' ') {
                i++;
            }
            if (buf.charAt(i) == ' ') i++;
            if (buf.charAt(i) == '-') {
                isPositive = -1;
                i++;
            }
            int value = 0;
            while (i < buf.length()) {
                value = value * 10 + (buf.charAt(i) - '0');
                i++;
            }
            value = value * isPositive;


            if (comand.equals("inse")) {
                if (!avl.findBool(value, avl.root)) {
                    avl.root = avl.add(avl.root, value);
                }
                //avl.preorderTraversal(avl.root);
                //System.out.println();

            } else if (comand.equals("exis")) {
                System.out.println(avl.findBool(value, avl.root));

            } else if (comand.equals("prev")) {

                if (avl.findBool(value, avl.root)) {
                    Node b = new Node();
                    b = avl.find(value, avl.root);
                    Node par = new Node();
                    par = avl.findParent(value, avl.root);
                    //System.out.print(b.key + " ");
                    //if (par != null) System.out.println(par.key + " ");

                    Node ans = avl.Prev(b, par, avl);
                    if (ans == null) System.out.println("none");
                    else
                        System.out.println(ans.key);
                } else {
                    avl.root = avl.add(avl.root, value);
                    Node b = new Node();
                    b = avl.find(value, avl.root);
                    Node par = new Node();
                    par = avl.findParent(value, avl.root);
                    Node ans = avl.Prev(b, par, avl);

                    if (ans == null) System.out.println("none");
                    else
                        System.out.println(ans.key);

                    avl.root = avl.delete(value, avl.root);
                }

            } else if (comand.equals("next")) {
                if (avl.findBool(value, avl.root)) {
                    Node b = new Node();
                    b = avl.find(value, avl.root);
                    Node par = new Node();
                    par = avl.findParent(value, avl.root);
                    if (avl.Next(b, par, avl) == null) System.out.println("none");
                    else
                        System.out.println(avl.Next(b, par, avl).key);
                } else {
                    avl.root = avl.add(avl.root, value);
                    Node b = new Node();
                    b = avl.find(value, avl.root);
                    Node par = new Node();
                    par = avl.findParent(value, avl.root);
                    Node ans = avl.Next(b, par, avl);
                    if (ans == null) System.out.println("none");
                    else
                        System.out.println(ans.key);
                    avl.root = avl.delete(value, avl.root);
                }

            } else if (comand.equals("dele")) {
                if (avl.findBool(value, avl.root)) {
                    avl.root = avl.delete(value, avl.root);
                }
            } else if (comand.equals("prin")) {
                avl.preorderTraversal(avl.root);
                System.out.println();
            }
            // buf = bf.readLine();
        }

    }


}
