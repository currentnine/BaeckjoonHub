#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[9];
int first[9];
int visited[9];

void dfs(int num, int k){
    if(k == m){
        for ( int  i = 0; i< m; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    else{
        for( int i = 1; i <= n; i++){
            if(!visited[i]){
                visited[i] = 1;
                arr[k] = first[i-1];
                dfs(i+1, k+1);
                visited[i] = 0;

            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i<n; i++) cin >> first[i];
    sort(first, first + n);
    dfs(1,0);
}