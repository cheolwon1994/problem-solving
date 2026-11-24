/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class Codec {
    Queue<String> q;

    //root,l,r
    public String preOrder(TreeNode root) {
        if(root == null) return "#";
        String s = String.valueOf(root.val)+",";
        s = s+preOrder(root.left)+",";
        s = s+preOrder(root.right)+",";
        return s;
    }

    public TreeNode decodePreOrder() {
        if(q.isEmpty()) return null;
        String s = q.poll();
        if(s.equals("#")) return null;
        TreeNode n = new TreeNode(Integer.parseInt(s));

        n.left = decodePreOrder();
        n.right = decodePreOrder();
        return n;
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        String s = preOrder(root);
        return s;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        q = new LinkedList<>();
        String[] ss = data.split(",");
        for(String s: ss){
            if(s.equals("")) continue;
            q.offer(s);
        }
        return decodePreOrder();
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));