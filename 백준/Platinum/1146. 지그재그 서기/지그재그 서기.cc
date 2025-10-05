#include <iostream>
#include <cstring>

using namespace std;

int n, arr[101][101];

int zigzag(int n, int k){
    if(!k){
        if(!n) return 1;
        else return 0;
    }
    int &ret = arr[n][k];
    if(ret != -1) return ret;

    return ret = (zigzag(n,k -1) + zigzag(n-1, n -k)) % 1'000'000;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(arr, -1, sizeof(arr));
    arr[0][0] = 1;
    cin >> n;

    if(n == 1){
        cout << 1; return 0;
    }
    cout << zigzag(n,n) * 2 % 1'000'000;
}