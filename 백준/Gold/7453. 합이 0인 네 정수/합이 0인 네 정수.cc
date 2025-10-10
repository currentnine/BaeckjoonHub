#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, arr[4005][4];
vector<int> a,b;

long long answer = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 4; j++) cin >> arr[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            a.push_back(arr[i][0] + arr[j][1]);
            b.push_back(arr[i][2] + arr[j][3]);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i < a.size(); i++){
        int l_boud = lower_bound(b.begin(), b.end(), -a[i]) - b.begin();
        int u_boud = upper_bound(b.begin(), b.end(), -a[i]) - b.begin();

        answer += (u_boud - l_boud);
    }

    cout << answer;
}