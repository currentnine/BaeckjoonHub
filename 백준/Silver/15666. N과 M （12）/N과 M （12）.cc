#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n,m;
int first[9];
int arr[9];
set<vector<int>> s;

void dfs(int num, int k){
    if(k==m){
        vector<int> v;
        for(int i = 0; i< m; i++) v.push_back(arr[i]);
        s.insert(v);
        v.clear();
    }
    else{
        for(int i = num; i < n; i++){
            arr[k] = first[i];
            dfs(i, k+1);
        }
    }
}

int main(){
    cin >> n >> m; 
    
    for(int i = 0 ; i < n; i++) cin >> first[i];
    sort(first, first + n);
    dfs(0,0);
    for(auto vector:s){
        for(auto vec : vector){
            cout << vec << " ";
        }
        cout << "\n";
        }
}