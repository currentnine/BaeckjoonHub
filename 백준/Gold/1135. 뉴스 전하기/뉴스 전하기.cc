#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
vector <int> v[55];

int dfs(int node){
    if (v[node].empty()) return 1;

    vector<int> child;
    for(int i = 0; i < v[node].size(); i++) child.push_back(dfs(v[node][i]) + 1);

    sort(child.begin(), child.end(), greater<int>());

    int result = 0;
    for(int i = 0 ; i < child.size(); i++) result = max(result, child[i] + i);

    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int>v1(n);
    for(int i = 0; i < n ; i++){
        cin >> v1[i];
        if(i == 0) continue;
        v[v1[i]].push_back(i);
    }

    cout << dfs(0) -1 ;
}