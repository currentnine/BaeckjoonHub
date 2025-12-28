#include <iostream>

using namespace std;

int x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> x;
    if(x == 1 || x%3 == 1) cout << "U";
    else if (x == 2 || x%3 == 2) cout << "O";
    else cout << "S";
}