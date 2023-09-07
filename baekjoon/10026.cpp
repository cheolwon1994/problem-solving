#include <iostream>
#include <queue>
#include <string>
using namespace std;
char arr[100][100][2];
bool flag[100][100][2]={false,};
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int num;

int countIsland(int cnt){
    int islandCnt = 0;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(!flag[i][j][cnt]){
                islandCnt++;
                queue<pair<int,int> > q;
                q.push(make_pair(i,j));
                flag[i][j][cnt] = true;

                while(!q.empty()){
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();

                    for(int k=0;k<4;k++){
                        int nx = cx+dx[k];
                        int ny = cy+dy[k];
                        if(nx>=0 && ny>=0 && nx<num && ny<num && arr[ny][nx][cnt]==arr[i][j][cnt] && !flag[ny][nx][cnt]){
                            flag[ny][nx][cnt] = true;
                            q.push(make_pair(ny,nx));
                        }
                    }
                }
            }
        }
    }

    return islandCnt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>str;
        for(int j=0;j<num;j++){
            char c = str[j];
            arr[i][j][0] = c;
            //적록 색명
            if(c=='R' || c=='G') arr[i][j][1] = 'R';
            else arr[i][j][1] = c;
        }
    }
    cout<<countIsland(0)<<" "<<countIsland(1);
    return 0;
}