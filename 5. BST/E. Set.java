import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Set {
    Node root;
    static class Node {
        long key;
        Node left, right;
        int balance = 0;
    }

    private static int balance(Node t) {
        if (t == null) return -1;
        else return t.balance;
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

    public Node rotateRight(Node b) {
        Node a = b.left;
        b.left = a.right;
        a.right = b;
        b.balance = Math.max(balance(b.left), balance(b.right)) + 1;
        a.balance = Math.max(balance(a.left), b.balance) + 1;
        return a;
    }

    public Node add(Node vertex, long elem) {
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


    public long postorderTraversal(Node vertex, long inLeft, long inRight) {
        if (vertex != null){
            if (vertex.key >= inLeft && vertex.key <= inRight){
                return vertex.key + postorderTraversal(vertex.right, inLeft, inRight) + postorderTraversal(vertex.left, inLeft, inRight);
            } else if (vertex.key < inLeft){
                return postorderTraversal(vertex.right, inLeft, inRight);
            } else if (vertex.key > inRight){
                return postorderTraversal(vertex.left, inLeft, inRight);
            }
        }
        return 0;
    }

    public void preorderTraversal(Node vertex) {
        if (vertex != null) {
            System.out.print(vertex.key + " ");
            preorderTraversal(vertex.left);
            preorderTraversal(vertex.right);
        }
    }

    public static void main(String[] args) throws IOException {
        Set set = new Set();
        long importantSum = 0;
        Scanner in = new Scanner(System.in);
        String buf;
        boolean flag = false;
        String nn = "";
        nn = in.nextLine();
        int ops = 0;
        long n = 0;
        while(ops < nn.length()){
            n = n * 10 + (nn.charAt(ops) - '0');
            ops++;
        }


        for (long qq = 0; qq < n; qq++){
            buf = in.nextLine();
            String comand = buf.substring(0, 1);
            int i = 1;
            while (buf.charAt(i) != ' ') i++;
            i++;
            while (buf.charAt(i) == ' ') i++;
            if (buf.charAt(i) == ' ') i++;


            if (comand.equals("+")){
                long isPositive = 1;
                long value = 0;
                if (buf.charAt(i) == '-') {
                    isPositive = -1;
                    i++;
                }
                while (i < buf.length()) {
                    value = value * 10 + (buf.charAt(i) - '0');
                    i++;
                }
                value = value * isPositive;

                if (flag) {//идет после ?, добавляем вместе с суммой
                    value = (value  + importantSum) % 1000000000;
                    set.root = set.add(set.root, value);
                    flag = false;
                } else {
                    set.root = set.add(set.root, value);
                    flag = false;
                }
            } else if (comand.equals("?")){
                flag = true;
                long indLeft = 0, indRight = 0;
                long isPositive = 1;
                long value = 0;
                if (buf.charAt(i) == '-') {
                    isPositive = -1;
                    i++;
                }
                while (buf.charAt(i) != ' ') {
                    value = value * 10 + (buf.charAt(i) - '0');
                    i++;
                }
                indLeft = value * isPositive;
                if (buf.charAt(i) == ' ') i++;
                isPositive = 1;
                value = 0;
                if (buf.charAt(i) == '-') {
                    isPositive = -1;
                    i++;
                }
                while (i < buf.length()) {
                    value = value * 10 + (buf.charAt(i) - '0');
                    i++;
                }
                indRight = value * isPositive;

                importantSum = set.postorderTraversal(set.root, indLeft, indRight);
                System.out.println(importantSum);

            } else if (comand.equals("s")){
                set.preorderTraversal(set.root);
            }
        }
    }
}
