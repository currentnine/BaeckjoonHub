#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = (1<<16) -1;
int station, cost[16][16], num, cache[MAX], least_num;

int turnStation(int turned_num, int state){
    if(turned_num >= least_num) return 0;

    int& ret = cache[state];
    if(ret != -1) return ret;

    ret = MAX;
    int min_cost = 51;
    for(int j = 0; j < num; j++){
        if(~state & 1<<j){
            for(int i = 0; i < num; i++){
                if(state & 1 << i) min_cost = min(min_cost, cost[i][j]);
            }
            ret = min(ret, turnStation(turned_num+1, state|(1<<j)) + min_cost);
            min_cost = 51;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string st;
    int station_state = 0, turned_on = 0;
    cin >> num;
    for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++) cin >> cost[i][j];

    
    cin >> st >> least_num;
    for(int i = 0; i < num; i++){
        if(st[i] == 'Y'){
            station_state |= (1 << i);
            turned_on++;
        }
    }
    if(station_state == 0){
        if(least_num==0) cout << "0";
        else cout << "-1";
        return 0;
    }
    memset(cache, -1, sizeof(cache));
    cout << turnStation(turned_on, station_state);

}