#define MAXI 50000
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
struct info{
    int y,x;
};

bool arr[100][100];
int flag[100][100];
int row,col;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int main(){
    cin >>row>>col;
    string s;
    for(int i=0;i<row;i++){
        cin>>s;
        for(int j=0;j<col;j++){
            arr[i][j] = s[j] == '1' ? true : false;
            flag[i][j] = MAXI;
        }
    }
    queue<info> q;
    flag[0][0] = 1;
    q.push({0,0});

    while(!q.empty()){
        info ii = q.front();
        q.pop();
        int cx = ii.x;
        int cy = ii.y;
        for(int k=0;k<4;k++){
            int nx = cx+dx[k];
            int ny = cy+dy[k];
            if(nx>=0 && ny>=0 && nx<col && ny<row && arr[ny][nx]==1 && flag[ny][nx] > flag[cy][cx] + 1){
                flag[ny][nx] = flag[cy][cx] + 1;
                q.push({ny,nx});
            }
        }
    }
    cout<<flag[row-1][col-1];
}