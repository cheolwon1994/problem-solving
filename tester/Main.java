import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    List<String> li;
    Character[] op = new Character[]{'*', '-', '+'};
    HashSet<String> set;

    public int calculate(String s) {
        int sum = 0;
        //* 연산부터 시작
        int idx = 0;
        String[] numbers = s.split("[-+*]");
        String[] ops = s.split("[0-9]");

//        for(String ss: numbers) {
//            System.out.print(ss+" ");
//        }
//        System.out.println();
//
//        for(String ss: ops) {
//            System.out.print(ss+" ");
//        }
//        System.out.println();

        Deque<Integer> dq = new ArrayDeque<>();
        dq.add(Integer.parseInt(numbers[0]));
        int nidx = 1;
        int oidx = 1;
        while(nidx < numbers.length && oidx < ops.length) {
            if(!ops[oidx].equals("*")) {
                dq.addLast(Integer.parseInt(numbers[nidx]));
            } else {
                ops[oidx] = "";
                int a = dq.pollLast();
                int b = Integer.parseInt(numbers[nidx]);
                a *= b;
                dq.addLast(a);
            }
            nidx++;
            oidx++;
        }

        //+, - 연산
        sum = dq.pollFirst();
        for(int i=1;i<ops.length;i++) {
            if(!ops[i].equals("")){
                if(ops[i].equals("+")) {
                    sum += dq.pollFirst();
                } else {
                    sum -= dq.pollFirst();
                }
            }
        }

        return sum;
    }

    public void dfs(int idx, StringBuilder sb, String num, int target) {
        if(idx == num.length()-1) {
            String s = sb.append(num.charAt(idx)).toString();
            if(set.contains(s)) return;
            set.add(s);

            int val = calculate(s);
            if(val == target) {
                li.add(sb.toString());
            }
            return;
        }
        //연산자 추가
        for(int i=0;i<op.length;i++){
            dfs(idx+1, sb.append(new char[]{op[i],num.charAt(idx)}), num, target);
        }
        //연산자 없이 진행
        dfs(idx+1, sb.append(num.charAt(idx)), num, target);
    }

    public List<String> addOperators(String num, int target) {
        li = new ArrayList<>();
        set = new HashSet<>();
        StringBuilder sb = new StringBuilder().append(num.charAt(0));
        dfs(1, sb, num, target);
        return li;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution T = new Solution();
//        ListNode f = new ListNode(1);
//        ListNode head = f;
//        f.next = new ListNode(2);
//        f = f.next;
//        f.next = new ListNode(4);
//
//        ListNode s = new ListNode(1);
//        ListNode head2 = s;
//        s.next = new ListNode(3);
//        s = s.next;
//        s.next = new ListNode(4);
//
//
//        ListNode n = T.mergeTwoLists(head, head2);

        T.addOperators("123", 6);
//        while(n!=null) {
//            System.out.println(n.val+" ");
//            n = n.next;
//        }
        System.out.println();

    }
}
