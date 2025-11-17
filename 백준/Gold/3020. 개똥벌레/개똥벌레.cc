#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> down, up;
int n, h, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h;
    int cnt = 0;
    int minVal = 500000;

    // 아래에서 자라는 석순(down), 위에서 자라는 종유석(up)
    for (int i = 0; i < n / 2; i++) {
        cin >> a >> b;
        down.push_back(a);
        up.push_back(b);
    }

    sort(down.begin(), down.end());
    sort(up.begin(), up.end());

    for (int height = 1; height <= h; height++) {

        // 현재 높이(height)에서 부딪히는 석순 개수
        // (길이가 height 이상인 석순 개수)
        int down_idx = lower_bound(down.begin(), down.end(), height) - down.begin();

        // 현재 높이(height)에서 부딪히는 종유석 개수
        // (길이가 h - height + 1 이상인 종유석 개수)
        int up_idx = lower_bound(up.begin(), up.end(), h - height + 1) - up.begin();

        // 부딪히는 총 장애물 개수 = 전체 N - 살아남는 장애물 수
        int cur = n - down_idx - up_idx;

        // 최소값 갱신 + 경우의 수 카운트
        if (cur < minVal) {
            minVal = cur;
            cnt = 1;
        } else if (cur == minVal) {
            cnt++;
        }
    }

    cout << minVal << " " << cnt;
}
