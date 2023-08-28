class Solution {
public:
    int row, col;

    void rotate(vector<vector<int>>& arr, int cnt){
        vector<int> backup;
        //backup leftside
        for(int i=row-1-cnt;i>=cnt;i--)
            backup.push_back(arr[i][cnt]);
        //down to left
        for(int i=cnt;i<col-cnt;i++) arr[i][cnt]= arr[row-1-cnt][i];
        //right to down
        for(int i=row-1-cnt;i>=cnt;i--) arr[row-1-cnt][col-1-i]= arr[i][col-1-cnt];
        //up to right
        for(int i=col-1-cnt;i>=cnt;i--) arr[i][row-1-cnt]= arr[cnt][i];
        //backup to up
        for(int i=0;i<backup.size();i++)
            arr[cnt][cnt+i] = backup[i];
    }

    void rotate(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        int cnt = 0;

        while(cnt+1 <= row/2){
            rotate(matrix, cnt);
            cnt++;
        }
    }
};