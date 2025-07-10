#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int r, c;
// 알파벳 방문 여부를 체크하는 배열 (A-Z)
bool alpha[26] = {}; 
char graph[21][21];
// 상하좌우 이동을 위한 배열
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int result = 0;

// (y, x) 위치에서 시작하여, 현재까지 'count'개의 칸을 지났음을 의미
void dfs(int y, int x, int count) {
    // 현재까지의 이동 횟수로 최대값 갱신
    result = max(result, count);

    // 4가지 방향(상, 하, 좌, 우)으로 탐색
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        // 1. 다음 위치가 보드 범위를 벗어나는지 체크
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;

        // 다음 위치의 알파벳에 해당하는 인덱스 계산
        int idx = graph[ny][nx] - 'A';
        
        // 2. 이미 방문한 알파벳인지 체크
        if (alpha[idx]) continue;

        // --- 탐색 진행 ---
        alpha[idx] = true; // 알파벳 방문 처리
        dfs(ny, nx, count + 1); // 재귀 호출
        
        // --- 백트래킹 ---
        // 탐색이 끝난 후, 다른 경로에서 이 알파벳을 사용할 수 있도록 방문 기록을 해제
        alpha[idx] = false; 
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
        }
    }

    // 시작점 (0, 0) 처리
    alpha[graph[0][0] - 'A'] = true; // 시작점 알파벳 방문 처리
    dfs(0, 0, 1); // (0, 0)에서 시작, 이동 칸 수 1

    cout << result << '\n';
    return 0;
}