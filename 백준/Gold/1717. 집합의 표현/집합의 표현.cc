#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p(1'000'001, -1);
int n,m;

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool Union(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(p[v] < p[u]) swap(u,v);
    if(p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    while(m--){
        int q, a, b;
        cin >> q >> a >> b;
        if(q == 0) Union(a,b);
        else{
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n"; 
        }
    }
}