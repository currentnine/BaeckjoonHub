#include <iostream>
using namespace std;

int arr[6]; // 나무 조각 배열 (인덱스 0~4 사용)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 받기
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    // 정렬 과정
    while (true) {
        bool swapped = false; // 교환이 발생했는지 확인하기 위한 플래그

        for (int i = 0; i < 4; i++) {
            if (arr[i] > arr[i + 1]) {
                // 인접한 두 수를 교환
                swap(arr[i], arr[i + 1]);
                swapped = true;

                // 현재 배열 상태 출력
                for (int t = 0; t < 5; t++) {
                    cout << arr[t] << ' ';
                }
                cout << '\n';
            }
        }

        // 더 이상 교환이 발생하지 않으면 종료
        if (!swapped) {
            break;
        }
    }

    return 0;
}