#include <iostream>

using namespace std;

string num;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        bool palindrome = true;
        cin >> num;
        if(num == "0") break;
        for(int i = 0; i <= num.length()/2; i++){
            if(num[i] != num[num.length()-1-i]){
                palindrome = false;
                break;
            }
        }
        if(palindrome) cout << "yes\n";
        else cout << "no\n";
    
}
}