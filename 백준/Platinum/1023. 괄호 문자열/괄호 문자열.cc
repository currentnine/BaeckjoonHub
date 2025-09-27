#include <iostream>
#include <vector>
using namespace std;

long long DP[52][130]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 초기값 설정
    for(int i = 1; i <= 120; i++){
        DP[0][i] = 1;   // 길이가 0일 때 올바른 경우는 하나
        DP[1][i] = 2;   // 길이가 1일 때 ( / ) 선택 가능
    }
    DP[0][60] = 0;      // 중앙 위치에서 길이 0일 때는 올바른 문자열 없음
    DP[1][61] = 1;      // 균형이 61일 때는 ")" 하나만 가능

    // DP 테이블 채우기
    for(int i = 2; i <= 50; i++){
        for(int j = 1; j < 60; j++) DP[i][j] = 1ll << i; // 불가능한 상태 → 큰 값 넣기
        for(int j = 60; j <= 120; j++) 
            DP[i][j] = DP[i -1][j - 1] + DP[i -1][j + 1]; // '(' 또는 ')' 선택해서 누적
    }

    long long n,k, count = 0;
    bool isCorrect = 0;
    cin >> n >> k; // n: 괄호 길이, k: k번째 괄호 문자열

    // 만들 수 없는 경우 체크
    if(n % 2 == 0 && k >= DP[n][60]){
        cout << -1;
        return 0;
    }

    int answer = 60; // 균형 시작 지점 (중앙값)
    for(int i = 1; i <= n; i++){
        long long val = DP[n-i][answer+1]; // '('을 선택했을 때 가능한 경우의 수

        if(isCorrect) val = 1ll << (n-i); // 이미 균형이 무너졌다면 그냥 전체 경우 수
        if(count + val > k) {             // k가 속한 구간이라면 '(' 출력
            answer++;
            cout << "(";
        }
        else{                             // 아니라면 ')' 출력
            count += val;
            answer--;
            cout << ")";
        }
        if(answer < 60) isCorrect = 1;    // 균형 깨짐 표시
    }
}
