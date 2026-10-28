/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode li = new ListNode(0);
        ListNode temp = li;
        int a1, a2, acc=0;
        while(l1!=null || l2!=null || acc !=0) {
            //a1
            if(l1==null) a1 = 0;
            else {
                a1 = l1.val;
                l1 = l1.next;
            }

            //a2
            if(l2==null) a2 = 0;
            else {
                a2 = l2.val;
                l2 = l2.next;
            }

            int sum = a1+a2+acc;
            if(sum>=10) {
                sum -= 10;
                acc = 1;
            } else {
                acc = 0;
            }

            //Node 추가
            temp.next = new ListNode(sum);

            //다음으로 넘김
            temp = temp.next;
        }

        return li.next;
    }
}