#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,m, t, num;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0 ; i < t; i++){
        int cnt = 0;
        queue<pair<int,int>>q;
        priority_queue<int> pq;
        cin >> n >> m;
        for(int j = 0; j < n; j++){
            cin >> num;
            q.push({j,num});
            pq.push(num);
        }
        while(!pq.empty()){
            int x = q.front().first;
            int y = q.front().second; q.pop();

            if(pq.top() == y){
                cnt++;
                pq.pop();
                if(x == m){
                    cout << cnt << "\n";
                    break;
                }
                
            }
            else q.push({x,y});
        }
    }
}