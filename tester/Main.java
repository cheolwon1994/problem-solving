import java.util.*;
import java.io.*;
import java.lang.*;

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    Stack<ListNode> stack;

    public void saveReverse(ListNode node) {
        if (node == null) return;
        stack.push(node);       //next는 사용하지 않는다. 추후에 사용
        saveReverse(node.next);
    }


    public void reorderList(ListNode head) {
        if (head == null) return;
        stack = new Stack<>();
        saveReverse(head);
        int len = stack.size();

        ListNode root = head;
        int cnt = 1;

        // node가 홀수개 -> 끝 or reverse + head쪽
        // node가 짝수개 -> reverse 더하고 끝
        while(head!=null && cnt<len) {
            //reverse 더하기
            ListNode n = stack.pop();
            n.next = head.next;
            head.next = n;
            head = head.next;
            cnt++;
            if(cnt==len) {
                head.next = null;
                break;
            }

            //head쪽 더하기
            head = head.next;
            cnt++;
            if(cnt==len) {
                head.next = null;
                break;
            }
        }
        head = root;
    }
}


public class Main {
    public static void main(String[] args) {
        Solution T = new Solution();
        ListNode n = new ListNode(1);
        ListNode head = n;
        n.next = new ListNode(2);
        n = n.next;
        n.next = new ListNode(3);
        n = n.next;
        n.next = new ListNode(4);
        n = n.next;
        n.next = new ListNode(5);


        T.reorderList(head);
        for (ListNode current = head; current != null; current = current.next) {
            System.out.print(current.val);
            if (current.next != null) System.out.print(" ");
        }
        System.out.println();

    }
}
