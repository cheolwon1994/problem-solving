class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        char answer = letters[0];

        while(l <= r){
            int mid = l + (r - l) / 2;
            char c = letters[mid];
            if(c > target){
                answer = c;
                r--;
            }
            else l++;
        }

        return answer;
    }
};