#define MAXI 987654321
#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
using namespace std;
struct info {
    int y, x, crushed;
};
int arr[1000][1000];
int visit[1000][1000][2];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int row, col, answer = MAXI;
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < col; j++) {
            arr[i][j] = str[j] - '0';
            for (int k = 0; k < 2; k++)
                visit[i][j][k] = MAXI;
        }
    }
    queue<info> q;
    q.push({ 0,0,0 });
    visit[0][0][0] = 1;
    while (!q.empty()) {
        info ii = q.front();
        q.pop();
        int cx = ii.x;
        int cy = ii.y;
        int cc = ii.crushed;
        if (cy == row - 1 && cx == col - 1) {
            answer = min(answer, visit[cy][cx][cc]);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
                if (arr[ny][nx] == 1) {
                    if (cc == 1) continue;
                    if (visit[ny][nx][1] > visit[cy][cx][0] + 1) {
                        visit[ny][nx][1] = visit[cy][cx][0] + 1;
                        q.push({ ny,nx,1 });
                    }
                }
                else {
                    if (visit[ny][nx][cc] > visit[cy][cx][cc] + 1) {
                        visit[ny][nx][cc] = visit[cy][cx][cc] + 1;
                        q.push({ ny,nx,cc });
                    }
                }
            }
        }
    }
    if (answer == MAXI) answer = -1;
    cout << answer;
    return 0;
}