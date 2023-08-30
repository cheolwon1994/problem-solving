class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            if(i<3){
                for(int k=0;k<i;k++)
                    temp.push_back(1);
            }
            else{
                temp.push_back(1);
                for(int k=0;k<i-2;k++)
                    temp.push_back(answer[i-2][k]+answer[i-2][k+1]);
                temp.push_back(1);
            }
            answer.push_back(temp);
        }
        return answer;
    }
};