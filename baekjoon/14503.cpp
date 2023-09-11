#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int row, col, answer;
int arr[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void clean(int y, int x, int dir) {
    //1
    if (arr[y][x] == 0) {
        arr[y][x] = 2;
        answer++;
    }

    int needToClean = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] == 0)
            needToClean += (i + 1);
    }

    //2.
    if (needToClean == 0) {
        int nd = (dir + 2) % 4;
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        //2-1
        if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] != 1) clean(ny, nx, dir);
        //2-2
        else return;
    }
    //3
    else {
        //3-1
        int nd = dir;
        for (int i = 0; i < 4; i++) {
            nd = (nd + 3) % 4;
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            //3-2
            if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] == 0) {
                clean(ny, nx, nd);
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int sy, sx, dir;
    answer = 0;
    cin >> row >> col >> sy >> sx >> dir;
    for (int i = 0; i < row; i++) 
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];
    clean(sy, sx, dir);

    cout << answer;
    return 0;
}