#include <iostream>
#include <cstring>

using namespace std;

int n, board[15][15];
int dp[1<<15][15][10];

int resell(int visited, int artist, int price){
    int & ret = dp[visited][artist][price];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 1; i < n; i++){
        if(!(visited & (1 << i)) && board[artist][i] >= price){ // 방문없이 더 비싸게
                int next_visited = visited | (1 << i);
                ret = max(ret, resell(next_visited, i, board[artist][i]) + 1);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < n; j++) board[i][j] = temp[j] - '0';
    }

    memset(dp, -1, sizeof(dp));
    resell(1,0,0);
    cout << dp[1][0][0] + 1;
}