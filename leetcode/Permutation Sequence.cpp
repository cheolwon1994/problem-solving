class Solution {
public:
    bool used[10]={false,};

    string getPermutation(int n, int k) {
        string answer = "";
        int mul = 1;
        for(int i=1;i<n;i++){
            mul*=i;
        }
        k--;
        
        for(int i=n-1;i>=0;i--){
            int q = k/mul;
            int temp = 0;
            for(int k=1;k<10;k++){
                if(!used[k]) temp++;
                if(temp==q+1){
                    answer+=to_string(k);
                    used[k] = true;
                    break;
                }
            }
            k -= q*mul;
            if(i>0) mul/=i;
        }

        return answer;
    }
};
