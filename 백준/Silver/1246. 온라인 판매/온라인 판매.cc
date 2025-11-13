#include <iostream>
#include <algorithm>

using namespace std;

int n,m,idx, arr[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int max = 0;

    for(int i = 0; i < m; i++) cin >> arr[i];

    sort(arr, arr+m, greater<int>());

    for(int i = 0 ; i < m ; i++){
        if(i < n){
            if(arr[i] * (i + 1) > max){
                max = arr[i] * (i+1);
                idx = i;
            }
        }
        else break;
    }

    cout << arr[idx] << " " << max;
}