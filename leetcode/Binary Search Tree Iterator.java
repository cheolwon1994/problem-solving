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
//inorder -> left, root, right
class BSTIterator {
    Queue<Integer> q;

    public void inOrder(TreeNode node) {
        if(node == null) return;
        //left
        if(node.left!=null) {
            inOrder(node.left);
        }
        //root
        q.offer(node.val);
        //right
        if(node.right!=null) {
            inOrder(node.right);
        }
    }

    public BSTIterator(TreeNode root) {
        q = new ArrayDeque<>();
        inOrder(root);
    }

    public int next() {
        return q.poll();
    }

    public boolean hasNext() {
        return q.isEmpty() ? false : true;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */