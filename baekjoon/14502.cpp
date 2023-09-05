#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct info {
	int y, x;
};
int row, col, answer;
int arr[8][8];
bool flag[8][8], dup[8][8];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<info> nothing;
queue<info> virus;

int spread() {
	queue<info> q = virus;
	int temp = nothing.size() - 3;	//빈 공간에서 벽 3개 설치
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++) 
			dup[i][j] = flag[i][j];

	while (!q.empty()) {
		info ii = q.front();
		q.pop();
		int cx = ii.x;
		int cy = ii.y;

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && !dup[ny][nx] && arr[ny][nx] == 0) {
				dup[ny][nx] = true;
				q.push({ ny,nx });
				temp--;
			}
		}
	}

	return temp;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		answer = max(spread(), answer);
		return;
	}
	for (int i = idx; i < nothing.size(); i++) {
		int y = nothing[i].y;
		int x = nothing[i].x;
		//벽 설치
		arr[y][x] = 1;
		dfs(i + 1, cnt + 1);
		//벽 해제
		arr[y][x] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	for(int i=0;i<row;i++)
		for (int j = 0; j < col; j++) {
			flag[i][j] = false;
			cin >> arr[i][j];
			if (arr[i][j] == 0) nothing.push_back({ i,j });
			else if (arr[i][j] == 2) {
				virus.push({ i,j });
				flag[i][j] = true;
			}
		}
	answer = 0;
	dfs(0, 0);
	cout << answer;
	return 0;
}