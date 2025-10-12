#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p(1'000'001, -1);
int t;

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool Union(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(p[v] < p[u]) swap(u,v);
    if(p[v] == p[u]) p[u]--;
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << "Scenario " << tc << ":\n";
        int n,k;
        cin >> n >> k;
        fill(p.begin() + 1, p.begin() + n + 1, -1);
        while(k--){
            int a , b;
            cin >> a >> b;
            Union(a,b);
        }
        int m;
        cin >> m;
        while(m--){
            int u,v;
            cin >> u >> v;
            cout << (find(u) == find(v)) << "\n";
        }
        cout << "\n";
    }
}