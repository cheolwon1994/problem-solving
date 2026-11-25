import java.util.*;
import java.io.*;

class Solution {

    public String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0")) return "0";

        Queue<String> q = new LinkedList<>();
        int tens = 0;       //뒤에 0을 붙이는 자리수

        for(int i=num2.length()-1;i>=0;i--) {
            int m = num2.charAt(i)-'0';
            if(m==0) {
                tens++;
                continue;
            }
            int acc = 0;
            StringBuilder sb = new StringBuilder();

            for (int j = num1.length() - 1; j >= 0; j--) {
                int num = m * (num1.charAt(j) - '0') + acc;
                acc = num / 10;
                sb.append(num % 10);
            }

            if (acc > 0) {
                sb.append(acc);
            }

            String sum = sb.reverse().toString();
            //뒤에 0 붙이기
            for(int k=0;k<tens;k++){
                sum = sum+"0";
            }
            tens++;
            q.offer(sum);
        }

        String answer = q.poll();
        while(!q.isEmpty()) {
            String next = q.poll();

            //add
            int lidx = answer.length()-1;
            int ridx = next.length()-1;
            int acc = 0;
            String temp = "";

            while(lidx>=0 || ridx>=0) {
                if(lidx<0) {
                    //next 다 더하기
                    while(ridx>=0) {
                        int sum = (next.charAt(ridx)-'0')+acc;
                        acc = sum/10;
                        sum%=10;
                        temp = sum+temp;
                        ridx--;
                    }
                    break;
                }
                if(ridx<0) {
                    //answer 다 더하기
                    while(lidx>=0) {
                        int sum = (answer.charAt(lidx)-'0')+acc;
                        acc = sum/10;
                        sum%=10;
                        temp = sum+temp;
                        lidx--;
                    }
                    break;
                }
                int sum = (answer.charAt(lidx)-'0')+(next.charAt(ridx)-'0')+acc;
                acc = sum/10;
                sum%=10;
                temp = sum+temp;
                lidx--;
                ridx--;
            }
            if(acc>0) {
                temp = String.valueOf(acc)+temp;
            }
            answer = temp;
        }

        return answer;
    }
}