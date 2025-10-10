#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n,t;
bool checked[100'001];
bool visited[100'001];
int cnt;
vector<int> v;

void dfs(int now){
    checked[now] = true;
    int next = v[now];
    
    if(!checked[next]) dfs(next);
    else if(!visited[next]){
        for(int i = next; i != now; i = v[i]) cnt++;
        cnt++;
    }
    visited[now] = true;
    return;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        v.resize(n+1);
        for(int i = 1; i <=n; i++) cin >> v[i];
        for(int i = 1; i <=n; i++){
            if(!checked[i]) dfs(i);
        }
        cout << n - cnt << "\n";
        cnt = 0;
        memset(checked, false, sizeof(checked));
        memset(visited, false, sizeof(visited));
    }
}