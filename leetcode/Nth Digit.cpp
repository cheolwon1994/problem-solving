class Solution {
public:
    int findNthDigit(int n) {
        long long l = 1, r = 1000000000;
        long long target = (long long)n;

        while(l <= r){
            long long mid = l + (r - l) / 2;
            long long sum = 0;
            string s = to_string(mid);
            int len = s.size();
            //cal 1~(len-1) length number len
            long long q = 9;
            for(int i=1;i<len;i++){
                sum += (q*i);
                q *= 10;
            }

            //cal len length ~ mid
            long long start = pow(10,len-1);
            sum += (mid - start)*len;

            //digit of mid
            if(sum < target && target <= sum + len){
                return (s[target-sum-1]-'0');
            }
            else if(sum >= target) r = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }
};
