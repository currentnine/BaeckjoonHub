#include <iostream>
using namespace std;

int main() {
    int N,M,x,y;
    int set = 1000, single = 1000;
    cin >> N >> M;

    while(M--) {
        cin >> x >> y;
        set = min(set, x);
        single = min(single, y);
    }
	
    cout << min((N/6+1)*set, min(N/6*set + N%6*single, N*single)) << '\n';
}