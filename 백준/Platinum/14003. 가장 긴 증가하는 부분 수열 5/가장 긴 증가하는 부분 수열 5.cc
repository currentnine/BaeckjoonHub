#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1'000'001];
int dp[1'000'001];        // arr[i]가 들어간 LIS 길이 위치
int prev_idx[1'000'001];  // arr[i]의 LIS 상 이전 원소 인덱스

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> v;         // LIS 저장용
    vector<int> idx_list;  // v의 각 원소에 해당하는 인덱스

    v.push_back(arr[1]);
    idx_list.push_back(1);
    dp[1] = 0;
    prev_idx[1] = -1;

    for (int i = 2; i <= n; i++) {
        if (arr[i] > v.back()) {
            prev_idx[i] = idx_list.back();
            v.push_back(arr[i]);
            idx_list.push_back(i);
            dp[i] = v.size() - 1;
        } else {
            int pos = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[pos] = arr[i];
            idx_list[pos] = i;
            dp[i] = pos;
            prev_idx[i] = (pos == 0 ? -1 : idx_list[pos - 1]);
        }
    }

    // LIS 길이
    int LTS = v.size() - 1;

    // LIS 마지막 원소 인덱스 찾기
    int last_idx = -1;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == LTS) {
            last_idx = i;
            break;
        }
    }

    // 역추적
    vector<int> answer;
    while (last_idx != -1) {
        answer.push_back(arr[last_idx]);
        last_idx = prev_idx[last_idx];
    }

    reverse(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for (int x : answer) cout << x << " ";
}
