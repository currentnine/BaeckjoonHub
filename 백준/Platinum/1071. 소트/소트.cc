#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        if(v[i]+1 == v[i+1]){
            int end =  i+2;
            if(end != n){
                while(v[end] == v[i+1]) end++;
            }
            if(end == n){
                int start = i - 1;
                if(start >= 0){
                    while(v[start] == v[i]) start--;
                }
                v[start+1]++;
                v[i+1]--;
            }
            else{
                int temp = v[end];
                v[end] = v[i+1];
                v[i+1] = temp;
            }
        }
    }
    for(auto a : v) cout << a << " ";
}