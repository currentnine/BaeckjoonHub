#include<iostream>
 
using namespace std;
 
int c, n;
pair<int, int> arr[20];
int cus[1111];
int answer = 987654321;
 
int main()
{
    cin >> c >> n;
 
    fill(cus+1, cus + 1111, 987654321);
 
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            cus[j + arr[i].second] = min(cus[j + arr[i].second], cus[j] + arr[i].first);
 
            if (j + arr[i].second >= c) {
                answer = min(answer, cus[j + arr[i].second]);
            }
        }
    }
 
    cout << answer;
}
