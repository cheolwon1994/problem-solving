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

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode merged = new ListNode(0);
        ListNode root = merged;

        while(list1!=null || list2 !=null) {
            if(list1== null) {
                merged.next = list2;
                break;
            } else if(list2== null) {
                merged.next = list1;
                break;
            }
            int fv = list1.val;
            int sv = list2.val;
            if(fv<=sv) {
                merged.next = list1;
                merged = merged.next;
                list1 = list1.next;
            } else {
                merged.next = list2;
                merged = merged.next;
                list2 = list2.next;
            }
        }
        return root.next;
    }
}