#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n,w,l;
int n2, arr[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> l;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int time = 0, total = 0;
    queue<int>q;

    for(int i = 0 ; i< n; i++){
        while(1){
            if(q.size() == w){
                total -= q.front();
                q.pop();
            }
            if(total + arr[i] <= l) break;
            q.push(0);
            time++;
        }
        q.push(arr[i]);
        total += arr[i];
        time++;
    }
    cout << time +w;

}