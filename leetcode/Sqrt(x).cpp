class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;

        int left = 1, right = x, answer = 1;
        while(left <= right){
            int mid = left + (right-left)/2;
            long long mul = (long long)mid * mid;
            if(mul == (long long)x) return mid;
            else if(mul > (long long)x) right = mid-1;
            else left = mid + 1;
        }

        return right;
    }
};
