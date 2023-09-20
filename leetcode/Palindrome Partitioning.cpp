class Solution {
public:
    vector<vector<string>> answer;
    void makePalindrome(int idx, vector<string>& temp, string s){
        if(idx==s.size()){
            answer.push_back(temp);
            return;
        }
        int maxLen = s.size()-idx;
        for(int i=1;i<=maxLen;i++){
            int left = idx;
            int right = idx+i-1;
            bool avail = true;
            while(left<=right){
                if(s[left]==s[right]){
                    left++;
                    right--;
                }
                else{
                    avail = false;
                    break;
                }
            }
            if(avail){
                string ss = s.substr(idx,i);
                temp.push_back(ss);
                makePalindrome(idx+i,temp,s);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        makePalindrome(0, temp, s);

        return answer;
    }
};