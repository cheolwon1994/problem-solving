import java.util.*;
import java.io.*;
import java.lang.*;

//1. (0,c-1)부터 시작한다
//1-1. 현재 값이 target보다 작다면, 왼쪽과 위는 전부 이 값보다 작은 값이다. 오른쪽 또는 아래로 간다. 하지만 현재 위치가 가장 우측이므로 아래로 간다.
//1-2. 현재 값이 target보다 크다면, 오른쪽과 아래는 전부 이 값보다 크다.  왼쪽 또는 위로 가야하지만, 위가 없으므로 왼쪽으로 간다.
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int r = matrix.length;
        int c = matrix[0].length;

        int x = c-1;
        int y = 0;
        while(x>=0 && y<r) {
            int num = matrix[y][x];
            if(num == target){
                return true;
            }
            else if(num < target) {
                y++;
            }
            else {
                x--;
            }
        }
        return false;
    }
}