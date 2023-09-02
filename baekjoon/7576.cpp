#include <iostream>
#include <queue>
using namespace std;

int arr[1000][1000];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int main(){
    int row,col,zeroTomato=0,days=0;
    cin>>col>>row;
    queue<pair<int,int> > q;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
            if(arr[i][j] == 0) zeroTomato++;
            else if(arr[i][j] == 1){
                q.push(make_pair(i,j));
            }
        }

    while(zeroTomato>0 && !q.empty()){
        int len = q.size();
        for(int k=0;k<len;k++){
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if(nx>=0 && ny>=0 && nx<col && ny<row && arr[ny][nx]==0){
                    arr[ny][nx] = 1;
                    zeroTomato--;
                    q.push(make_pair(ny,nx));
                }
            }
        }
        days++;
    }
    if(zeroTomato) cout<<-1;
    else cout<<days;
    return 0;
}