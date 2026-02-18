#include <iostream>
#include <algorithm>

using namespace std;

vector <pair<int, int >> v;
int n;

bool cmp(pair<int, int> a, pair<int,int> b){
    if(a.first == 0) return 0;
    else if (b.first == 0) return 1;
    else if (a.second == 0 && b.second == 0) return a.first < b.first;
    return a.second * b.first < a.first * b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), cmp);
    int result = 0;
    for(int i = 0; i < v.size(); i++){
        result = result + result * v[i].first + v[i].second;
        result %= 40000;
    }

    cout << result;
}