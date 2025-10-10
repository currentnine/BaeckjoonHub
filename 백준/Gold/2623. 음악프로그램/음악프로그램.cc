#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int arr[1005];
int n,m;
vector<int> graph[1005];
vector<int> result;

void topological_sort(){
    queue<int> q;
    for(int i = 1; i <=n; i++) if(arr[i] == 0) q.push(i);
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        result.push_back(cur);

        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            arr[next]--;
            if(arr[next] == 0) q.push(next);
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    while(m--){
        int num;
        cin >> num;
        if(num == 0) continue;
        else if(num == 1){
            int a; cin >> a;
            continue;
        }
        int singer, subsinger;
        cin >> singer;
        for(int i = 1; i < num; i++){
            cin >> subsinger;
            graph[singer].push_back(subsinger);
            arr[subsinger]++;
            singer = subsinger;
        }
    }

    topological_sort();

    if(result.size() != n) cout << "0";
    else {
        for(auto answer : result) cout << answer << "\n";
    } 
}