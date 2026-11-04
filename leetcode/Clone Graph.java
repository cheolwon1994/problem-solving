import java.util.*;
import java.io.*;
import java.lang.*;

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/


class Solution {
    HashMap<Node, Node> cloneMap;

    public Node clone(Node node) {
        if(node == null) return null;
        if(cloneMap.containsKey(node)){
            return cloneMap.get(node);
        }
        Node c = new Node(node.val);
        cloneMap.put(node, c);
        for(Node n: node.neighbors) {
            c.neighbors.add(clone(n));
        }
        return c;
    }

    public Node cloneGraph(Node node) {
        cloneMap = new HashMap<>();

        return clone(node);
    }
}