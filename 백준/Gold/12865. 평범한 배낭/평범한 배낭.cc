#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
int w[100'005],v[1'005];
int d[101][100'005];

// 점화식 : DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);

int main(){

    cin>>n>>k;
    for(int i = 1;i<=n;i++) cin>>w[i]>>v[i];
    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=k;j++){
            if(j-w[i]>=0) d[i][j] = max(d[i-1][j], d[i-1][j-w[i]]+v[i]);
            else d[i][j] = d[i-1][j];
        }
    }
    cout<<d[n][k];

}