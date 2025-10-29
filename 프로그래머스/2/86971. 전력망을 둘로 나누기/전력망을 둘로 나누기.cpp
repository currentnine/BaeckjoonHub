#include <string>
#include <vector>
#include <cmath>
#include <queue>
#define MAX 105
using namespace std;

int cnt;
vector<int> info[MAX];

void bfs(int v1, int v2){
    queue<int> q;
    vector<bool> visited(MAX);
    q.push(v1);
    visited[v1] = true;
    visited[v2] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 0 ; i < info[cur].size(); i++){
            int state = info[cur][i];
            if(visited[state]) continue;
            cnt++;
            q.push(state);
            visited[state] = true;
        }
    }
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX;
    for(auto w: wires){
        info[w[0]].push_back(w[1]);
        info[w[1]].push_back(w[0]);
    }
    
    for(auto w: wires){
        cnt = 1;
        int v1 = w[0];
        int v2 = w[1];
        bfs(v1,v2);
        answer = min(answer, abs(2 * cnt - n));
    }
    return answer;
}