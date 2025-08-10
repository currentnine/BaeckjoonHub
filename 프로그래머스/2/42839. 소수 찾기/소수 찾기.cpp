#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

bool isprime(int n){
    if(n <2) return false;
    for(int i = 2; i<=sqrt(n); ++i){
        if(n%i==0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int>ans{};
    sort(numbers.begin(), numbers.end());
    do
    {
        string tmp;
        for(int i = 0; i<numbers.size();i++){
            tmp +=numbers[i];
            if(isprime(stoi(tmp))) ans.insert(stoi(tmp));
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    return ans.size();
}