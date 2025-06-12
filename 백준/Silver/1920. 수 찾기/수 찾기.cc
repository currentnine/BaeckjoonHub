#include <iostream>
#include <algorithm>

using namespace std;

int a[100'005];
int n;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i = 0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int m;
    cin>>m;
    for(int i = 0; i< m; i++){
        int x;
        cin>>x;
        cout << binary_search(a, a+n, x) << "\n";
    }

}