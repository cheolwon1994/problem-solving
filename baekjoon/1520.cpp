#include <iostream>
#include <algorithm>
using namespace std;

int arr[500][500];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int row, col;

int dfs(int y, int x) {
    if (y == row - 1 && x == col - 1) return 1;
    int res = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] < arr[y][x])
            res += dfs(ny, nx);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];
    cout << dfs(0, 0);
    return 0;
}