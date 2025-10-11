#include <iostream>
#include <cmath>

using namespace std;

int num, n, r, c, N;

void div(int n, int r, int c){

    if (n== 1) return;

    int half = n / 2;
    int area = half * half;

    // 1
    if(r < half && c < half){
        div(half , r , c);
    }
    // 2
    else if(r < half && c >= half){
        num += area;
        div(half , r , c - half);
    }
    // 3
    else if(r >= half && c < half){
        num += 2 * area;
        div(half , r - half , c);
    }

    // 4
    else{
        num += 3 * area;
        div(half , r - half , c - half);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;

    N = 1 << n;
    div(N, r, c);
    cout << num;

}