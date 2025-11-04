#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100005
using namespace std;

int n;
int arr[MAX];
bool visited[MAX];
vector<int> v[MAX];

void dfs(int k){
    visited[k] = true;
    for(int i = 0; i < v[k].size();i++){
        int next = v[k][i];
        if(!visited[next]){
            arr[next] = k;
            dfs(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i<n-1;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    for(int i = 2; i <=n; i++) cout << arr[i] <<"\n";

}