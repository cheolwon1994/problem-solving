#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
    int y, x;
};
int num, answer;
int arr[100][100];
bool snakeBody[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
deque<info> snake;
queue<pair<int, char>> changeInfo;

void snake_move(int y, int x, int dir, int cnt) {
    //뱀 방향 전환
    if (!changeInfo.empty()) {
        if (changeInfo.front().first == cnt) {
            char c = changeInfo.front().second;
            if (c == 'L') dir = (dir + 3) % 4;
            else dir = (dir + 1) % 4;
            changeInfo.pop();
        }
    }
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    //뱀 사망
    if (nx < 0 || ny < 0 || nx >= num || ny >= num || snakeBody[ny][nx]) {
        answer = cnt + 1;
        return;
    }

    //이동한칸에 사과 있는지 확인
    bool haveApple = false;
    if (arr[ny][nx] == 1) {
        arr[ny][nx] = 0;
        haveApple = true;
    }

    snake.push_front({ ny,nx });
    snakeBody[ny][nx] = true;

    //사과 없다면
    if (!haveApple) {
        snakeBody[snake.back().y][snake.back().x] = false;
        snake.pop_back();
    }
    snake_move(ny, nx, dir, cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int apple, y, x, change, sec;
    char c;
    answer = 0;
    cin >> num >> apple;
    for (int i = 0; i < apple; i++) {
        cin >> y >> x;
        arr[y - 1][x - 1] = 1;
    }
    cin >> change;
    for (int i = 0; i < change; i++) {
        cin >> sec >> c;
        changeInfo.push({ sec,c });
    }
    //뱀 생성
    snake.push_back({ 0, 0 });
    snakeBody[0][0] = true;

    snake_move(0, 0, 1, 0);
    cout << answer;
    return 0;
}