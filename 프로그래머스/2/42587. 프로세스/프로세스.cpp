#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for(int i = 0; i < priorities.size(); i++){
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    int count = 1;
    while(1){
        pair<int, int> p = q.front(); q.pop();
        if(p.second != pq.top()) q.push(p);
        else{
            if(p.first == location){
                answer = count;
                break;
            }
            else{
                count++;
                pq.pop();
            }
        }
    }
    return answer;
}