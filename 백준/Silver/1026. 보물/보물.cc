#include <iostream>
#include <algorithm>

using namespace std;

int n, a[105], b[105];

int main(){

    cin>>n;
    for(int i = 0;i<n;i++) cin >> a[i];
    for(int i = 0;i<n;i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);

    int answer = 0;
    for(int i = 0;i<n;i++) answer += a[i] * b[n-1-i];
    cout << answer;
    
}