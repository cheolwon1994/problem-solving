class Solution {
public:
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        int** dup = new int*[row];
        for(int i=0;i<row;i++)
            dup[i] = new int[col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int alive = 0;
                for(int k=0;k<8;k++){
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if(nx>=0 && ny>=0 && nx<col && ny<row && board[ny][nx] == 1)
                        alive++;
                }
                //alive cell
                if(board[i][j]==1){
                    if(2 <= alive && alive <= 3) dup[i][j] = 1;
                    else dup[i][j] = 0;
                }
                //dead cell
                else{
                    if(alive == 3) dup[i][j] = 1;
                    else dup[i][j] = 0;
                }
            }
        }

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                board[i][j] = dup[i][j];
    }
};
