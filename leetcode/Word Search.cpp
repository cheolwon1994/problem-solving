class Solution {
public:
    bool answer;
    int row,col;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};

    void backtracking(int y, int x, int nextIdx, vector<vector<char>> &board,string word){
        if(answer) return;
        if(nextIdx == word.size()){
            answer = true;
            return;
        }
        char c = board[y][x];
        board[y][x] = ' ';
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<col && ny<row && board[ny][nx]==word[nextIdx]){
                backtracking(ny,nx,nextIdx+1,board,word);
            }
        }
        board[y][x] = c;
    }

    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        answer = false;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                char c = board[i][j];
                if(c==word[0]){
                    backtracking(i,j,1,board,word);
                    if(answer) return answer;
                }
            }
        }

        return false;
    }
};