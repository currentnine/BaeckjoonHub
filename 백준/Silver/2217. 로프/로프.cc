#include <iostream>
#include <algorithm>
using namespace std;

int n,w[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0;i<n;i++) cin>>w[i];
    sort(w,w+n);

    int answer = 0;
    for(int i = 1;i<=n;i++) {answer = max(answer, w[n-i]*i);}
    cout << answer <<"\n";
}