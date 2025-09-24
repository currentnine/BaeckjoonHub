#include <iostream>

using namespace std;

pair<int,int> go(int n, int k){
    if(n == 2){
        if(k == 1) return {1,1};
        if(k == 2) return {1,2};
        if(k == 3) return {2,2};
        return {2,1};
    }
    int half = n/2;
    int area = half*half;
    if(k <= area){
        auto [r,c] = go(half, k);
        return {c, r}; // 좌상단 회전
    }
    else if(k <= 2*area){
        auto [r,c] = go(half, k-area);
        return {r, c+half}; // 우상단
    }
    else if(k <= 3*area){
        auto [r,c] = go(half, k-2*area);
        return {r+half, c+half}; // 우하단
    }
    else{
        auto [r,c] = go(half, k-3*area);
        return {2*half-c+1, half-r+1}; // 좌하단 회전대칭
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K; cin >> N >> K;
    auto [x,y] = go(N,K);
    cout << x << " " << y << "\n";
}