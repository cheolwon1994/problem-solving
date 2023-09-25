class Solution {
public:
    bool visited[16];

    bool canMake(int idx, vector<int>& matchsticks, int sum, int quarter, int group){
        //made 4 group
        if(group == 4) return true;
        //made sum to quarter
        if(sum == quarter) return canMake(0, matchsticks, 0, quarter, group + 1);

        for(int i=idx;i<matchsticks.size();i++){
            if(!visited[i] && sum + matchsticks[i] <= quarter){
                visited[i] = true;
                if(canMake(i+1, matchsticks, sum + matchsticks[i], quarter, group))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int i=0;i<matchsticks.size();i++){
            sum += matchsticks[i];
            visited[i] = false;
        }
        if(sum%4 != 0) return false;

        sort(matchsticks.rbegin(), matchsticks.rend());

        return canMake(0, matchsticks, 0, sum/4, 0);
    }
};
