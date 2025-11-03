#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int a[1'000'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int max = 0;
    for(int i = 0 ; i < n; i++) cin >> a[i];
    sort(a, a+n);

    long long start = 0, end = a[n-1];
    while(start <= end){
        long long sum = 0;
        long long cut = (start + end) / 2;

        for(int i = 0 ; i < n ; i++){
            if(a[i] - cut > 0) sum+= a[i] - cut;
        }

        if(sum >= m){
            max = cut;
            start = cut+1;
        }
        else end = cut -1;
    }

    cout << max;


}