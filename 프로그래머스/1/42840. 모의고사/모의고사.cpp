#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer, ans(3,0);
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> v3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0; i < answers.size(); i++){
        if(v1[i % v1.size()] == answers[i]) ans[0]++;
        if(v2[i % v2.size()] == answers[i]) ans[1]++;
        if(v3[i % v3.size()] == answers[i]) ans[2]++;
    }
    int max_val = *max_element(ans.begin(), ans.end());
    for(int i = 0; i <3; i++){
        if(max_val == ans[i]) answer.push_back(i+1);
    }
    return answer;
}