#include <iostream>

using namespace std;

bool check[100'000'05] = {0,};

long long Min, Max, temp, count;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> Min >> Max;
    for(long long i = 2; i*i<=Max; i++){
        temp = Min / (i*i) ; 
        if(Min%(i*i)) temp++;
        while(temp*i*i <= Max) {
            check[temp*i*i - Min] = 1;
            temp++;
        }
    }
    for(long long i = 0 ; i<= Max-Min;i++) if(!check[i]) count++;
    cout << count;
}