#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;

int n, m, h, arr[105][105][105];
int answer =  0;
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

queue<pair<pair<int, int>, int>> q;

void bfs(){
    while(!q.empty()){
        int cx = q.front().X.X;
        int cy = q.front().X.Y; 
        int cz = q.front().Y;
        q.pop();
        for(int i = 0; i < 6; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nz = cz + dz[i];
            if(ny >= 0 && nx >= 0 && nz >= 0 && nx < n && ny < m && nz < h && arr[nx][ny][nz] == 0){
                arr[nx][ny][nz] = arr[cx][cy][cz] + 1;
                q.push(make_pair(make_pair(nx,ny),nz));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;
    for(int k = 0; k < h;  k++){
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
            cin >> arr[i][j][k];
            if(arr[i][j][k] == 1){
                q.push(make_pair(make_pair(i,j),k));
                }
            }
        }
    }


    bfs();

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < h; k++){
            if(arr[i][j][k] == 0){
                cout << -1; return 0;
            }
            else {
                answer = max(arr[i][j][k], answer);
            }
        }
    }
    }
    cout << answer-1;
}