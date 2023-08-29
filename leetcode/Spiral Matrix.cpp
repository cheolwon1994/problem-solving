class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int minRow = 0;
        int maxRow = arr.size()-1;
        int minCol = 0;
        int maxCol = arr[0].size()-1;
        vector<int> answer;

        while(true){
            //go right
            for (int j = minCol; j <= maxCol; j++) answer.push_back(arr[minRow][j]);
            minRow++;
            if (minRow > maxRow) break;
            //go down
            for (int i = minRow; i <= maxRow; i++) answer.push_back(arr[i][maxCol]);
            maxCol--;
            if (minCol > maxCol) break;
            //go left
            for (int j = maxCol; j >= minCol; j--) answer.push_back(arr[maxRow][j]);
            maxRow--;
            if (minRow > maxRow) break;
            //go up
            for (int i = maxRow; i >= minRow; i--) answer.push_back(arr[i][minCol]);
            minCol++;
            if (minCol > maxCol) break;
        }

        return answer;
    }
};