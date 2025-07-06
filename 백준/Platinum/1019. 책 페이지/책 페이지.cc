#include <iostream>

using namespace std;

int n, count[10] = {}, add_num = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i = 1; n != 0; i*=10){
        int curr = n%10;
        n /=10;

        count[0] -= i;
        for(int j = 0; j<curr; j++) count[j] += (n+1) * i;
        count[curr] += n*i + 1 + add_num;
        for(int j = curr + 1; j<=9; j++) count[j] += n * i;
        add_num += curr * i;
    }

    for(int i = 0; i<=9; i++) cout << count[i] << " ";

}