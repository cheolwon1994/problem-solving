import java.util.*;
import java.io.*;

class Solution {
    public boolean isPalindrom(int l, int r, String s, boolean skipped) {
        if(l>=r) {
            return true;
        }

        if(s.charAt(l) == s.charAt(r)) {
            return isPalindrom(l+1, r-1, s, skipped);
        }
        if(skipped) {
            return false;
        }
        //skip 가능
        return isPalindrom(l+1, r, s, true) || isPalindrom(l, r-1, s, true);
    }

    public boolean validPalindrome(String s) {
        return isPalindrom(0, s.length()-1, s, false);
    }
}