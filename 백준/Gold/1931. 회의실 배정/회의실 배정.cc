#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair <int, int> room[100'005];

int main(){

    cin>>n;
    for(int i =0;i<n;i++) cin>>room[i].second>>room[i].first;

    sort(room, room+n);
    int answer = 0;
    int a = 0;
    for(int i =0; i<n;i++){
        if(a>room[i].second) continue;
        answer++;
        a = room[i].first;
    }
    cout << answer;

}