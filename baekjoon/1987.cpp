#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
char arr[20][20];
bool visit[20][20];
bool alpha[26];
int row, col, answer;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void dfs(int y, int x, int cnt) {
    answer = max(answer, cnt);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < col && ny < row && !visit[ny][nx]) {
            char c = arr[ny][nx];
            if (!alpha[c - 'A']) {
                alpha[c - 'A'] = true;
                visit[ny][nx] = true;
                dfs(ny, nx, cnt + 1);
                visit[ny][nx] = false;
                alpha[c - 'A'] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    answer = 1;
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
            visit[i][j] = false;
        }
    for (int i = 0; i < 26; i++)
        alpha[i] = false;

    visit[0][0] = true;
    alpha[arr[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << answer;
    return 0;
}