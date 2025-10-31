#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin >> n ;
    int a = 100, b =100;
    for(int i = 0 ; i < n ; i++){
        int x,y;
        cin >> x >> y;
        if(x > y) a -= x;
        else if(x<y) b -= y;
    }
    cout << b << '\n' << a;
}