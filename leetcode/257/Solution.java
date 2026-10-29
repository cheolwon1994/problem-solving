

import java.util.*;
import java.io.*;
import java.lang.*;

public static class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public int printPath(TreeNode root) {
        int num = 0;
        if(root == null){
            System.out.println();
            return -101;
        }

        num = root.val;
        System.out.print(num+" ");
        // s = String.format("%d",root.val);

        if(root.left != null) {
            printPath(root.left);
            // if(child ==0) return num;
            // else return String.format("%d->%s",root.val, printPath(root->left));
        }

        if(root.right != null) {
            printPath(root.right);
            // if(child.equals("")) return s;
            // else return String.format("%d->%s",root.val, printPath(root->right));
        }
        return 0;
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> li = new ArrayList<>();

        return li;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        TreeNode root = new TreeNode(
                1,
                new TreeNode(
                        2,
                        null,
                        new TreeNode(5)
                ),
                new TreeNode(3)
        );
        List<String> result = s.binaryTreePaths(root);
        System.out.println(result);
    }
}