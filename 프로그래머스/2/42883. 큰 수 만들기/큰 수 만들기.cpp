#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start_idx = 0;
    for(int i = 0 ; i < number.size() - k; i++){
        char mx = number[start_idx];
        int max_idx = start_idx;
        for(int j = start_idx; j <= k + i; j++){
        if(mx < number[j]){
            mx = number[j];
            max_idx = j;
        }
    }
    start_idx = max_idx + 1;
    answer += mx;
    }
    
    return answer;
}