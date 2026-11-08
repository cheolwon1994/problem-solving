import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    //1. M 찾기 (1000M ~ 3000MMM, 900CM 가능)
    //2. D 찾기 (400CD ~ 800DCCC)
    //3. C 찾기 (90XC ~ 300CCC)
    // ...

    int answer;

    //1000, 100, 10, ...
    public String tens(String s, char c, int num) {
        if(s.charAt(0) == c) {
            int idx = 0;
            while(idx < s.length()) {
                if(s.charAt(idx) != c) {
                    break;
                }
                else idx++;
            }
            idx--;
            //num~3*num
            answer += (idx+1)*num;
            s = s.substring(idx+1, s.length());
        }
        //0.9 * num 확인
        if(s.length()>1 && s.charAt(1) == c){
            answer += (0.9*num);
            s = s.substring(2, s.length());
        }
        return s;
    }

    public String fives(String s, char fiveC, char tenC, int num) {
        ////DC, DCC, DCCC
        if(s.charAt(0) == fiveC) {
            int idx = 1;
            while(idx < s.length()) {
                if(s.charAt(idx) == tenC) idx++;
                else break;
            }
            idx--;
            System.out.println("idx: "+idx);
            answer += (num + idx*num/5);
            s = s.substring(idx+1, s.length());
        }
        if (s.length() > 1 && s.charAt(1) == fiveC) {        //CD
            answer += (0.8*num);
            s = s.substring(2, s.length());
        }
        return s;
    }

    public int romanToInt(String s) {
        //init
        answer = 0;

        //1, 1000M ~ 3000MMM, 900CM
        s = tens(s, 'M', 1000);
        if(s.length() == 0) return answer;
        //2, 400CD ~ 800DCCC
        s = fives(s, 'D', 'C', 500);
        if(s.length() == 0) return answer;
        //3. C ~ CCC, XC
        s = tens(s, 'C', 100);
        if(s.length() == 0) return answer;
        //4. L
        s = fives(s, 'L', 'X', 50);
        if(s.length() == 0) return answer;
        //5. X
        s = tens(s, 'X', 10);
        if(s.length() == 0) return answer;
        //6. V
        s = fives(s, 'V', 'I', 5);
        if(s.length() == 0) return answer;
        //7. I
        s = tens(s, 'I', 1);
        if(s.length() == 0) return answer;
        return answer;
    }
}