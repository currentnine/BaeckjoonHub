#include <iostream>

using namespace std;

int n,s;
int arr[51];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> arr[i];
    cin >> s;

    int st = 0;
    while(st <n && s > 0){
        int maxidx = st;
        for(int i = st; i<=min(n-1, st+s); i++){
            if(arr[maxidx] < arr[i]) maxidx = i;
        }

        for(int i = maxidx; i > st; i--){
            swap(arr[i], arr[i-1]);
            s--;
        }

        st++;
    }

    for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";
}