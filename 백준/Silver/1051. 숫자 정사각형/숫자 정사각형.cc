#include <iostream>
#include <string>
using namespace std;

int n,m,answer;
int arr[50][50];
string input;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        cin >> input;
        for(int j = 0; j<m;j++) arr[i][j] = input[j] - '0';
    }
    int min_len = min(n,m);
    int a,b,c,d;
    for(int len = 1; len <= min_len; len++){
        for(int i = 0; i<=n-len;i++){
            for(int j = 0; j<=m-len;j++){
                a = arr[i][j];
                b = arr[i + len -1][j];
                c = arr[i][j+len -1];
                d = arr[i + len -1][j+len-1];
                if(a == b && b == c && c== d) answer = len;
            }
        }
    }
    cout << answer * answer;
}