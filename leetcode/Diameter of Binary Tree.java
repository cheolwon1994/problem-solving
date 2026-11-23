/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.*;

class Solution {
    int answer;

    public int search(TreeNode node) {
        if(node == null) return 0;

        //left
        int l = search(node.left);
        //right
        int r = search(node.right);

        answer = Math.max(l+r, answer);

        //본인 node 포함위해 +1
        return Math.max(l, r)+1;
    }

    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null) return 0;
        answer = 0;
        search(root);

        return answer;
    }
}