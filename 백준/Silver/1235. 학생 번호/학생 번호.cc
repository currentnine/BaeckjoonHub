#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, answer;
string input;
vector <string> stduent_num;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int length = 1;
    for(int i = 0; i < n ; i++){
        cin >> input;
        reverse(input.begin(), input.end());
        stduent_num.push_back(input);
    }

    while(1){
        set <string> s;
        for(int i = 0 ; i < n ; i++) s.insert(stduent_num[i].substr(0, length));

        if(s.size() == n) break;
        else length++;
    }

    cout << length;

}