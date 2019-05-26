import java.io.*;
import java.util.Scanner;
import java.util.stream.StreamSupport;

public class BST {
    Node root;
    int size = 0;

    static class Node {
        int key;
        Node left, right, parent;
    }

    public Node add(Node vertex, int elem) { //without .parent

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
        return vertex;
    }

    public int size() {
        return size;
    }

    public void clear() {
        size = 0;
        root = null;
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


    public Node delete(int elem, Node vertex) {
        //System.out.print(elem);System.out.print(" ");System.out.println(vertex.key);
        if (vertex == null) return vertex;
        if (elem < vertex.key) {
            vertex.left = delete(elem, vertex.left);
        } else if (elem > vertex.key) {
            vertex.right = delete(elem, vertex.right);
        }

        else if (vertex.left != null && vertex.right != null) {
            vertex.key = min(vertex.right).key;
            vertex.right = delete(vertex.key, vertex.right);
        //}// else if (vertex.left == null && vertex.right == null) {
          //  vertex = null;
         //   return vertex;
        } else {
            if (vertex.left != null) {
                vertex = vertex.left;
            } else {
                vertex = vertex.right;
            }
        }


        return vertex;
    }

    public Node Prev(Node elem, Node par, BST bst) {
        if (elem.left != null)
            return max(elem.left);
        Node y = par;
        while (y != null && elem == y.left) {
            elem = y;
            y = bst.findParent(y.key, bst.root);
        }
        return y;
    }

    public Node Next(Node elem, Node par, BST bst) {
        if (elem.right != null)
            return min(elem.right);
        Node y = par;
        while (y != null && elem == y.right) {
            elem = y;
            y = bst.findParent(y.key, bst.root);
        }
        return y;
    }
  /* public Node Next(Node elem, Node root) {
       private Node current = root;
       Node successor = null;                // root — корень дерева
       while (current != null) {
           if (current.key > elem.key) {
               successor = current;
               current = current.left;
           }else
               current = current.right;
       }
       if (successor != null) return successor
   }*/

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

    public void inorderTraversal(Node vertex) {
        if (vertex != null) {
            inorderTraversal(vertex.left);
            System.out.print(vertex.key + " ");
            inorderTraversal(vertex.right);
        }
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

    public void postorderTraversal(Node vertex) {
        if (vertex != null) {
            postorderTraversal(vertex.left);
            postorderTraversal(vertex.right);
            System.out.print(vertex.key + " ");
        }
    }


    public static void main(String[] args) throws IOException {
        BST bst = new BST();
        int isPositive = 1;

        Scanner in = new Scanner(System.in);
        String buf;
        while(in.hasNextLine()){
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
                if (!bst.findBool(value, bst.root)) {
                    bst.root = bst.add(bst.root, value);
                }
                //bst.preorderTraversal(bst.root);
                //System.out.println();

            } else if (comand.equals("exis")) {
                System.out.println(bst.findBool(value, bst.root));

            } else if (comand.equals("prev")) {

                if (bst.findBool(value, bst.root)) {
                    Node b = new Node();
                    b = bst.find(value, bst.root);
                    Node par = new Node();
                    par = bst.findParent(value, bst.root);
                    //System.out.print(b.key + " ");
                    //if (par != null) System.out.println(par.key + " ");

                    Node ans = bst.Prev(b, par, bst);
                    if (ans == null) System.out.println("none");
                    else
                        System.out.println(ans.key);
                } else {
                    bst.root = bst.add(bst.root, value);
                    Node b = new Node();
                    b = bst.find(value, bst.root);
                    Node par = new Node();
                    par = bst.findParent(value, bst.root);
                    Node ans = bst.Prev(b, par, bst);

                    if (ans == null) System.out.println("none");
                    else
                        System.out.println(ans.key);

                    bst.root = bst.delete(value, bst.root);
                }

            } else if (comand.equals("next")) {
                if (bst.findBool(value, bst.root)) {
                    Node b = new Node();
                    b = bst.find(value, bst.root);
                    Node par = new Node();
                    par = bst.findParent(value, bst.root);
                    if (bst.Next(b, par, bst) == null) System.out.println("none");
                    else
                        System.out.println(bst.Next(b, par, bst).key);
                } else {
                    bst.root = bst.add(bst.root, value);
                    Node b = new Node();
                    b = bst.find(value, bst.root);
                    Node par = new Node();
                    par = bst.findParent(value, bst.root);
                    Node ans = bst.Next(b, par, bst);
                    if (ans == null) System.out.println("none");
                    else
                        System.out.println(ans.key);

                    bst.root = bst.delete(value, bst.root);
                }

            } else if (comand.equals("dele")) {

                if (bst.findBool(value, bst.root)) {
                    bst.root = bst.delete(value, bst.root);
                }
                //bst.preorderTraversal(bst.root);
                //System.out.println();


            } else if (comand.equals("prin")){
                bst.preorderTraversal(bst.root);
                System.out.println();
            }
           // buf = bf.readLine();
        }

    }

}
