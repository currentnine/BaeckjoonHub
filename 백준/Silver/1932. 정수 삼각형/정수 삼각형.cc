#include <iostream>
#include <algorithm>
using namespace std;

int t[505][505] = {0};
int dp[505][505] = {0};

int n;

int main(){
    cin >> n;
    int answer = 0;
    for(int i = 1; i <=n;i++)
        for(int j = 1 ; j <= i; j++) cin >> t[i][j];

    dp[1][1] = t[1][1];
    for(int i = 2; i<=n; i++){
        for(int j = 1; j <=i; j++) dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + t[i][j];
    }

    for(int i = 1; i <=n; i++){
        if(answer < dp[n][i]) answer = dp[n][i];
    }

    cout << answer;
}