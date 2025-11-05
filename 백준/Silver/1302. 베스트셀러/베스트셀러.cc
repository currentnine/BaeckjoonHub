#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> book;
    int len;
    cin >> len;

    for (int i = 0; i < len; i++) {
        string str;
        cin >> str;
        book[str]++; // 책의 판매량 카운트
    }

    string res;
    int maxCnt = 0;

    for (auto &cur : book) {
        if (cur.second > maxCnt) {  // 판매량이 더 많은 경우 갱신
            maxCnt = cur.second;
            res = cur.first;
        }
    }

    cout << res;
}
