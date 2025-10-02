#include <iostream>
#include <vector>

using namespace std;

int answer,n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> building(n);
    vector<int> count(n, 0);
    for(int i = 0; i < n; i++) cin >> building[i];
    for(int i = 0; i < n; i++){
        double max_level = -9999999999;
        for(int j = i+1; j < n; j++){
            //기울기
            double level = (double)(building[j] - building[i]) / (j - i);
            if(level > max_level){
                count[i]++;
                count[j]++;
                max_level = level;
            }
        }
    }
    for(auto cnt : count) answer = max(answer, cnt);
    cout << answer;
}