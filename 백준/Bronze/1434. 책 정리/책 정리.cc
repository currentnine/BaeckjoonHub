#include <iostream>
using namespace std;

int shelf[1001]; // 책장 용량
int books[1001]; // 책 크기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m; // 책장의 칸 수와 책의 수

    int remainingSpace = 0; // 남는 책장 공간
    for (int i = 0; i < n; i++) {
        cin >> shelf[i]; // 책장 용량 입력
        remainingSpace += shelf[i]; // 책장의 총 용량
    }

    for (int i = 0; i < m; i++) {
        cin >> books[i]; // 책 크기 입력
    }

    int j = 0; // 현재 책장 인덱스
    for (int i = 0; i < m; i++) {
        while (j < n) {
            if (shelf[j] >= books[i]) { // 책이 현재 책장에 들어갈 수 있으면
                shelf[j] -= books[i]; // 책장 용량 감소
                remainingSpace -= books[i]; // 남는 공간 감소
                break;
            } else {
                j++; // 다음 책장으로 이동
            }
        }
    }

    cout << remainingSpace << '\n'; // 최종 남는 공간 출력
    return 0;
}