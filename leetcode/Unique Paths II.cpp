class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<int> v(col,0);
        v[0] = 1;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int gv = obstacleGrid[i][j];
                if(gv == 1) v[j] = 0;
                else{
                    if(j==0){
                        if(v[j]!=0)
                            v[j] = 1;
                    }
                    else v[j] = v[j] + v[j-1];
                }
            }
        }

        return v[col-1];
    }
};
