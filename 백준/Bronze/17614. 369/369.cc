#include <iostream>
#include <string>
using namespace std;
int n,ans;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        string s = to_string(i);
        for(auto c : s) {
            if(c=='3' || c=='6'||c=='9') ans++;
        }
    }
    cout << ans;
}