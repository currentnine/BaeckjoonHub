#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> a(n + 1), dp(n + 1, 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[i] > a[j]) dp[i] = max(dp[i], dp[j]+1);
        }
    }

    cout << *max_element(dp.begin(), dp.end());

}