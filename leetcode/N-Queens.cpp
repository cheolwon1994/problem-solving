class Solution {
public:
    struct info{
        int y,x;
    };
    vector<info> queens;
    vector<vector<string>> answer;
    bool col[9];
    string temp;

    void backtracking(int row, int n){
        if(row==n){
            vector<string> v;
            for(int i=0;i<n;i++){
                string s = temp;
                int x = queens[i].x;
                s[x] = 'Q';
                v.push_back(s);
            }
            answer.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(col[i]) continue;
            //check diagonal
            if(row==0){
                queens.push_back({row,i});
                col[i] = true;
                backtracking(row+1,n);
                col[i] = false;
                queens.pop_back();
            }
            else{
                bool avail = true;
                for(int k=0;k<queens.size();k++){
                    int qx = queens[k].x;
                    int qy = queens[k].y;
                    if(row+i == qx+qy || row-i == qy-qx){
                        avail = false;
                        break;
                    }
                }

                if(avail){
                    queens.push_back({row,i});
                    col[i] = true;
                    backtracking(row+1,n);
                    col[i] = false;
                    queens.pop_back();
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        //init
        temp = "";
        for(int i=0;i<n;i++){
            temp +=".";
            col[i] = false;
        }
        backtracking(0, n);
        return answer;
    }
};
