#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p(10005, -1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int v, e;
tuple<int, int, int> edge[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for(int i = 0; i< e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    sort(edge, edge + e);
    int count = 0;
    int answer = 0;
    for(int i = 0 ; i <e; i++){
        int a, b, cost;
        tie(cost, a, b ) = edge[i];
        if(!is_diff_group(a,b)) continue;
        answer += cost;
        count++;
        if(count == v - 1) break;
    }
    cout << answer;

}
