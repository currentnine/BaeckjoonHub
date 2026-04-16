#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> f >> n;

    ll sum = 0;
    
    if(f==1) sum = n*8;
    else if(f==2) 
    {
        if(n%2==0) sum = n*4+1;
        else sum = n*4+3;
    
    }
    else if(f==3) sum = n*4+2;
    else if(f==4)
    {
        if(n%2==0) sum = n*4+3;
        else sum = n*4+1;
    }
    else sum = n*8+4;

    cout << sum;

    return 0;
}
