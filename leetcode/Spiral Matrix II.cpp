class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector< vector<int>> arr(n, vector<int>(n,0));
        int cnt = 1;
        int left = 0, right = n-1;
        int top = 0, down = n-1;

        while(true){
            //go right
            for(int i=left;i<=right;i++) arr[top][i] = cnt++;
            if(++top > down) break;

            //go down
            for(int i=top;i<=down;i++) arr[i][right] = cnt++;
            if(--right < left) break;

            //go left
            for(int i=right;i>=left;i--) arr[down][i] = cnt++;
            if(--down < top) break;

            //go up
            for(int i=down;i>=top;i--) arr[i][left] = cnt++;
            if(++left > right) break;
        }

        return arr;
    }
};
