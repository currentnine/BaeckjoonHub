#include <iostream>
#include <algorithm>

using namespace std;

int h, w, k;
string arr[50];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;

    for (int i = 0; i < h; i++) cin >> arr[i];

    cin >> k;

    int answer = -1;

    for (int i = 0; i < h; i++) {
        int cnt = 0;

        // 1) i번째 행에서 '0' 개수 세기
        for (int j = 0; j < w; j++) {
            if (arr[i][j] == '0') cnt++;
        }

        int sum = 0;

        // 2) cnt(켜져야 할 0의 개수)와 k(스위치 횟수)의 조건 체크
        if (cnt <= k && (cnt % 2) == (k % 2)) {
            // 3) 같은 패턴을 가진 행 개수 세기
            for (int x = 0; x < h; x++) {
                if (arr[i] == arr[x]) sum++;
            }
        }

        answer = max(answer, sum);
    }

    cout << answer;
}
    