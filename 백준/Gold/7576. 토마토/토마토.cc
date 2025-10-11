#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;

int n,m, arr[1005][1005];
int answer =  0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int, int>> q;

void bfs(){
    while(!q.empty()){
        int cx = q.front().X;
        int cy = q.front().Y; q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(ny >= 0 && nx >= 0 && nx < n && ny < m && arr[nx][ny] == 0){
                arr[nx][ny] = arr[cx][cy] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                q.push(make_pair(i,j));
            }
        }
    }

    bfs();

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                cout << -1; return 0;
            }
            else {
                answer = max(arr[i][j], answer);
            }
        }
    }
    cout << answer-1;
}