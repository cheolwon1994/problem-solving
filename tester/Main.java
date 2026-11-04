import java.util.*;
import java.io.*;
import java.util.function.Supplier;

// ===== 여기에 LeetCode 풀이를 붙여넣으세요 =====
class Solution {
    public String longestPalindrome(String s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int k = 0; k < 2; k++) {
                int l = i, r = i + k;
                while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
                    l--;
                    r++;
                }
                if (r - l - 1 > end - start) {
                    start = l + 1;
                    end = r;
                }
            }
        }
        return s.substring(start, end);
    }
}

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.longestPalindrome("aaaa"));
    }
}
