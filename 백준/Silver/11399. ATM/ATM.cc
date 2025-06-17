#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, p;
vector <int> v;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 0 ; i < n; i++) { 
        cin >> p;
        v.push_back(p);
    }

    int answer = 0;
    sort(v.begin(), v.end());

    for(int  i = 0; i < n; i++){
        answer += v[i] * (n-i);
    }
    cout << answer;
}