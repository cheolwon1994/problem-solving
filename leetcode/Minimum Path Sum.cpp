class Solution {
public:
    int row,col;
    int maxi = 987654321;
    int cost[200][200];

 int go(int y, int x, vector<vector<int>>& grid) {
    if (y < 0 || x < 0) return maxi;
    if (cost[y][x] != maxi) return cost[y][x];
    if (y == 0 && x == 0) return cost[y][x] = grid[0][0];
    else if (y == 0) return cost[y][x] = grid[y][x] + go(y, x - 1, grid);
    else if (x == 0) return cost[y][x] = grid[y][x] + go(y - 1, x, grid);
    return cost[y][x] = grid[y][x] + min(go(y - 1, x, grid), go(y, x - 1, grid));
}

    int minPathSum(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                cost[i][j] = maxi;
        go(row-1,col-1,grid);
        return cost[row-1][col-1];
    }
};