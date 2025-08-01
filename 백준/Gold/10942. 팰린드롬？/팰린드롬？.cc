#include <iostream>
using namespace std;

int N,M;
int arr[2010];
int dp[2010][2010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    cin >> M;
    for(int i=1; i<=N; i++){
        dp[i][i]=1; //한자리 수는 팰린드롬
        if(i!=1 && arr[i-1] == arr[i]) dp[i-1][i]=1; //두자리수가 같은 경우 팰린드롬
    }
    
    for(int i=2; i<=N-1; i++){
        for(int j=1; i+j<=N; j++){
            if(arr[j]==arr[i+j] && dp[j+1][i+j-1]==1)
                dp[j][i+j]=1;
        }
    }
    
    while(M--){
        int s,e; 
        cin >> s >> e;
        if(dp[s][e] == 1) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    
    return 0;
}