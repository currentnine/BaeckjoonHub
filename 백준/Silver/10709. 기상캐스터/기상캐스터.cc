#include <iostream>
#include <algorithm>

using namespace std;

int h,w;
char c[105][105];
int answer[105][105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    for(int i = 0; i < h; i++)
        for(int j = 0 ; j < w; j++) cin >> c[i][j];

    
    for(int i = 0; i < h; i++){
        int tmp = -1;
        for(int j = 0; j < w; j++){
            if(c[i][j] == 'c'){
                answer[i][j] = 0;
                tmp = 0;
            }
            else{
                if(tmp != -1) tmp++;
                answer[i][j] = tmp;
            }
            }
        }

    for(int i = 0; i < h; i++){
        for(int j = 0 ; j < w; j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}
