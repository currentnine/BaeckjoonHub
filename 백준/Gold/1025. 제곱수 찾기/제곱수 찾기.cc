#include <iostream>
#include <cmath>
#include <algorithm> // max 함수 사용을 위해 추가

using namespace std;

int n, m;
int chart[10][10];
long long answer = -1; 

bool isSquare(long long num) { // 인자 타입 변경
    if (num < 0) return false;
    long long root = round(sqrt(num));
    return root * root == num;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            chart[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = -n; x < n; x++) {
                for (int y = -m; y < m; y++) {
                    // 1자리 숫자도 처리하기 위해 x와 y가 둘 다 0인 경우도 포함

                    int r = i, c = j;
                    long long num = 0;
                    
                    while (0 <= r && r < n && 0 <= c && c < m) {
                        num = num * 10 + chart[r][c];
                        
                        if (isSquare(num)) {
                            answer = max(answer, num);
                        }
                        
                        // 방향 이동
                        r += x;
                        c += y;
                        if (!x && !y) break; // 무한루프 방지
                    }
                }
            }
        }
    }

    cout << answer;
    return 0;
}