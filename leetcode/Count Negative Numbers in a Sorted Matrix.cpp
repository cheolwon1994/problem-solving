class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int up = 0, down = grid.size() - 1;
        int left = 0, right = grid[0].size() - 1;
        int answer = 0;

        while(left <= right && up <= down){
            //check row's last number
            for(int i=right;i>=left;i--){
                if(grid[up][i] < 0){
                    right--;
                    answer += (down - up + 1);
                }
                else up++;
            }

            //check col's last number
            for(int i=down;i>=up;i--){
                if(grid[i][left] < 0){
                    down--;
                    answer += (right - left + 1);
                }
                else left++;
            }
        }

        return answer;
    }
};