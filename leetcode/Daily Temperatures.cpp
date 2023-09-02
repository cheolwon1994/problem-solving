class Solution {
public:
    struct info{
        int idx,val;
    };
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> answer(len,0);
        stack<info> s;

        for(int i=0;i<len;i++){
            int num = temperatures[i];
            if(s.empty()) s.push({i,num});
            else{
                while(!s.empty() && s.top().val < num){
                    int sidx = s.top().idx;
                    answer[sidx] = i-sidx;
                    s.pop();
                }
                s.push({i,num});
            }
        }
        return answer;
    }
};
