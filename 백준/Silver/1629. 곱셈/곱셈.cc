#include <iostream>
#include <algorithm>

using namespace std;

long long answer(long long a, long long b, long long c){
    if(b==0) return 1;
    long long temp;
    temp = answer(a,b/2,c);
    temp = temp * temp %c;
    if(b%2 == 0) return temp; // 짝수일때
    else return temp*a%c;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a,b,c;

    cin >> a >> b >> c;

    cout << answer(a,b,c);

}