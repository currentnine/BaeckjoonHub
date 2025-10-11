#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,d,k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k;

    vector<int> v(n);

    for(int i = 0 ; i < n; i++) cin >> v[i];

    int m = k / v[0];

    for(int i = 1; i < n; i++) m = min(m, k / v[i]);

    cout << (d + m -1) / m -1;

}
