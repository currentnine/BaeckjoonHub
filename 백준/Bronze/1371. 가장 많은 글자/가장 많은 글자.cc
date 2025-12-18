#include <iostream>
#include <string>
using namespace std;
char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
int check[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
 
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++) {    //알파벳 갯수 탐색
            for (int k = 0; k < 26; k++) {
                if (s[i] == alphabet[k]) check[k]++;
            }
        }
    }
    int maxIndex = 0;
    for (int i = 0; i < 26; i++) {    //알파벳 갯수가 젤 많은게 몇개인지 탐색
        if (check[i] > maxIndex) {
            maxIndex = check[i];
        }
    }
    for (int i = 0; i < 26; i++) {
        if (check[i] == maxIndex) cout << alphabet[i];    //최대 갯수가 중복일수가 있으니 전부출력
    }
}