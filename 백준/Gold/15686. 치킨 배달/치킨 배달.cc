#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define X first
#define Y second

int n,m;
bool visit[13];
int board[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int answer = INT_MAX;

int dist(){
    int total = 0;
    for(int i = 0; i < house.size(); i++){
        int hx = house[i].X;
        int hy = house[i].Y;
        int min_dist = INT_MAX;

        for(int j = 0; j < chicken.size(); j++){
            if(!visit[j]) continue;
            int cx = chicken[j].X;
            int cy = chicken[j].Y;
            int dist = abs(hx - cx) + abs(hy - cy);
            min_dist = min(min_dist, dist);
        }
        total += min_dist;
    }
    return total;
}

void dfs(int idx, int count){
    if(count == m){
        int d = dist();
        answer = min(answer, d);
        return;
    }
    for(int i = idx; i < chicken.size(); i++){
        visit[i] = true;
        dfs(i+1, count +1);
        visit[i] = false;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) house.push_back({i,j});
            else if(board[i][j] == 2) chicken.push_back({i,j});
        }
    }

    dfs(0,0);
    cout << answer;
}
