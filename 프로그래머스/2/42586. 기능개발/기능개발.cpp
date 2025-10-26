#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0; i < progresses.size(); i++){
        int day = 0;
        while(progresses[i] <100){
            day++;
            progresses[i] += speeds[i];
        }
        q.push(day);
    }
    
    while(!q.empty()){
        int day = q.front();
        int p = 1;
        q.pop();
        
        while(!q.empty() && q.front() <= day){
            q.pop();
            p++;
        }
        answer.push_back(p);
    }
    
    return answer;
}