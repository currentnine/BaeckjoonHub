#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int i = 0; i < numbers.size(); i++) v.push_back(to_string(numbers[i]));
    sort(v.begin(), v.end(), compare);
    if(v[1] == "0") return "0";
    for(auto x : v) answer += x;
    return answer;
}