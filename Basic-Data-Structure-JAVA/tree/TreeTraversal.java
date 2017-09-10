package interview.tree;

import java.util.ArrayList;
import java.util.List;

public class TreeTraversal {

    public void preOrder(TreeNode root) {
        if(root == null) {
            return;
        }
        System.out.print(root.getValue() + " ");
        preOrder(root.getLeft());
        preOrder(root.getRight());
    }

    public void inOrder(TreeNode root) {
        if(root == null) {
            return;
        }
        inOrder(root.getLeft());
        System.out.print(root.getValue() + " ");
        inOrder(root.getRight());
    }

    public void postOrder(TreeNode root) {
        if(root == null) {
            return;
        }
        postOrder(root.getLeft());
        postOrder(root.getRight());
        System.out.print(root.getValue() + " ");
    }

    public void postOrder(String preOrder, String inOrder) {
        if(preOrder.isEmpty()) {
            return;
        }
        char rootValue = preOrder.charAt(0);
        int rootIndex = inOrder.indexOf(rootValue);
        postOrder(preOrder.substring(1, 1+rootIndex), inOrder.substring(0, rootIndex));
        postOrder(preOrder.substring(1+rootIndex), inOrder.substring(1+rootIndex));
        System.out.print(rootValue + " ");
    }

    public static void main(String[] args) {
        TreeCreator tc = new TreeCreator();
        TreeNode root = tc.createSampleTree();
        TreeTraversal tt = new TreeTraversal();

        tt.preOrder(root);
        System.out.println();
        tt.inOrder(root);
        System.out.println();
        tt.postOrder(root);
        System.out.println();
        System.out.println("==============");
        TreeNode tree = tc.createTree("ABDEGCF", "DBGEACF");
        tt.postOrder(tree);
        System.out.println();
        TreeNode tree1 = tc.createTree("", "");
        tt.postOrder(tree1);
        System.out.println();
        TreeNode tree2 = tc.createTree("A", "A");
        tt.postOrder(tree2);
        System.out.println();
        TreeNode tree3 = tc.createTree("AB", "BA");
        tt.postOrder(tree3);
        System.out.println();
        System.out.println("==============");
        tt.postOrder("ABDEGCF", "DBGEACF");

    }
}
