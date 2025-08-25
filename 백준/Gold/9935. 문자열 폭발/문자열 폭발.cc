#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
string s1, s2, result;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++){
        result += s1[i];
        if(result.size() >= s2.size()){
            if(result.substr(result.size() - s2.size(), s2.size()) == s2){
                result.erase(result.end() - s2.size(), result.end());
            }
        }
    }
    if(result.size()) cout << result;
    else cout << "FRULA";

}