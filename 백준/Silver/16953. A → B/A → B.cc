#include <iostream>

using namespace std;

int a,b;

int main(){
    cin >> a >> b;
    int answer = 1;
    while(1){
        if(a == b) break;
        else if (a > b) {
            answer = -1;
            break;
        }

        if(b%2==0) b/=2;
        else if (b % 10 == 1) b = (b-1)/10;
        else{
            answer = -1;
            break;
        }
        answer++;
    }
    cout << answer;
}