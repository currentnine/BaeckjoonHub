#include <iostream>

using namespace std;

typedef long long ll;

int n,k;
int arr[10'005];

bool solve(ll x){
    ll cur = 0;
    for(int i = 0; i < k; i++) cur+= arr[i] / x;
    return cur>=n;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for (int i = 0; i< k; i++) cin>> arr[i];

    ll answer = 1;
    ll en = 0x7fffffff;
    while(answer < en){
        ll mid = (answer + en + 1) / 2;
        if(solve(mid)) answer = mid;
        else en = mid-1;
    }
    cout << answer;


}