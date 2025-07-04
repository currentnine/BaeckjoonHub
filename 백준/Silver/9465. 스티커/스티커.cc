#include <iostream>
#include <algorithm>

using namespace std;
int arr[2][100'005];
int t,n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while(t--){
        cin >> n;
        for(int i = 0; i <2; i++)
            for(int j = 1; j <= n; j++) cin >> arr[i][j];

        for(int j = 2; j <= n; j++){
            arr[0][j] += max(arr[1][j-1], arr[1][j-2]);
            arr[1][j] += max(arr[0][j-1], arr[0][j-2]);
        }

        cout << max(arr[0][n], arr[1][n]) << "\n";
    }


}