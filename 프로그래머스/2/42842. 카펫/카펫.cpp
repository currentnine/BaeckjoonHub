#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = brown + yellow;
    for(int h = 3; h <= sqrt(area); h++){
        if(area % h == 0){
            int w = area / h;
            if(((w + h) * 2 -4 ) == brown){
                answer.push_back(w);
                answer.push_back(h);
            }
        }
    }
    return answer;
}