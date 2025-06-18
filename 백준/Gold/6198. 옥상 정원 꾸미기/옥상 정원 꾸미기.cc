#include <iostream>
#include <stack>

using namespace std;

int n;
stack <int> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long answer = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        int h;
        cin >> h;
        if(s.empty()) { 
            s.push(h);
            continue;
        }
        while(!s.empty() && s.top() <= h) s.pop();
        answer += s.size();
        s.push(h);
    }

    cout << answer;


}