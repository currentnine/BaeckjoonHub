#include <iostream>
using namespace std;

int main() {
    int cnt = 0;
    int sum = 0;
    int n;
    string s;
    cin >> n >> s;
 
 
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'O') {
            sum += i + 1;
            sum += cnt;
            cnt++;
        }
        else {
            cnt = 0;
        }
    }
    
    cout << sum << "\n";
 
 
    return 0;
}
