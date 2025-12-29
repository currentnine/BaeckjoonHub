#include <iostream>
#include <string>
using namespace std;

string s, k, tmp;

int main(){
    cin >> s >> k;

    // 문자열 s에서 알파벳 문자만 추출하여 tmp에 저장
    for(int i = 0; i < s.length(); i++)
        if(isalpha(s[i])) tmp.push_back(s[i]);

    // 알파벳만 남긴 문자열에 k가 부분 문자열로 존재하는지 확인
    if(tmp.find(k) == string::npos) cout << "0";
    else cout << "1";
}
