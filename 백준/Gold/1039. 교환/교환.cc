#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n,k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;
    string s;
    cin >> s >> k;
    queue<string>q;
    q.push(s);
    int step = 0;
    while(!q.empty() && step < k){
        set <string> visit; // 한단계씩 체크
        int size = q.size();
        for(int  ts = 0; ts < size; ts++){
            string cur = q.front(); q.pop();
            for(int i = 0; i < cur.size() -1; i++){
                for(int j = i+1; j < cur.size();j++){
                    swap(cur[i], cur[j]);
                    if(cur[0] == '0'){
                        swap(cur[i], cur[j]);
                        continue;
                    }
                    if(visit.find(cur) == visit.end()){ // 없는경우
                        if(step == (k-1) && answer < stoi(cur)) answer = stoi(cur);
                        visit.insert(cur); q.push(cur);
                    }
                    swap(cur[i], cur[j]); // 원상복구
                }
            }
        }
        step++;
    }
    if(answer == 0) cout << "-1";
    else cout << answer;
}