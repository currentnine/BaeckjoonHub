#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, answer;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> v(n);
    vector<int> dp_left(n), dp_right(n);

    dp_right[dp_right.size()-1] = 1;
    for(int i =0; i<n; i++){
        cin >> v[i];
        for(int j = 0; j < i; j++){
            if(v[i] > v[j]) dp_left[i] = max(dp_left[i],dp_left[j] );
        }
        dp_left[i]++;
    }

    for(int i =v.size()-2; i>=0; i--){
        for(int j = v.size() -1; j > i; j--){
            if(v[i] > v[j]) dp_right[i] = max(dp_right[i],dp_right[j] );
        }
        dp_right[i]++;
    }
    for(int i = 0; i < n; i++) answer = max(answer, dp_left[i] + dp_right[i]);
    cout << answer-1;
}