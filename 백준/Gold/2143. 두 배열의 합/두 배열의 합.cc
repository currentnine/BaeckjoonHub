#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2e8;
int t;
int n, m;
int a[1000], b[1000];
vector<int> v, w;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> t >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];
    //a로 만들 수 있는 부분합

    for (int i = 0; i < n; i++) {
        int sum = a[i];
        v.push_back(sum);
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            v.push_back(sum);
        }
    }

    //b로 만들 수 있는 부분합
    for (int i = 0; i < m; i++) {
        int sum = b[i];
        w.push_back(sum);
        for (int j = i + 1; j < m; j++) {
            sum += b[j];
            w.push_back(sum);
        }
    }
    
    sort(w.begin(), w.end());

    long long answer = 0;
    for (auto item : v)
    {
        int diff = t - item;
        auto ub = upper_bound(w.begin(), w.end(), diff);
        auto lb = lower_bound(w.begin(), w.end(), diff);
        answer += (ub - lb);
    }
    cout << answer;

    return 0;
}