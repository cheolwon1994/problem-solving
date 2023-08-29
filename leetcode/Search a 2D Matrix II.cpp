class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size()-1;

        while(i<matrix.size() && j >=0){
            int val = matrix[i][j];
            if(val==target) return true;
            else if(val < target) i++;
            else j--;
        }
        return false;
    }
};